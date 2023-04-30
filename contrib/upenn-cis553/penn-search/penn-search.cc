/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2010 University of Pennsylvania
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "penn-search.h"

#include "ns3/random-variable-stream.h"
#include "ns3/inet-socket-address.h"
#include "ns3/penn-key-helper.h"
#include <openssl/sha.h>

// #include<iostream>
// #include<set>
// #include<cstdio>
// #include<algorithm>
#include<bits/stdc++.h>

using namespace ns3;


TypeId
PennSearch::GetTypeId()
{
  static TypeId tid = TypeId("PennSearch")
                          .SetParent<PennApplication>()
                          .AddConstructor<PennSearch>()
                          .AddAttribute("AppPort",
                                        "Listening port for Application",
                                        UintegerValue(10000),
                                        MakeUintegerAccessor(&PennSearch::m_appPort),
                                        MakeUintegerChecker<uint16_t>())
                          .AddAttribute("ChordPort",
                                        "Listening port for Application",
                                        UintegerValue(10001),
                                        MakeUintegerAccessor(&PennSearch::m_chordPort),
                                        MakeUintegerChecker<uint16_t>())
                          .AddAttribute("PingTimeout",
                                        "Timeout value for PING_REQ in milliseconds",
                                        TimeValue(MilliSeconds(2000)),
                                        MakeTimeAccessor(&PennSearch::m_pingTimeout),
                                        MakeTimeChecker());
  return tid;
}

PennSearch::PennSearch()
    : m_auditPingsTimer(Timer::CANCEL_ON_DESTROY)
{
  m_chord = NULL;

  Ptr<UniformRandomVariable> m_uniformRandomVariable = CreateObject<UniformRandomVariable>();
  m_currentTransactionId = m_uniformRandomVariable->GetValue(0x00000000, 0xFFFFFFFF);
}


// dstr
/*
I've confirmed that the autograder is expecting the following output format:
AvgHopCount<3, 16, 51>
AvgHopCount<4, 11, 42>

With information as follows:
AvgHopCount<Node#, Lookup Count, Lookup Hop Count>

Some other pointers on this:
Should be printed from the PennSearch destructor.
*/
PennSearch::~PennSearch()
{
  // TBD:  need to sort out the incrementation llogic after all other tests arw correct
    // print out?
  std::cout << "AvgHopCount<" << ReverseLookup(m_local) << ", " << lookupNumber << ", " << hopNumber << ">" << std::endl;
  // SEARCH_LOG("AvgHopCount<" << ReverseLookup(m_local) << ", " << lookupNumber << ", " << hopNumber << ">");


}

void PennSearch::DoDispose()
{
  StopApplication();
  PennApplication::DoDispose();
}

void PennSearch::StartApplication(void)
{
  std::cout << "PennSearch::StartApplication()!!!!!" << std::endl;
  // Create and Configure PennChord
  ObjectFactory factory;

  factory.SetTypeId(PennChord::GetTypeId());
  factory.Set("AppPort", UintegerValue(m_chordPort));
  m_chord = factory.Create<PennChord>();
  m_chord->SetNode(GetNode());
  m_chord->SetNodeAddressMap(m_nodeAddressMap);
  m_chord->SetAddressNodeMap(m_addressNodeMap);
  m_chord->SetModuleName("CHORD");
  std::string nodeId = GetNodeId();
  m_chord->SetNodeId(nodeId);
  m_chord->SetLocalAddress(m_local);

  // Configure Callbacks with Chord
  m_chord->SetPingSuccessCallback(MakeCallback(&PennSearch::HandleChordPingSuccess, this));
  m_chord->SetPingFailureCallback(MakeCallback(&PennSearch::HandleChordPingFailure, this));
  m_chord->SetPingRecvCallback(MakeCallback(&PennSearch::HandleChordPingRecv, this));
  // m2
  m_chord->SetSearchSuccessCallback(MakeCallback(&PennSearch::HandleNodeLookup, this));
  // m2b
  m_chord->SetNodeJoinCallback(MakeCallback(&PennSearch::HandleNodeJoin, this));
  m_chord->SetNodeLeaveCallback(MakeCallback(&PennSearch::HandleNodeLeave, this));


  // Start Chord
  m_chord->SetStartTime(Simulator::Now());
  m_chord->Initialize();

  if (m_socket == 0)
  {
    TypeId tid = TypeId::LookupByName("ns3::UdpSocketFactory");
    m_socket = Socket::CreateSocket(GetNode(), tid);
    InetSocketAddress local = InetSocketAddress(Ipv4Address::GetAny(), m_appPort);
    m_socket->Bind(local);
    m_socket->SetRecvCallback(MakeCallback(&PennSearch::RecvMessage, this));
  }

  // Configure timers
  m_auditPingsTimer.SetFunction(&PennSearch::AuditPings, this);
  // Start timers
  m_auditPingsTimer.Schedule(m_pingTimeout);
}

void PennSearch::StopApplication(void)
{
  // Stop chord
  m_chord->StopChord();
  // Close socket
  if (m_socket)
  {
    m_socket->Close();
    m_socket->SetRecvCallback(MakeNullCallback<void, Ptr<Socket>>());
    m_socket = 0;
  }

  // Cancel timers
  m_auditPingsTimer.Cancel();
  m_pingTracker.clear();
}

void PennSearch::ProcessCommand(std::vector<std::string> tokens)
{
  std::vector<std::string>::iterator iterator = tokens.begin();
  std::string command = *iterator;
  if (command == "CHORD")
  {
    // Send to Chord Sub-Layer
    tokens.erase(iterator);
    m_chord->ProcessCommand(tokens); // leave is a case here?
  }
  if (command == "PING")
  {
    if (tokens.size() < 3)
    {
      ERROR_LOG("Insufficient PING params...");
      return;
    }
    iterator++;
    if (*iterator != "*")
    {
      std::string nodeId = *iterator;
      iterator++;
      std::string pingMessage = *iterator;
      SendPing(nodeId, pingMessage);
    }
    else
    {
      iterator++;
      std::string pingMessage = *iterator;
      std::map<uint32_t, Ipv4Address>::iterator iter;
      for (iter = m_nodeAddressMap.begin(); iter != m_nodeAddressMap.end(); iter++)
      {
        std::ostringstream sin;
        uint32_t nodeNumber = iter->first;
        sin << nodeNumber;
        std::string nodeId = sin.str();
        SendPing(nodeId, pingMessage);
      }
    }
  }

  // m2 publishing
  if (command == "PUBLISH") {

    std::cout << "command == PUBLISH" << std::endl;

    // std::cout << "Cmd is PUBLISH..." << std::endl;
    // std::cout << "tokens.size(): " << tokens.size() << std::endl;
    if (tokens.size() >= 2) {
      ++iterator;
      std::string fileName = *iterator;  
      // std::cout << "fileName: " << fileName << std::endl;

      std::cout << "fileName" << fileName << std::endl;

      constructInvertedList(fileName);

    } else {
      ERROR_LOG("Please specify the file path to read!");
      return;
    }

  }

  if (command == "SEARCH") {
      // search

      // Search debug: Whenever a node issues a search query with terms T1, T2,...,Tn, you should output:
      // Search<T1,T2,...,Tn>


      std::cout << "command == SEARCH" << std::endl;
      ++iterator;

      std::string viaNodeID = *iterator;
      Ipv4Address viaNodeAddr = ResolveNodeIpAddress(viaNodeID);

      if (viaNodeAddr != Ipv4Address::GetAny()) {

        std::vector<std::string> queryTerms;

        std::string searchStr = "Search<";

        for (auto tokIter = ++iterator; tokIter != tokens.end(); ++tokIter) {

          if (searchStr != "Search<") {
            searchStr += ", ";
          }

          // std::cout << "*tokIter: " << *tokIter << std::endl;
          queryTerms.push_back(*tokIter);
          searchStr += *tokIter;
        }

        searchStr += ">";

        SEARCH_LOG(searchStr);

      std::cout << "viaNodeAddr: " << viaNodeAddr << std::endl;
    
        
      constructInitSearchReq(viaNodeAddr, queryTerms);
    } else {

      // error log?
    }
        
  }


    // leave?
    // or these handled in callback function(s)?

    // join/rejoin? 
      // this may be okay if chord correctly finds the new chord node, 
      // as the outdated info on other node will not be accessed anyway?


}

void PennSearch::SendPing(std::string nodeId, std::string pingMessage)
{
  // Send Ping Via-Chord layer
  SEARCH_LOG("Sending Ping via Chord Layer to node: " << nodeId << " Message: " << pingMessage);
  Ipv4Address destAddress = ResolveNodeIpAddress(nodeId);
  m_chord->SendPing(destAddress, pingMessage);
}

void PennSearch::SendPennSearchPing(Ipv4Address destAddress, std::string pingMessage)
{
  if (destAddress != Ipv4Address::GetAny())
  {
    uint32_t transactionId = GetNextTransactionId();
    SEARCH_LOG("Sending PING_REQ to Node: " << ReverseLookup(destAddress) << " IP: " << destAddress << " Message: " << pingMessage << " transactionId: " << transactionId);
    Ptr<PingRequest> pingRequest = Create<PingRequest>(transactionId, Simulator::Now(), destAddress, pingMessage);
    // Add to ping-tracker`
    m_pingTracker.insert(std::make_pair(transactionId, pingRequest));
    Ptr<Packet> packet = Create<Packet>();
    PennSearchMessage message = PennSearchMessage(PennSearchMessage::PING_REQ, transactionId);
    message.SetPingReq(pingMessage);
    packet->AddHeader(message);
    m_socket->SendTo(packet, 0, InetSocketAddress(destAddress, m_appPort));
  }
}

void PennSearch::RecvMessage(Ptr<Socket> socket)
{
  Address sourceAddr;
  Ptr<Packet> packet = socket->RecvFrom(sourceAddr);
  InetSocketAddress inetSocketAddr = InetSocketAddress::ConvertFrom(sourceAddr);
  Ipv4Address sourceAddress = inetSocketAddr.GetIpv4();
  uint16_t sourcePort = inetSocketAddr.GetPort();
  PennSearchMessage message;
  packet->RemoveHeader(message);

  switch (message.GetMessageType())
  {
  case PennSearchMessage::PING_REQ:
    ProcessPingReq(message, sourceAddress, sourcePort);
    break;
  case PennSearchMessage::PING_RSP:
    ProcessPingRsp(message, sourceAddress, sourcePort);
    break;
  // m2
  case PennSearchMessage::INVERTED_MSG:
    ProcessInvertedMsg(message);
    break;
  default:
    ERROR_LOG("Unknown Message Type!");
    break;
  }
}

void PennSearch::ProcessPingReq(PennSearchMessage message, Ipv4Address sourceAddress, uint16_t sourcePort)
{

  // Use reverse lookup for ease of debug
  std::string fromNode = ReverseLookup(sourceAddress);
  SEARCH_LOG("Received PING_REQ, From Node: " << fromNode << ", Message: " << message.GetPingReq().pingMessage);
  // Send Ping Response
  PennSearchMessage resp = PennSearchMessage(PennSearchMessage::PING_RSP, message.GetTransactionId());
  resp.SetPingRsp(message.GetPingReq().pingMessage);
  Ptr<Packet> packet = Create<Packet>();
  packet->AddHeader(resp);
  m_socket->SendTo(packet, 0, InetSocketAddress(sourceAddress, sourcePort));
}

void PennSearch::ProcessPingRsp(PennSearchMessage message, Ipv4Address sourceAddress, uint16_t sourcePort)
{
  // Remove from pingTracker
  std::map<uint32_t, Ptr<PingRequest>>::iterator iter;
  iter = m_pingTracker.find(message.GetTransactionId());
  if (iter != m_pingTracker.end())
  {
    std::string fromNode = ReverseLookup(sourceAddress);
    SEARCH_LOG("Received PING_RSP, From Node: " << fromNode << ", Message: " << message.GetPingRsp().pingMessage);
    m_pingTracker.erase(iter);
  }
  else
  {
    DEBUG_LOG("Received invalid PING_RSP!");
  }
}

void PennSearch::AuditPings()
{
  std::map<uint32_t, Ptr<PingRequest>>::iterator iter;
  for (iter = m_pingTracker.begin(); iter != m_pingTracker.end();)
  {
    Ptr<PingRequest> pingRequest = iter->second;
    if (pingRequest->GetTimestamp().GetMilliSeconds() + m_pingTimeout.GetMilliSeconds() <= Simulator::Now().GetMilliSeconds())
    {
      DEBUG_LOG("Ping expired. Message: " << pingRequest->GetPingMessage() << " Timestamp: " << pingRequest->GetTimestamp().GetMilliSeconds() << " CurrentTime: " << Simulator::Now().GetMilliSeconds());
      // Remove stale entries
      m_pingTracker.erase(iter++);
    }
    else
    {
      ++iter;
    }
  }
  // Rechedule timer
  m_auditPingsTimer.Schedule(m_pingTimeout);
}



// m2
void PennSearch::ProcessInvertedMsg(PennSearchMessage message)
{
  std::string invertedMessage = message.GetInvertedMessage().invertedMessage;

  if (invertedMessage == "store") // includes storing because some node left/joined
  {
    processInvertedStore(message);

  } else if (invertedMessage == "search_init") {

    initInvertedSearch(message);

  } else if (invertedMessage == "search") // need to increase hop count?
  {
    processInvertedSearch(message);
  } 
  else if (invertedMessage == "search_result") // originator gets search result
  {
    processInvertedSearchResult(message);
  }
  else if (invertedMessage == "node_join_req") // originator gets search result
  {
    processNodeJoinReq(message);
  }
  else
  {
    ERROR_LOG("Unknown lookupMessage string content!");
  }
}



//

uint32_t
PennSearch::GetNextTransactionId()
{
  return m_currentTransactionId++;
}

// Handle Chord Callbacks

void PennSearch::HandleChordPingFailure(Ipv4Address destAddress, std::string message)
{
  SEARCH_LOG("Chord Ping Expired! Destination nodeId: " << ReverseLookup(destAddress) << " IP: " << destAddress << " Message: " << message);
}

void PennSearch::HandleChordPingSuccess(Ipv4Address destAddress, std::string message)
{
  SEARCH_LOG("Chord Ping Success! Destination nodeId: " << ReverseLookup(destAddress) << " IP: " << destAddress << " Message: " << message);
  // Send ping via search layer
  SendPennSearchPing(destAddress, message);
}

void PennSearch::HandleChordPingRecv(Ipv4Address destAddress, std::string message)
{
  SEARCH_LOG("Chord Layer Received Ping! Source nodeId: " << ReverseLookup(destAddress) << " IP: " << destAddress << " Message: " << message);
}

// Override PennLog

void PennSearch::SetTrafficVerbose(bool on)
{
  m_chord->SetTrafficVerbose(on);
  g_trafficVerbose = on;
}

void PennSearch::SetErrorVerbose(bool on)
{
  m_chord->SetErrorVerbose(on);
  g_errorVerbose = on;
}

void PennSearch::SetDebugVerbose(bool on)
{
  m_chord->SetDebugVerbose(on);
  g_debugVerbose = on;
}

void PennSearch::SetStatusVerbose(bool on)
{
  m_chord->SetStatusVerbose(on);
  g_statusVerbose = on;
}

void PennSearch::SetChordVerbose(bool on)
{
  m_chord->SetChordVerbose(on);
  g_chordVerbose = on;
}

void PennSearch::SetSearchVerbose(bool on)
{
  m_chord->SetSearchVerbose(on);
  g_searchVerbose = on;
}

// m2 publishing related
void PennSearch::constructInvertedList(std::string fileName) {

  // from ed
  // The autograder will use file paths such as  ./contrib/upenn-cis553/keys/metadata0.keys.
  // it is sufficient to do the following without parsing the file path:
  std::ifstream data;
  data.open(fileName);
  // std::cout << "data.is_open(): "<< data.is_open() << std::endl;

  // format: doc0 T1 T2 T3 T4
  std::string readLine;
  while (std::getline(data, readLine)) {

    // std::cout << "read line: "<< readLine << std::endl;
    std::vector<std::string> splited;
    splitStr(readLine, ' ', splited);
    // for (auto word : splited) {
    //     std::cout << word << std::endl;
    // }

    long unsigned int splitedSize = splited.size();

    if (splitedSize >= 1) {

      std::string doc = splited[0];

      // add to m_invertLists: unordered_map<std::string, std::set<std::string> >
      for (long unsigned int i = 1; i < splitedSize; ++i) {
        
        std::string keyword = splited[i];

        auto itorFind = m_invertLists.find(keyword);
        // keyword already exists, update into the set
        if (itorFind != m_invertLists.end()) { 

          m_invertLists[keyword].insert(doc);
        } else {
          // init a new set, then add to map
          std::set<std::string> newSet;
          newSet.insert(doc);

          m_invertLists[keyword] = newSet;
        }

        // For grading purposes, we require the following information to be printed using SEARCH_LOG 
        // Publish<keyword, docID>
        SEARCH_LOG("Publish<" << keyword << ", " << doc << ">");
      }

    }

  }
/*
  std::cout << "fileName: " << fileName << std::endl;
  // cout m_invertLists to check
  for (auto const& ent : m_invertLists) {
    std::cout << ent.first  // (key)
               << ':';
    // (value)
    auto setItor = ent.second.begin();
    for (; setItor != ent.second.end(); ++setItor) {
      std::cout << *setItor << " ";
    }

    std::cout << std::endl;
  }

*/
  // iterate k-v entries, lookup node and prepare ptk to store
  for (auto const& ent : m_invertLists) {


    // look up node based on hash
    // hash the term
    std::string term = ent.first;
    uint32_t termHash = PennKeyHelper::CreateShaKey(term);


    // // if the look up node is myself, store locally
    // if (termHash == m_chord->myKey) {

    //   std::set<std::string> res;

    //   auto setItor = ent.second.begin();
    //   for (; setItor != ent.second.end(); ++setItor) {

    //     res.insert(*setItor);
    //     SEARCH_LOG("Store<" << term << ", " << *setItor << ">");

    //     // std::cout << *setItor << " ";
    //   }

    //   m_searchDatabase[term] = res;
    //   continue;
    // } 

    // 更新 m_storeJobs， 后续助力handle callback
    uint32_t txID = GetNextTransactionId();
    m_storeJobs[txID] = term;

    // 魔法开始，at some point handle callback会被调用然后根据look up结果发相关packet
    // m_chord->sendSearchReqPacket(termHash, txID);
    // std::stringstream ss;  
    // ss << txID;  
    // std::string txIDmsg;  
    // ss >> txIDmsg;

    std::cout << "txID: "<< txID << ", term:" << term << std::endl;
    // std::cout << "m_storeJobs[txID]: "<< m_storeJobs[txID] << std::endl;
    m_chord->sendSearchReqPacket(termHash, txID);

  }
}


// search req, from originator node to contact node, whom will then do look up accordingly
// originator doesn't need to do lookup, so no search job created here, just to inform contac
void PennSearch::constructInitSearchReq(Ipv4Address destAddress, std::vector<std::string> queryTerms) {
 
  if (queryTerms.size() == 0) {
    return;
  }

  // consruct and send as search pkt 

  Ptr<Packet> packet = Create<Packet>();
  uint32_t txId = GetNextTransactionId ();
  std::set<std::string> resultSoFar;

  std::cout << "constructInitSearchReq queryTerms size: " << queryTerms.size() << std::endl;

  // SetInvertedMessage(std::string invertedMessage,  std::vector<std::string> keywords, std::set<std::string> docIDs,
                        // uint32_t hopCount, Ipv4Address originatorIp, Ipv4Address destinationIp, uint32_t termKey, 
                        // uint32_t originatorKey, uint32_t destinationKey)
  PennSearchMessage message = PennSearchMessage(PennSearchMessage::INVERTED_MSG, txId);
  message.SetInvertedMessage("search_init", queryTerms, resultSoFar, 0, m_local, destAddress,
             PennKeyHelper::CreateShaKey(queryTerms[0]), PennKeyHelper::CreateShaKey(m_local), PennKeyHelper::CreateShaKey(destAddress));
  packet->AddHeader(message);

  // ？
  m_socket->SendTo(packet, 0, InetSocketAddress(destAddress, m_appPort));


}


// std::string
// need a uint32_t transactionID to track job info
void PennSearch::HandleNodeLookup (Ipv4Address destAddress, std::string message, uint32_t transactionID) {

/* TBD
rejoin也有查询， 这个要store jobs 修改用struct分辨然后rejoin的不加count

第一次join调用的也是 (re)join的流程， 所以要加以分辨？

//
还有加一个 internalHopNum 的parameter
*/
  lookupNumber++;
  // TBD: should includ internal courd count
  hopNumber++;

  std::cout << "HandleNodeLookup destAddress: "<< destAddress << ", dest NodeId: " << ReverseLookup(destAddress) << std::endl;
  std::cout << "HandleNodeLookup txID: "<< transactionID << std::endl;

  // check if destAddress is myself, if so, no need to fwd another packet
  bool destIsMe = (destAddress == m_local);

  // 根据transactionID出现在m_storeJobs还是m_searchJobs里判断任务
  // 之后根据相关信息
    // init packet accordingly
    
  // send to the looked up node
   // tbd: need transactionID
  auto storeJobsIter = m_storeJobs.find(transactionID);
  auto searchJobsIter = m_searchJobs.find(transactionID);

  if (storeJobsIter != m_storeJobs.end()) {

    std::string term = storeJobsIter->second;

    std::cout << "store term: "<< term << std::endl;

    // store:
    if (destIsMe) {

      auto setItor = m_invertLists[term].begin();
      for (; setItor != m_invertLists[term].end(); ++setItor) {

        auto termFind = m_searchDatabase.find(term);
        // keyword already exists, update into the m_searchDatabase[term]
        if (termFind != m_searchDatabase.end()) { 

          m_searchDatabase[term].insert(*setItor);

        } else {
          // init a new set, then add to map
          std::set<std::string> newSet;
          newSet.insert(*setItor);

          m_searchDatabase[term] = newSet;
        }

        SEARCH_LOG("Store<" << term << ", " << *setItor << ">");
        // std::cout << *setItor << " ";
      }


    } else {
        // deal with job info accordingly and send pkt to destAddress
        // send inverted msg packet for keyword/term and its docIds> 
        // then the node responside will processInvertedMsg 

        // this should be logged in processInvertedMsg after the receriving node successfully updated to the m_searchDatabase
        //  SEARCH_LOG("Store<" << keyword << ", " << *setItor << ">");


      Ptr<Packet> packet = Create<Packet>();
      uint32_t txId = GetNextTransactionId ();


      std::vector<std::string> keywords;
      keywords.push_back(term);

      // SetInvertedMessage(std::string invertedMessage,  std::vector<std::string> keywords, std::set<std::string> docIDs,
                        // uint32_t hopCount, Ipv4Address originatorIp, Ipv4Address destinationIp, uint32_t termKey, 
                        // uint32_t originatorKey, uint32_t destinationKey)
      PennSearchMessage message = PennSearchMessage(PennSearchMessage::INVERTED_MSG, txId);
      message.SetInvertedMessage("store", keywords, m_invertLists[term], 0, m_local, destAddress,
             PennKeyHelper::CreateShaKey(term), PennKeyHelper::CreateShaKey(m_local), PennKeyHelper::CreateShaKey(destAddress));
      packet->AddHeader(message);
      m_socket->SendTo(packet, 0, InetSocketAddress(destAddress, m_appPort));

    }

    // erase after job info processed
    m_storeJobs.erase(storeJobsIter);





  } else if (searchJobsIter != m_searchJobs.end()) {

    // search

    SearchInfo searchInfo = searchJobsIter->second;

    // destinationIp should be updated in callback after node look up
    // destinationKey should be updated in callback after node look up

    // SetInvertedMessage(std::string invertedMessage,  std::vector<std::string> keywords, std::set<std::string> docIDs,
                        // uint32_t hopCount, Ipv4Address originatorIp, Ipv4Address destinationIp, uint32_t termKey, 
                        // uint32_t originatorKey, uint32_t destinationKey)
      PennSearchMessage message = PennSearchMessage(PennSearchMessage::INVERTED_MSG, GetNextTransactionId());
      message.SetInvertedMessage("search", searchInfo.keywords, searchInfo.docIDs, searchInfo.hopCount, searchInfo.originatorIp, destAddress,
             searchInfo.termKey, searchInfo.originatorKey, PennKeyHelper::CreateShaKey(destAddress));
     

    if (destIsMe) {

      std::cout << "destIsMe" <<std::endl;

      // find search job, still need to send packet fwd if there's more chained search
      // or send back final result to originator if I'm the last
      // the above logic may utilize the processInvertedSearch(PennSearchMessage message) function
      processInvertedSearch(message);

        
    } else {

      std::cout << "not in destIsMe" << std::endl;

      // find search job, construct & send packet to sent to destAddr if there's more chained search
      Ptr<Packet> packet = Create<Packet>();
      packet->AddHeader(message);
      m_socket->SendTo(packet, 0, InetSocketAddress(destAddress, m_appPort));
    }

    // erase after job info processed
    m_searchJobs.erase(searchJobsIter);
      

  } else {

      // error log
      // transactionID + " on nodeID: " + ReverseLookup(m_local
      ERROR_LOG("Neither valid store nor search job...");
  }

  

}






void PennSearch::processInvertedStore(PennSearchMessage message) {


  PennSearchMessage::InvertedMsg invertedMsg = message.GetInvertedMessage();

  // std::string invertedMessage = invertedMsg.invertedMessage; // subtype info
  std::vector<std::string> keywords = invertedMsg.keywords; // or terms, making it a vec so easier to handle search terms
  std::set<std::string> docIDs = invertedMsg.docIDs;
        
  // uint32_t hopCount = invertedMsg.hopCount;
  // Ipv4Address originatorIp = invertedMsg.originatorIp;
  // Ipv4Address destinationIp = invertedMsg.destinationIp;

  // hash keys
  // uint32_t termKey = invertedMsg.termKey;
  // uint32_t originatorKey = invertedMsg.originatorKey;
  // uint32_t destinationKey = invertedMsg.destinationKey;

  // store to my node local storage
  std::set<std::string> res;

  std::string term = keywords[0];

  std::cout << "process store keyword: " << term << " on nodeId: " << ReverseLookup(m_local)<< std::endl;
  // std::cout << "docIDs.size(): " << docIDs.size() << std::endl;
  
  // auto setItor = docIDs.begin();
  // for (; setItor != docIDs.end(); ++setItor) {

  //   // std::cout << "*setItor: " << *setItor << "for term: " << term << std::endl;
  //   res.insert(*setItor);
  //   SEARCH_LOG("Store<" << term << ", " << *setItor << ">");
  //   // std::cout << *setItor << " ";
  // }

  // m_searchDatabase[term] = res;

  auto setItor = docIDs.begin();
    for (; setItor != docIDs.end(); ++setItor) {

      auto termFind = m_searchDatabase.find(term);
      // keyword already exists, update into the m_searchDatabase[term]
      if (termFind != m_searchDatabase.end()) { 

        m_searchDatabase[term].insert(*setItor);
          
      } else {
        // init a new set, then add to map
        std::set<std::string> newSet;
        newSet.insert(*setItor);
        m_searchDatabase[term] = newSet;
      }

      SEARCH_LOG("Store<" << term << ", " << *setItor << ">");
        // std::cout << *setItor << " ";
  }

  
}

// need to look up to find the node containing the first query term
void PennSearch::initInvertedSearch(PennSearchMessage message) {

  PennSearchMessage::InvertedMsg invertedMsg = message.GetInvertedMessage();
  // get payload
  // std::string invertedMsgRecv = invertedMsg.invertedMessage;
  std::vector<std::string> queryTerms = invertedMsg.keywords; // or terms, making it a vec so easier to handle search terms
  std::set<std::string> docIDsSoFar = invertedMsg.docIDs;
  // after initInvertedSearch, this will always be 1 as here the first lookup will be called
  // uint32_t hopCount = invertedMsg.hopCount; 
  // ++hopCount;
  Ipv4Address originatorIp = invertedMsg.originatorIp;
  Ipv4Address destinationIp = invertedMsg.destinationIp; // to be updated in call back

  // hash keys
  uint32_t termKey = PennKeyHelper::CreateShaKey(queryTerms[0]);
  uint32_t originatorKey = invertedMsg.originatorKey;
  uint32_t destinationKey = invertedMsg.destinationKey;



   uint32_t hopCount = 1;


   // construct search job accordingly, then in callback after node look up
      uint32_t txID = GetNextTransactionId();

      SearchInfo searchJobInfo = {

                .invertedMessage = "search",
                .keywords = queryTerms,
                .docIDs = docIDsSoFar,
      
                .hopCount = hopCount, // keep track of internal chord hop numbers of this lookup
                
                .originatorIp = originatorIp,
                .destinationIp = destinationIp,
                // destinationIp should be updated in callback after node look up

                // hash keys
                .termKey = termKey,
                .originatorKey = originatorKey,
                .destinationKey = destinationKey
                // destinationKey should be updated in callback after node look up
    };

    m_searchJobs[txID] = searchJobInfo;

    m_chord->sendSearchReqPacket(termKey, txID);

}


// the term is stored on my node
void PennSearch::processInvertedSearch(PennSearchMessage message) {

  PennSearchMessage::InvertedMsg invertedMsg = message.GetInvertedMessage();
  // get payload
  // std::string invertedMsgRecv = invertedMsg.invertedMessage;
  std::vector<std::string> queryTerms = invertedMsg.keywords; // or terms, making it a vec so easier to handle search terms
  std::set<std::string> docIDsSoFar = invertedMsg.docIDs;
        
  uint32_t hopCount = invertedMsg.hopCount;
  Ipv4Address originatorIp = invertedMsg.originatorIp;
  Ipv4Address destinationIp = invertedMsg.destinationIp;

  // hash keys
  // uint32_t termKey = invertedMsg.termKey;
  uint32_t originatorKey = invertedMsg.originatorKey;
  uint32_t destinationKey = invertedMsg.destinationKey;
  

  // queryTerms[0] is what I should look up
  std::string mySearchTerm = queryTerms[0];
  // mySearchTermHash
  uint32_t mySearchTermHash = PennKeyHelper::CreateShaKey(mySearchTerm);
  // erase the my term so the receiving node vector starts with it's own searchTerm
  queryTerms.erase(queryTerms.begin());
  // note: after erasing mine, if queryTerms remains only 1 element, the next node is the last round search & intersaction
    // it can then check the vector size to act accordingly
    // std::string invertedMsgToNext = "search";


  // local databse seach
  std::set<std::string> localResult = m_searchDatabase[mySearchTerm];



  std::cout << "nodeID " << ReverseLookup(m_local) << "'s mySearchTerm: " << mySearchTerm << std::endl;
  
  // 
  std::cout << "docIDsSoFar: ";
  for (auto str : docIDsSoFar) {
     std::cout << str << " ";
  }
  std::cout << std::endl;

  std::cout << "localResult: ";
  for (auto str : localResult) {
    std::cout << str << " ";
  }
  std::cout << std::endl;


  // final result ids to pass into packet
  std::set<std::string> finalResult;
  
  // to check: count 0 is the init round, could it  be that init node is it self?
  // if I'm the first round actually query & search, as the hopCount is 0 for now
  // the first round does not call intersection(thil will ptherwise clean up my search result)
  if (hopCount <= 1) {
  
    finalResult = localResult;
  } else {

    // only check if both are not empty
    if (localResult.size() != 0 && docIDsSoFar.size() != 0) {

      // ohterwise perform intersection 
      finalResult = setIntersection(localResult, docIDsSoFar);

    }
  }


  std::cout << "finalResult: ";
  for (auto str : finalResult) {
    std::cout << str << " ";
  }
  std::cout << std::endl;

  
  
  // Inverted list shipping debug: For each inverted list <docIDList> being shipped in the process of the search, you should output:
    // InvertedListShip<targetKeyword, docIDList>
  // Message: InvertedListShip<Leonard-Nimoy, {Star-Trek}>
  // Message: InvertedListShip<Leonard-Nimoy, 'Empty List'>
  //  InvertedListShip<Keira-Knightley, {Pirates-of-the-Caribbean, Alice-in-Wonderland}>
  std::string invertedListShip = "InvertedListShip<" + mySearchTerm + ", ";

  if (finalResult.size() == 0) {

    // ? with quotation mark 'Empty List'
    invertedListShip += "'Empty List'";

  } else {

    invertedListShip += "{";

    // std::string firstVal = *finalResult.begin();
    // invertedListShip += firstVal;

    // for (auto str : finalResult) {
    //   //filter first
    //   if (str != firstVal) {
    //     invertedListShip += ", ";
    //   }
    //   invertedListShip += str;
    // }


    auto resItor = finalResult.begin();
    invertedListShip += *resItor;

    resItor++;
    for (; resItor != finalResult.end(); ++resItor) {

      invertedListShip += ", ";
      invertedListShip += *resItor;
    }

    invertedListShip += "}";
  }

  invertedListShip += ">";

  // std::cout << "invertedListShip: " << invertedListShip << std::endl;
  SEARCH_LOG(invertedListShip);

  // no more term after eraing mine, meaning that my query will be the last search 
  // if I'm the last node look up info, deriectly send processed info to the originator
  if (queryTerms.size() == 0) {

    // process & create search_result pkt to send directly to originator which
    // will should printed out as result on the originator node


    Ptr<Packet> packet = Create<Packet>();
    // SetInvertedMessage(std::string invertedMessage,  std::vector<std::string> keywords, std::set<std::string> docIDs,
                        // uint32_t hopCount, Ipv4Address originatorIp, Ipv4Address destinationIp, uint32_t termKey, 
                        // uint32_t originatorKey, uint32_t destinationKey)
      PennSearchMessage message = PennSearchMessage(PennSearchMessage::INVERTED_MSG, GetNextTransactionId());
      message.SetInvertedMessage("search_result", queryTerms, finalResult, hopCount, originatorIp, originatorIp,
             mySearchTermHash, originatorKey, originatorKey);
      packet->AddHeader(message);
      // send back directly to originatorIp
      m_socket->SendTo(packet, 0, InetSocketAddress(originatorIp, m_appPort));

      
  } else { // else I need to do the next round look up and pass along info so far

      // process & constuct search job to be sent to the next lookup node

      // increase hop count as I need to do look up
      ++hopCount;

      // construct search job accordingly, then in callback after node look up
      uint32_t txID = GetNextTransactionId();

      uint32_t nextTermHash = PennKeyHelper::CreateShaKey(queryTerms[0]);

      SearchInfo searchJobInfo = {

                .invertedMessage = "search",
                .keywords = queryTerms,
                .docIDs = finalResult,
      
                .hopCount = hopCount, // keep track of internal chord hop numbers of this lookup
                
                .originatorIp = originatorIp,
                .destinationIp = destinationIp,
                // destinationIp should be updated in callback after node look up

                // hash keys
                .termKey = nextTermHash,
                .originatorKey = originatorKey,
                .destinationKey = destinationKey
                // destinationKey should be updated in callback after node look up
    };

    m_searchJobs[txID] = searchJobInfo;
    // ！！here should be the hash of the next of my term -_-
    m_chord->sendSearchReqPacket(nextTermHash, txID);


  }


  // • Lookup forwarding debug: Every time a node forwards a lookup request, the following message is printed:
  // LookupRequest<currentNodeKey>: NextHop<nextNodeNum, nextNodeKey, targetKey>


}


void PennSearch::processInvertedSearchResult(PennSearchMessage message) {

  /*
  Search results debug: At the end of intersecting all keywords (T1, T2, . . . , Tn), output the final document list <docIDList> that is being sent back to the initial query node:
  SearchResults<queryNode, docIDList>
  */

  PennSearchMessage::InvertedMsg invertedMsg = message.GetInvertedMessage();
  // get payload
  std::set<std::string> docIDsSoFar = invertedMsg.docIDs;



  /*
  os << ((m_address >> 24) & 0xff) << "."
     << ((m_address >> 16) & 0xff) << "."
     << ((m_address >> 8) & 0xff) << "."
     << ((m_address >> 0) & 0xff);
  */

  std::string searchResultStr = ", ";

  if (docIDsSoFar.size() == 0) {

    // ? with quotation mark 'Empty List'
    searchResultStr += "'Empty List'";

  } else {

    searchResultStr += "{";

    auto resItor = docIDsSoFar.begin();
    searchResultStr += *resItor;

    resItor++;
    for (; resItor != docIDsSoFar.end(); ++resItor) {

      searchResultStr += ", ";
      searchResultStr += *resItor;
    }


    searchResultStr += "}";
  }
  searchResultStr += ">";

  SEARCH_LOG("SearchResults<" << m_local << searchResultStr);
}


// helper to split readLine
void PennSearch::splitStr(std::string const &line, const char delim, std::vector<std::string> &vec) { 

    std::stringstream strStream(line); 
    std::string tok; 

    while (std::getline(strStream, tok, delim)) { 
        vec.push_back(tok); 
    }

} 


// get docID Intersection
std::set<std::string> PennSearch::setIntersection(std::set<std::string> set1, std::set<std::string> set2) {

  std::set<std::string> common;
  std::set_intersection(set1.begin(),set1.end(),set2.begin(),set2.end(), std::inserter(common, common.end()));

  return common;
}
    




// m2b
void PennSearch::HandleNodeJoin(Ipv4Address destAddress) {

  // std::cout << "in HandleNodeJoin..." << std::endl;

  // need to grab data from my succ node

  if (destAddress == m_local) { // I am the only node in the ring, do nothing
    return;
  }

  // else, send join request to succ node
  Ptr<Packet> packet = Create<Packet>();
  uint32_t txId = GetNextTransactionId ();

  std::vector<std::string> keywords; // empty
  std::set<std::string> docIDs; // empty

  // SetInvertedMessage(std::string invertedMessage,  std::vector<std::string> keywords, std::set<std::string> docIDs,
                    // uint32_t hopCount, Ipv4Address originatorIp, Ipv4Address destinationIp, uint32_t termKey, 
                    // uint32_t originatorKey, uint32_t destinationKey)
  PennSearchMessage message = PennSearchMessage(PennSearchMessage::INVERTED_MSG, txId);
  message.SetInvertedMessage("node_join_req", keywords, docIDs, 0, m_local, destAddress,
          0, PennKeyHelper::CreateShaKey(m_local), PennKeyHelper::CreateShaKey(destAddress));
  packet->AddHeader(message);
  m_socket->SendTo(packet, 0, InetSocketAddress(destAddress, m_appPort));
}

// m2b
void PennSearch::HandleNodeLeave(Ipv4Address destAddress) {

  // std::cout << "in HandleNodeLeave..." << std::endl;

  if (destAddress == m_local) { // I am the only node in the ring, and i leave!
    // empty m_searchdatabase
    // m_searchDatabase.clear();
    return;
  }

  for (auto const& ent : m_searchDatabase) { // I will send <term:docs> packet one by one

    // look up node based on hash
    // hash the term
    std::string term = ent.first;

    SEARCH_LOG("HandleNodeLeave curr term iterated: " << term); 

    Ptr<Packet> packet = Create<Packet>();
    uint32_t txId = GetNextTransactionId ();


    std::vector<std::string> keywords;
    keywords.push_back(term);

    // SetInvertedMessage(std::string invertedMessage,  std::vector<std::string> keywords, std::set<std::string> docIDs,
                      // uint32_t hopCount, Ipv4Address originatorIp, Ipv4Address destinationIp, uint32_t termKey, 
                      // uint32_t originatorKey, uint32_t destinationKey)
    PennSearchMessage message = PennSearchMessage(PennSearchMessage::INVERTED_MSG, txId);
    message.SetInvertedMessage("store", keywords, m_searchDatabase[term], 0, m_local, destAddress,
            PennKeyHelper::CreateShaKey(term), PennKeyHelper::CreateShaKey(m_local), PennKeyHelper::CreateShaKey(destAddress));
    packet->AddHeader(message);
    m_socket->SendTo(packet, 0, InetSocketAddress(destAddress, m_appPort));
  }
}



// reference to processStore
void PennSearch::processNodeJoinReq(PennSearchMessage message) {

  // std::cout << "in processNodeJoinReq..." << std::endl;

  PennSearchMessage::InvertedMsg invertedMsg = message.GetInvertedMessage();
  Ipv4Address originatorIp = invertedMsg.originatorIp;
  uint32_t predKey = PennKeyHelper::CreateShaKey(invertedMsg.originatorIp);

  // std::set<std::string> invertedListToShare;

  // test
  for (auto const& ent : m_searchDatabase) { // I will send <term:docs> packet one by one

    // look up node based on hash
    // hash the term
    std::string term = ent.first;
    uint32_t termHash = PennKeyHelper::CreateShaKey(term);

    SEARCH_LOG("processNodeJoinReq curr term iterated: " << term); 

    Ptr<Packet> packet = Create<Packet>();
    uint32_t txId = GetNextTransactionId ();


    std::vector<std::string> keywords;
  
    if (termHash <= predKey){
      keywords.push_back(term);

      // SetInvertedMessage(std::string invertedMessage,  std::vector<std::string> keywords, std::set<std::string> docIDs,
                        // uint32_t hopCount, Ipv4Address originatorIp, Ipv4Address destinationIp, uint32_t termKey, 
                        // uint32_t originatorKey, uint32_t destinationKey)
      PennSearchMessage message = PennSearchMessage(PennSearchMessage::INVERTED_MSG, txId);
      message.SetInvertedMessage("store", keywords, m_searchDatabase[term], 0, m_local, originatorIp,
              PennKeyHelper::CreateShaKey(term), PennKeyHelper::CreateShaKey(m_local), PennKeyHelper::CreateShaKey(originatorIp));
      packet->AddHeader(message);
      m_socket->SendTo(packet, 0, InetSocketAddress(originatorIp, m_appPort));
        
      // m_searchDatabase.erase(term);
    }
  }


/*
  // iterate k-v entries, lookup node and prepare ptk to store
  for (auto const& ent : m_searchDatabase) {


    // look up node based on hash
    // hash the term
    std::string term = ent.first;
    uint32_t termHash = PennKeyHelper::CreateShaKey(term);


    // 更新 m_storeJobs， 后续助力handle callback
    uint32_t txID = GetNextTransactionId();
    m_storeJobs[txID] = term;

    // 魔法开始，at some point handle callback会被调用然后根据look up结果发相关packet

    std::cout << "txID: "<< txID << ", term:" << term << std::endl;
    // 会查到该term在更新完的ring里应该存在哪里，并调用m2a的callback func发相关store subtpe packet给新target
    m_chord->sendSearchReqPacket(termHash, txID);
  }
*/
}