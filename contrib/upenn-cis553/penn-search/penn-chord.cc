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

#include "penn-chord.h"
#include "penn-chord-message.h"

#include "ns3/inet-socket-address.h"
#include "ns3/random-variable-stream.h"
#include "ns3/penn-key-helper.h"
#include <openssl/sha.h>

using namespace ns3;

TypeId
PennChord::GetTypeId()
{
  static TypeId tid = TypeId("PennChord")
                          .SetParent<PennApplication>()
                          .AddConstructor<PennChord>()
                          .AddAttribute("AppPort", "Listening port for Application", UintegerValue(10001),
                                        MakeUintegerAccessor(&PennChord::m_appPort), MakeUintegerChecker<uint16_t>())
                          .AddAttribute("PingTimeout", "Timeout value for PING_REQ in milliseconds", TimeValue(MilliSeconds(2000)),
                                        MakeTimeAccessor(&PennChord::m_pingTimeout), MakeTimeChecker())
                          .AddAttribute("StableTimeout", "Timeout value for sending out stable request in milliseconds", TimeValue(MilliSeconds(20)),
                                        MakeTimeAccessor(&PennChord::m_stableTimeout), MakeTimeChecker())
                          .AddAttribute("FixFingerTimeout", "Timeout value for call fixFinger milliseconds", TimeValue(MilliSeconds(2000)),
                                        MakeTimeAccessor(&PennChord::m_fixFingerTimeout), MakeTimeChecker());
  return tid;
}

PennChord::PennChord()
    : m_auditPingsTimer(Timer::CANCEL_ON_DESTROY), m_stableTimer(Timer::CANCEL_ON_DESTROY), m_fingerTimer(Timer::CANCEL_ON_DESTROY)
{
  Ptr<UniformRandomVariable> m_uniformRandomVariable = CreateObject<UniformRandomVariable>();
  m_currentTransactionId = m_uniformRandomVariable->GetValue(0x00000000, 0xFFFFFFFF);
}

PennChord::~PennChord()
{
}

void PennChord::DoDispose()
{
  StopApplication();
  PennApplication::DoDispose();
}

void PennChord::StartApplication(void)
{
  std::cout << "PennChord::StartApplication()!!!!!" << std::endl;
  if (m_socket == 0)
  {
    TypeId tid = TypeId::LookupByName("ns3::UdpSocketFactory");
    m_socket = Socket::CreateSocket(GetNode(), tid);
    InetSocketAddress local = InetSocketAddress(Ipv4Address::GetAny(), m_appPort);
    m_socket->Bind(local);
    m_socket->SetRecvCallback(MakeCallback(&PennChord::RecvMessage, this));
    // std::cout << "reset m_socekt to not null, now is " << m_socket << std::endl;
  }

  // Configure timers
  m_auditPingsTimer.SetFunction(&PennChord::AuditPings, this);
  // Start timers
  m_auditPingsTimer.Schedule(m_pingTimeout);

  m_stableTimer.SetFunction(&PennChord::SetStableTimer, this);
  m_stableTimer.Schedule(m_stableTimeout);

  m_fingerTimer.SetFunction(&PennChord::fixFinger, this);
  m_fingerTimer.Schedule(m_fixFingerTimeout);

  // std::cout << "PennChord::StartApplication() - finished" << std::endl;
}

void PennChord::StopApplication(void)
{
  // Close socket
  if (m_socket)
  {
    m_socket->Close();
    m_socket->SetRecvCallback(MakeNullCallback<void, Ptr<Socket>>());
    m_socket = 0;
  }

  // Cancel timers
  m_auditPingsTimer.Cancel();
  m_stableTimer.Cancel();
  m_fingerTimer.Cancel();

  m_pingTracker.clear();
}

void PennChord::ProcessCommand(std::vector<std::string> tokens)
{
  // std::cout << "ProcessCommand started" << std::endl;

  DEBUG_LOG("processing new command")
  std::vector<std::string>::iterator iterator = tokens.begin();
  std::string command = *iterator;
  // std::cout << command << std::endl;
  if (command == "JOIN")
  {
    if (tokens.size() < 2)
    {
      ERROR_LOG("Insufficient JOIN params");
      return;
    }
    iterator++;
    std::istringstream sin(*iterator);
    // extract the via node number
    uint32_t viaNodeNum;
    sin >> viaNodeNum;
    // check if vianode number equals my node number
    // if so, this is the first node in the chord ring
    if (m_addressNodeMap[m_local] == viaNodeNum)
    {
      landmarkNodeInitialization();
    }
    else
    {
      // send a lookup message to the viaNode to look for my successor
      joiningNodeInitialization(std::to_string(viaNodeNum));
      // PennChordMessage message = PennChordMessage(PennChordMessage::LOOKUP_MSG, GetNextTransactionId());
      // // paylod / paylodip is not useful here
      // Ipv4Address destinationIp = m_nodeAddressMap[viaNodeNum];
      // message.SetLookupMessage("join", myKey, m_local, 0, 0, 0, destinationIp);
    }
    m_stableTimer.Schedule(m_stableTimeout);
    
    // m2b send signal to PennSearch Layer via handler
    // make callback
    
  }
  else if (command == "LEAVE")
  {
    // reaching here means i am a chord node to leave the ring
    // need to notify my neighbours about my leave
    if (succIP != unInitiazlied && succIP != m_local)
    {
      // send out a lookup message ("leave_pred") to my succ
      PennChordMessage messageToSucc = PennChordMessage(PennChordMessage::LOOKUP_MSG, GetNextTransactionId());
      messageToSucc.SetLookupMessage("leave_pred", myKey, m_local, predKey, predIP, 0, succIP);
      Ptr<Packet>
          packet = Create<Packet>();
      packet->AddHeader(messageToSucc);
      m_socket->SendTo(packet, 0, InetSocketAddress(succIP, m_appPort));
    }

    if (predIP != unInitiazlied && predIP != m_local)
    {
      // send out a lookup message ("leave_succ") to my pred
      PennChordMessage messageToPred = PennChordMessage(PennChordMessage::LOOKUP_MSG, GetNextTransactionId());
      messageToPred.SetLookupMessage("leave_succ", myKey, m_local, succKey, succIP, 0, predIP);
      Ptr<Packet>
          packet = Create<Packet>();
      packet->AddHeader(messageToPred);
      m_socket->SendTo(packet, 0, InetSocketAddress(predIP, m_appPort));
    }

    // m2b
    // Callback to PennSearch
    m_nodeLeaveCallback(succIP);

    setisChord(false);
    // setSuccKey(0);
    // setSuccIP(unInitiazlied);
    setPredIP(unInitiazlied);
    setPredKey(0);


  }
  else if (command == "RINGSTATE")
  {
    ringStateInvoke();
  }
  else
  {
    PRINT_LOG("Not a valid command!");
  }
}

void PennChord::SendPing(Ipv4Address destAddress, std::string pingMessage)
{
  if (destAddress != Ipv4Address::GetAny())
  {
    uint32_t transactionId = GetNextTransactionId();
    CHORD_LOG("Sending PING_REQ to Node: " << ReverseLookup(destAddress) << " IP: " << destAddress << " Message: " << pingMessage << " transactionId: " << transactionId);
    Ptr<PingRequest> pingRequest = Create<PingRequest>(transactionId, Simulator::Now(), destAddress, pingMessage);
    // Add to ping-tracker
    m_pingTracker.insert(std::make_pair(transactionId, pingRequest));
    Ptr<Packet> packet = Create<Packet>();
    PennChordMessage message = PennChordMessage(PennChordMessage::PING_REQ, transactionId);
    message.SetPingReq(pingMessage);
    packet->AddHeader(message);
    m_socket->SendTo(packet, 0, InetSocketAddress(destAddress, m_appPort));
  }
  else
  {
    // Report failure
    m_pingFailureFn(destAddress, pingMessage);
  }
}

void PennChord::RecvMessage(Ptr<Socket> socket)
{
  Address sourceAddr;
  Ptr<Packet> packet = socket->RecvFrom(sourceAddr);
  InetSocketAddress inetSocketAddr = InetSocketAddress::ConvertFrom(sourceAddr);
  Ipv4Address sourceAddress = inetSocketAddr.GetIpv4();
  uint16_t sourcePort = inetSocketAddr.GetPort();
  PennChordMessage message;
  packet->RemoveHeader(message);

  switch (message.GetMessageType())
  {
  case PennChordMessage::PING_REQ:
    ProcessPingReq(message, sourceAddress, sourcePort);
    break;
  case PennChordMessage::PING_RSP:
    ProcessPingRsp(message, sourceAddress, sourcePort);
    break;
  case PennChordMessage::LOOKUP_MSG:
    processLookupMsg(message);
    break;
  case PennChordMessage::STABILIZE_MSG:
    processStabilizeMsg(message);
    // std::cout << "stabilize_message type encountered" << std::endl;
    break;
  default:
    std::cout << message.GetMessageType() << std::endl;
    ERROR_LOG("Unknown Message Type!");
    break;
  }
}

void PennChord::ProcessPingReq(PennChordMessage message, Ipv4Address sourceAddress, uint16_t sourcePort)
{

  // Use reverse lookup for ease of debug
  std::string fromNode = ReverseLookup(sourceAddress);
  CHORD_LOG("Received PING_REQ, From Node: " << fromNode << ", Message: " << message.GetPingReq().pingMessage);
  // Send Ping Response
  PennChordMessage resp = PennChordMessage(PennChordMessage::PING_RSP, message.GetTransactionId());
  resp.SetPingRsp(message.GetPingReq().pingMessage);
  Ptr<Packet> packet = Create<Packet>();
  packet->AddHeader(resp);
  m_socket->SendTo(packet, 0, InetSocketAddress(sourceAddress, sourcePort));
  // Send indication to application layer
  m_pingRecvFn(sourceAddress, message.GetPingReq().pingMessage);
}

void PennChord::ProcessPingRsp(PennChordMessage message, Ipv4Address sourceAddress, uint16_t sourcePort)
{
  // Remove from pingTracker
  std::map<uint32_t, Ptr<PingRequest>>::iterator iter;
  iter = m_pingTracker.find(message.GetTransactionId());
  if (iter != m_pingTracker.end())
  {
    std::string fromNode = ReverseLookup(sourceAddress);
    CHORD_LOG("Received PING_RSP, From Node: " << fromNode << ", Message: " << message.GetPingRsp().pingMessage);
    m_pingTracker.erase(iter);
    // Send indication to application layer
    m_pingSuccessFn(sourceAddress, message.GetPingRsp().pingMessage);
  }
  else
  {
    DEBUG_LOG("Received invalid PING_RSP!");
  }
}

void PennChord::AuditPings()
{
  // std::cout << "Audit pings is run" << std::endl;
  std::map<uint32_t, Ptr<PingRequest>>::iterator iter;
  for (iter = m_pingTracker.begin(); iter != m_pingTracker.end();)
  {
    Ptr<PingRequest> pingRequest = iter->second;
    if (pingRequest->GetTimestamp().GetMilliSeconds() + m_pingTimeout.GetMilliSeconds() <= Simulator::Now().GetMilliSeconds())
    {
      DEBUG_LOG("Ping expired. Message: " << pingRequest->GetPingMessage() << " Timestamp: " << pingRequest->GetTimestamp().GetMilliSeconds() << " CurrentTime: " << Simulator::Now().GetMilliSeconds());
      // Remove stale entries
      m_pingTracker.erase(iter++);
      // Send indication to application layer
      m_pingFailureFn(pingRequest->GetDestinationAddress(), pingRequest->GetPingMessage());
    }
    else
    {
      ++iter;
    }
  }
  // Rechedule timer
  m_auditPingsTimer.Schedule(m_pingTimeout);
}

void PennChord::SetStableTimer()
{
  // std::cout << "setStableTimer is called" << std::endl;
  if (isChord == true)
  {
    sendStablizePacket();
    m_stableTimer.Schedule(m_stableTimeout);
  }
}

uint32_t
PennChord::GetNextTransactionId()
{
  return m_currentTransactionId++;
}

void PennChord::StopChord()
{
  StopApplication();
}

void PennChord::SetPingSuccessCallback(Callback<void, Ipv4Address, std::string> pingSuccessFn)
{
  m_pingSuccessFn = pingSuccessFn;
}

void PennChord::SetPingFailureCallback(Callback<void, Ipv4Address, std::string> pingFailureFn)
{
  m_pingFailureFn = pingFailureFn;
}

void PennChord::SetPingRecvCallback(Callback<void, Ipv4Address, std::string> pingRecvFn)
{
  m_pingRecvFn = pingRecvFn;
}

void PennChord::setOwnKey()
{
  myKey = PennKeyHelper::CreateShaKey(m_local);
}

void PennChord::setPredKey(uint32_t pred)
{
  predKey = pred;
}

void PennChord::setSuccKey(uint32_t succ)
{
  succKey = succ;
}

void PennChord::setSuccIP(Ipv4Address ip)
{
  succIP = ip;
}

void PennChord::setPredIP(Ipv4Address ip)
{
  predIP = ip;
}

void PennChord::setisChord(bool chord)
{
  isChord = chord;
}

uint32_t PennChord::findSucc()
{
  // Naive implementation for M1
  return succKey;
}

Ipv4Address PennChord::findSuccIp()
{
  return succIP;
}

void PennChord::processLookupMsg(PennChordMessage message)
{
  std::string lookupMessage = message.GetLookupMessage().lookupMessage;

  if (lookupMessage == "join")
  {
    processNodeJoinPacket(message);
  }
  else if (
      lookupMessage == "join_resp")
  {
    processJoiningRespPacket(message);
  }
  else if (lookupMessage == "leave_pred")
  {
    processLeaveOfPred(message);
  }
  else if (lookupMessage == "leave_succ")
  {
    processLeaveOfSucc(message);
  }
  else if (lookupMessage == "ringstate")
  {
    processRingStatePacket(message);
  }
  else if (lookupMessage == "fix_req")
  {
    processFixReqPacket(message);
  }
  else if (lookupMessage == "fix_resp")
  {
    processFixRespPacket(message);
  }
  else if (lookupMessage == "search_req")
  {
    processSearchReqPacket(message);
  }
  else if (lookupMessage == "search_resp")
  {
    processSearchResp(message);
  }
  else
  {
    ERROR_LOG("Unknown lookupMessage string content!");
  }
}

void PennChord::processStabilizeMsg(PennChordMessage message)
{
  std::string stabilizeMessage = message.GetStabilizeMessage().stabilizeMessage;

  if (stabilizeMessage == "stable_req")
  {
    processStablizeRequest(message);
  }
  else if (stabilizeMessage == "stable_resp")
  {
    processStablizeResp(message);
  }
  else if (stabilizeMessage == "notify")
  {
    processNotify(message);
  }
  else
  {
    ERROR_LOG("Unknown stabilizeMessage string content!");
  }
}

void PennChord::printRingStateHelper()
{
  std::string currNodeNum = ReverseLookup(m_local);
  std::string succNodeNum = ReverseLookup(succIP);
  std::string predNodeNum = ReverseLookup(predIP);

  PRINT_LOG("Ring State\n"
            << "\tCurr<Node " << currNodeNum << ", " << m_local << ", " << PennKeyHelper::KeyToHexString(myKey) << ">\n"
            << "\tPred<Node " << predNodeNum << ", " << predIP << ", " << PennKeyHelper::KeyToHexString(predKey) << ">\n"
            << "\tSucc<Node " << succNodeNum << ", " << succIP << ", " << PennKeyHelper::KeyToHexString(succKey) << ">");
}

void PennChord::processNodeJoinPacket(PennChordMessage lookupMessage)
{

  uint32_t joiningNodeKey = lookupMessage.GetLookupMessage().originatorKey;

  if (myKey == succKey)
  {
    Ipv4Address joiningNodeIP = lookupMessage.GetLookupMessage().originatorIp;
    Ptr<Packet> joiningRespPacket = Create<Packet>();
    PennChordMessage resp = PennChordMessage(PennChordMessage::LOOKUP_MSG, GetNextTransactionId());
    resp.SetLookupMessage("join_resp", myKey, m_local, myKey, m_local, joiningNodeKey, joiningNodeIP);
    joiningRespPacket->AddHeader(resp);
    m_socket->SendTo(joiningRespPacket, 0, InetSocketAddress(joiningNodeIP, m_appPort));
  }

  else if ((joiningNodeKey > myKey && joiningNodeKey < succKey) || (myKey > succKey && joiningNodeKey < succKey) || (myKey > succKey && joiningNodeKey > myKey)) // correct location
  {
    // send the succKey to joining node
    Ipv4Address joiningNodeIP = lookupMessage.GetLookupMessage().originatorIp;
    Ptr<Packet> joiningRespPacket = Create<Packet>();
    PennChordMessage resp = PennChordMessage(PennChordMessage::LOOKUP_MSG, GetNextTransactionId());
    resp.SetLookupMessage("join_resp", myKey, m_local, succKey, succIP, joiningNodeKey, joiningNodeIP);
    joiningRespPacket->AddHeader(resp);
    m_socket->SendTo(joiningRespPacket, 0, InetSocketAddress(joiningNodeIP, m_appPort));
  }
  else
  // forward the packet to succ
  {
    Ipv4Address nextHopAddr = closest_preceding_finger(lookupMessage.GetLookupMessage().originatorKey);
    if (nextHopAddr != m_local)
    {
      forwardingLookupMessage(lookupMessage, nextHopAddr);
    }
    else
    {
      forwardingLookupMessage(lookupMessage, findSuccIp());
    }
  }
}

void PennChord::processLeaveOfPred(PennChordMessage message)
{
  setPredKey(message.GetLookupMessage().payload);
  setPredIP(message.GetLookupMessage().payloadIp);
}

void PennChord::processLeaveOfSucc(PennChordMessage message)
{
  setSuccKey(message.GetLookupMessage().payload);
  setSuccIP(message.GetLookupMessage().payloadIp);
}

void PennChord::forwardingLookupMessage(PennChordMessage lookupMessage, Ipv4Address destination)
{
  Ptr<Packet> forwardPacket = Create<Packet>();
  forwardPacket->AddHeader(lookupMessage);
  m_socket->SendTo(forwardPacket, 0, InetSocketAddress(destination, m_appPort));
}

void PennChord::processJoiningRespPacket(PennChordMessage message)
{
  uint32_t succKey = message.GetLookupMessage().payload;
  Ipv4Address succIP = message.GetLookupMessage().payloadIp;
  setSuccIP(succIP);
  setSuccKey(succKey);
  setisChord(true);
  setIthFingerEntery(0, succIP);

  // m2b
  // Callback to PennSearch
  m_nodeJoinCallback(succIP);
}

void PennChord::joiningNodeInitialization(std::string joiningViaNodeNum)
{

  setOwnKey();
  // predKey == 0 means I don't have a pred yet
  setPredKey(0);
  setPredIP(Ipv4Address());
  setisChord(true);
  // initialize an empty fingerTable
  fingerTable = std::vector<std::tuple<uint32_t, Ipv4Address>>(FINGER_SIZE, std::tuple<uint32_t, Ipv4Address>{PennKeyHelper::CreateShaKey(unInitiazlied), unInitiazlied});

  Ipv4Address receiverIp = ResolveNodeIpAddress(joiningViaNodeNum);
  // TODO: send lookup msg for joining through joiningVia node
  Ptr<Packet>
      packet = Create<Packet>();
  PennChordMessage message = PennChordMessage(PennChordMessage::LOOKUP_MSG, GetNextTransactionId());
  message.SetLookupMessage("join", myKey, m_local, 0, Ipv4Address(), 0, receiverIp);
  packet->AddHeader(message);
  m_socket->SendTo(packet, 0, InetSocketAddress(receiverIp, m_appPort));
}

void PennChord::landmarkNodeInitialization()
{
  setOwnKey();
  setPredKey(0);
  setPredIP(Ipv4Address());
  // setPredKey(myKey); // landmark's pred is always 0??
  setSuccKey(myKey);
  setSuccIP(m_local);
  setisChord(true);
  // initialize an empty fingerTable
  fingerTable = std::vector<std::tuple<uint32_t, Ipv4Address>>(FINGER_SIZE, std::tuple<uint32_t, Ipv4Address>{PennKeyHelper::CreateShaKey(unInitiazlied), unInitiazlied});
  setIthFingerEntery(0, m_local);
}

void PennChord::ringStateInvoke()
{
  printRingStateHelper();
  Ptr<Packet> packet = Create<Packet>();
  PennChordMessage message = PennChordMessage(PennChordMessage::LOOKUP_MSG, GetNextTransactionId());
  message.SetLookupMessage("ringstate", myKey, m_local, 0, Ipv4Address(), 0, Ipv4Address());
  packet->AddHeader(message);
  m_socket->SendTo(packet, 0, InetSocketAddress(succIP, m_appPort));
  // std::cout << "ringstate invoke next ip" << succIP << std::endl;
}

void PennChord::processRingStatePacket(PennChordMessage message)
{
  Ipv4Address originatorIP = message.GetLookupMessage().originatorIp;
  if (originatorIP == m_local) // if already a loop, no need to do anything
  {
    PRINT_LOG("End of Ring State");
    return;
  }
  printRingStateHelper();
  // forward the packet to its direct succ
  Ptr<Packet> packet = Create<Packet>();
  packet->AddHeader(message);
  m_socket->SendTo(packet, 0, InetSocketAddress(succIP, m_appPort));
}

void PennChord::sendStablizePacket()
{
  // send lookup packet with "stable_req" msg to succ
  Ptr<Packet>
      packet = Create<Packet>();
  PennChordMessage message = PennChordMessage(PennChordMessage::STABILIZE_MSG, GetNextTransactionId());
  message.SetStabilizeMessage("stable_req", myKey, 0, m_local, succIP, m_local, Ipv4Address());
  packet->AddHeader(message);
  m_socket->SendTo(packet, 0, InetSocketAddress(succIP, m_appPort));
}

void PennChord::processStablizeRequest(PennChordMessage message)
{
  // upon receiving the request, create a lookup packet with "stable_resp" and pred info and send back
  Ptr<Packet>
      packet = Create<Packet>();
  PennChordMessage stableResp = PennChordMessage(PennChordMessage::STABILIZE_MSG, GetNextTransactionId());
  // from the receiver side TO understand the signature , my predIp is the receiver's possible succIp
  stableResp.SetStabilizeMessage("stable_resp", 0, predKey, m_local, message.GetStabilizeMessage().originatorIp, Ipv4Address(), predIP);
  packet->AddHeader(stableResp);
  m_socket->SendTo(packet, 0, InetSocketAddress(message.GetStabilizeMessage().originatorIp, m_appPort));
}

void PennChord::processStablizeResp(
    PennChordMessage message)
{
  // upon receiving stablize resq, send nofity packet back
  Ipv4Address candidanteSuccIp = message.GetStabilizeMessage().successorIp;
  uint32_t candidanteSuccKey = message.GetStabilizeMessage().successorKey;
  if (!candidanteSuccKey)
  {
    sendNotifyPacket();
    return;
  }
  if ((myKey == succKey) || (myKey < succKey && myKey < candidanteSuccKey) || (myKey > succKey && (myKey < candidanteSuccKey || candidanteSuccKey < succKey)))
  {
    setSuccKey(candidanteSuccKey);
    setSuccIP(candidanteSuccIp);
    setIthFingerEntery(0, candidanteSuccIp);
  }
  sendNotifyPacket();
}

void PennChord::sendNotifyPacket()
{
  // send stabilize packet with "notify" msg to succ
  Ptr<Packet>
      packet = Create<Packet>();
  PennChordMessage notifyMessage = PennChordMessage(PennChordMessage::STABILIZE_MSG, GetNextTransactionId());
  notifyMessage.SetStabilizeMessage("notify", myKey, 0, m_local, succIP, m_local, Ipv4Address());
  packet->AddHeader(notifyMessage);
  m_socket->SendTo(packet, 0, InetSocketAddress(succIP, m_appPort));
}

void PennChord::processNotify(PennChordMessage message)
{

  Ipv4Address candidantePredIp = message.GetStabilizeMessage().predecessorIp;
  uint32_t candidantePredKey = message.GetStabilizeMessage().predecessorKey;
  if (!predKey || predKey == myKey || (predKey < myKey && predKey < candidantePredKey && candidantePredKey < myKey) ||
      (predKey > myKey && (candidantePredKey > predKey || candidantePredKey < myKey)))
  {
    setPredKey(candidantePredKey);
    setPredIP(candidantePredIp);
  }
}

void PennChord::setIthFingerEntery(int i, Ipv4Address addr)
{
  fingerTable[i] = std::tuple<uint32_t, Ipv4Address>{PennKeyHelper::CreateShaKey(addr), addr};
}

uint32_t PennChord::getIthEntryKey(int i)
{
  // note: m = 32 : bit of key
  return ((myKey + (uint32_t)pow(2, i)) % (uint32_t)(pow(2, 32)));
}

Ipv4Address PennChord::closest_preceding_finger(uint32_t key)
{
  for (int i = FINGER_SIZE - 1; i >= 0; i--)
  {
    if (std::get<1>(fingerTable[i]) != unInitiazlied)
    {
      std::tuple<uint32_t, Ipv4Address> currTuple = fingerTable[i];
      uint32_t currEntryKey = std::get<0>(currTuple);
      Ipv4Address currEntryIp = std::get<1>(currTuple);
      if ((currEntryKey > myKey && currEntryKey < key) || (myKey > key && currEntryKey < key))
      {
        return currEntryIp;
      }
    }
  }
  return m_local;
}

void PennChord::fixFinger()
{
  // only run fix finger if we have valid succIP
  // otherwise, there is no entry in the finger table yet
  if (succIP != unInitiazlied)
  {
    int fingerEntryIndex = 0;
    while (fingerEntryIndex < FINGER_SIZE)
    {
      uint32_t currEntryKey = getIthEntryKey(fingerEntryIndex);
      if (isClockWise(myKey, currEntryKey, succKey))
      {
        // if the entry is within me and my successor
        fingerTable[fingerEntryIndex] = std::tuple<uint32_t, Ipv4Address>{succKey, succIP};
        fingerEntryIndex++;
      }
      else
      {
        break;
      }
    }
    // start sending packte to take care of the remaining finger entries
    // this if check avoid edge case : the landmark node itself send packet to itself
    if (succIP != m_local)
    {
      while (fingerEntryIndex < FINGER_SIZE)
      {

        uint32_t currEntryKey = getIthEntryKey(fingerEntryIndex);
        // consult current finger table to figure out the next hop
        Ipv4Address destIp = closest_preceding_finger(currEntryKey);
        if (destIp != m_local && destIp != unInitiazlied)
        {
          // ready to send out a request
          Ptr<Packet>
              packet = Create<Packet>();
          PennChordMessage message = PennChordMessage(PennChordMessage::LOOKUP_MSG, GetNextTransactionId());
          message.SetLookupMessage("fix_req", myKey, m_local, 0, Ipv4Address(), currEntryKey, destIp);
          packet->AddHeader(message);
          m_socket->SendTo(packet, 0, InetSocketAddress(destIp, m_appPort));
        }
        fingerEntryIndex++;
      }
    }
  }
  m_fingerTimer.Schedule(m_fixFingerTimeout);
}

bool PennChord::isClockWise(uint32_t x, uint32_t y, uint32_t z)
{
  // case 1: strictly increasing x < y < z
  if (x < y && y < z)
  {
    return true;
  }
  // case 2: z is the smallest x < y, z < x
  if (z < x && x < y)
  {
    return true;
  }
  // case 3: y is the smallest and x is the largest:  y < z, x> z
  if (z < x && y < z)
  {
    return true;
  }
  return false;
}

void PennChord::processFixReqPacket(PennChordMessage lookupMessage)
{

  uint32_t targetKey = lookupMessage.GetLookupMessage().targetKey;
  // should we keep this??
  // if (myKey == succKey)
  // {
  //   Ipv4Address joiningNodeIP = lookupMessage.GetLookupMessage().originatorIp;
  //   Ptr<Packet> joiningRespPacket = Create<Packet>();
  //   PennChordMessage resp = PennChordMessage(PennChordMessage::LOOKUP_MSG, GetNextTransactionId());
  //   resp.SetLookupMessage("join_resp", myKey, m_local, myKey, m_local, joiningNodeKey, joiningNodeIP);
  //   joiningRespPacket->AddHeader(resp);
  //   m_socket->SendTo(joiningRespPacket, 0, InetSocketAddress(joiningNodeIP, m_appPort));
  // }

  if ((targetKey > myKey && targetKey < succKey) || (myKey > succKey && targetKey < succKey) || (myKey > succKey && targetKey > myKey)) // correct location
  {
    // send the succKey to joining node
    Ipv4Address fixReqSenderIP = lookupMessage.GetLookupMessage().originatorIp;
    Ptr<Packet> fixRespPacket = Create<Packet>();
    PennChordMessage resp = PennChordMessage(PennChordMessage::LOOKUP_MSG, GetNextTransactionId());
    resp.SetLookupMessage("fix_resp", myKey, m_local, succKey, succIP, targetKey, fixReqSenderIP);
    fixRespPacket->AddHeader(resp);
    m_socket->SendTo(fixRespPacket, 0, InetSocketAddress(fixReqSenderIP, m_appPort));
  }
  else
  // forward the packet to succ
  {
    Ipv4Address nextHopAddr = closest_preceding_finger(targetKey);
    if (nextHopAddr != m_local)
    {
      forwardingLookupMessage(lookupMessage, nextHopAddr);
    }
    else
    {
      forwardingLookupMessage(lookupMessage, findSuccIp());
    }
  }
}

void PennChord::processFixRespPacket(PennChordMessage message)
{
  uint32_t correspondingEntryKey = message.GetLookupMessage().targetKey;
  Ipv4Address succIP = message.GetLookupMessage().payloadIp;
  for (int index = 0; index < FINGER_SIZE; index++)
  {
    if (getIthEntryKey(index) == correspondingEntryKey)
    {
      setIthFingerEntery(index, succIP);
      break;
    }
  }
  // printFingerTable();
}

void PennChord::printFingerTable()
{
  {
    std::cout << "***************** Print Finger Table ***********************" << std::endl;
    for (int fingerEntryIndex = 0; fingerEntryIndex < FINGER_SIZE; fingerEntryIndex++)
    {
      std::cout << "currKey" << myKey << std::endl;
      std::cout << "m = " << fingerEntryIndex << " 2^m = " << pow(2, fingerEntryIndex) << " currentKey + 2**m= " << ((uint32_t)(myKey + pow(2, fingerEntryIndex)) % (uint32_t)(pow(2, FINGER_SIZE))) << " Key: " << std::get<0>(fingerTable[fingerEntryIndex]) << " Node #: " << m_addressNodeMap[std::get<1>(fingerTable[fingerEntryIndex])] << " SuccKey: " << PennKeyHelper::CreateShaKey(std::get<1>(fingerTable[fingerEntryIndex])) << std::endl;
    }
    std::cout << "***************** End of Print Finger Table ***********************" << std::endl;
  }
}

void PennChord::sendSearchReqPacket(uint32_t searchKey, uint32_t transactionId)
{
  // TODO: handle succIP == uninitialized
  if ((searchKey > myKey && searchKey < succKey) || (myKey > succKey && searchKey < succKey) || (myKey > succKey && searchKey > myKey)) // correct location
  {
    // the term key belongs to my succ
    m_searchSuccessCallback(succIP, "search", transactionId);
  }
  else
  // send the packet based on finger table
  {
    Ipv4Address nextHopAddr = closest_preceding_finger(searchKey);
    if (nextHopAddr == m_local)
    {
      nextHopAddr = succIP;
    }
    Ptr<Packet>
        packet = Create<Packet>();
    PennChordMessage message = PennChordMessage(PennChordMessage::LOOKUP_MSG, transactionId);
    message.SetLookupMessage("search_req", myKey, m_local, searchKey, Ipv4Address(), 0, nextHopAddr);
    packet->AddHeader(message);
    m_socket->SendTo(packet, 0, InetSocketAddress(nextHopAddr, m_appPort));
  }
}

void PennChord::processSearchReqPacket(PennChordMessage searchMessage)
{

  uint32_t searchKey = searchMessage.GetLookupMessage().payload;

  // if (myKey == succKey)
  // {
  //   Ipv4Address joiningNodeIP = lookupMessage.GetLookupMessage().originatorIp;
  //   Ptr<Packet> joiningRespPacket = Create<Packet>();
  //   PennChordMessage resp = PennChordMessage(PennChordMessage::LOOKUP_MSG, GetNextTransactionId());
  //   resp.SetLookupMessage("join_resp", myKey, m_local, myKey, m_local, joiningNodeKey, joiningNodeIP);
  //   joiningRespPacket->AddHeader(resp);
  //   m_socket->SendTo(joiningRespPacket, 0, InetSocketAddress(joiningNodeIP, m_appPort));
  // }
  // ? searchKey == myKey , ? <=
  if ((searchKey > myKey && searchKey < succKey) || (myKey > succKey && searchKey < succKey) || (myKey > succKey && searchKey > myKey)) // correct location
  {
    std::cout << "processSearchReqPacket searchKey: " << searchKey << std::endl;
    std::cout << "processSearchReqPacket myKey: " << myKey << std::endl;
    std::cout << "processSearchReqPacket succKey: " << succKey << std::endl;

    Ipv4Address originatorIP = searchMessage.GetLookupMessage().originatorIp;
    uint32_t transactionId = searchMessage.GetTransactionId();
    Ptr<Packet> searchRespPacket = Create<Packet>();
    PennChordMessage resp = PennChordMessage(PennChordMessage::LOOKUP_MSG, transactionId);
    resp.SetLookupMessage("search_resp", myKey, m_local, succKey, succIP, 0, originatorIP);
    searchRespPacket->AddHeader(resp);
    m_socket->SendTo(searchRespPacket, 0, InetSocketAddress(originatorIP, m_appPort));
  }
  else
  // forward the packet to succ
  {
    Ipv4Address nextHopAddr = closest_preceding_finger(searchKey);
    if (nextHopAddr != m_local)
    {
      forwardingLookupMessage(searchMessage, nextHopAddr);
    }
    else
    {
      forwardingLookupMessage(searchMessage, findSuccIp());
    }
  }
}

void PennChord::processSearchResp(PennChordMessage message)
{
  Ipv4Address resultIp = message.GetLookupMessage().payloadIp;
  uint32_t transactionId = message.GetTransactionId();
  m_searchSuccessCallback(resultIp, "search", transactionId);
}

void PennChord::SetSearchSuccessCallback(Callback<void, Ipv4Address, std::string, uint32_t> searchSuccessCallback)
{
  // this call back function should be the handler implemented in penn-search
  m_searchSuccessCallback = searchSuccessCallback;
}

// m2b
void PennChord::SetNodeLeaveCallback(Callback<void, Ipv4Address> nodeLeaveCallback)
{
  m_nodeLeaveCallback = nodeLeaveCallback;
}

void PennChord::SetNodeJoinCallback(Callback<void, Ipv4Address> nodeJoinCallback)
{
  m_nodeJoinCallback = nodeJoinCallback;
}