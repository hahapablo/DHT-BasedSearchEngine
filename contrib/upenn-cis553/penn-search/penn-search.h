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

#ifndef PENN_SEARCH_H
#define PENN_SEARCH_H

#include "ns3/penn-application.h"
#include "ns3/penn-chord.h"
#include "ns3/penn-search-message.h"
#include "ns3/ping-request.h"

#include "ns3/ipv4-address.h"
#include <map>
#include <set>
#include <vector>
#include <string>
#include "ns3/socket.h"
#include "ns3/nstime.h"
#include "ns3/timer.h"
#include "ns3/uinteger.h"
#include "ns3/boolean.h"

#include <unordered_map>

using namespace ns3;

class PennSearch : public PennApplication
{
  public:
    static TypeId GetTypeId (void);
    PennSearch ();
    virtual ~PennSearch ();

    void SendPing (std::string nodeId, std::string pingMessage);
    void SendPennSearchPing (Ipv4Address destAddress, std::string pingMessage);
    void RecvMessage (Ptr<Socket> socket);
    void ProcessPingReq (PennSearchMessage message, Ipv4Address sourceAddress, uint16_t sourcePort);
    void ProcessPingRsp (PennSearchMessage message, Ipv4Address sourceAddress, uint16_t sourcePort);
    void AuditPings ();
    uint32_t GetNextTransactionId ();

    // m2
    void ProcessInvertedMsg(PennSearchMessage message);
    // m2b
    void processNodeJoinReq(PennSearchMessage message);

    // Chord Callbacks
    void HandleChordPingSuccess (Ipv4Address destAddress, std::string message);
    void HandleChordPingFailure (Ipv4Address destAddress, std::string message);
    void HandleChordPingRecv (Ipv4Address destAddress, std::string message);
    // m2
    // std::string 
    // uint32_t transactionID
    void HandleNodeLookup (Ipv4Address destAddress, std::string message, uint32_t transactionID);

    // m2b
    void HandleNodeJoin(Ipv4Address destAddress);
    void HandleNodeLeave(Ipv4Address destAddress);

    // From PennApplication
    virtual void ProcessCommand (std::vector<std::string> tokens);
    // From PennLog
    virtual void SetTrafficVerbose (bool on);
    virtual void SetErrorVerbose (bool on);
    virtual void SetDebugVerbose (bool on);
    virtual void SetStatusVerbose (bool on);
    virtual void SetChordVerbose (bool on);
    virtual void SetSearchVerbose (bool on);

    // m2 business logic related functions
    void processInvertedStore(PennSearchMessage message);
    void initInvertedSearch(PennSearchMessage message);
    void processInvertedSearch(PennSearchMessage message);
    void processInvertedSearchResult(PennSearchMessage message);
    // helper
    void splitStr(std::string const &line, const char delimeter, std::vector<std::string> &vec);
    std::set<std::string> setIntersection(std::set<std::string> set1, std::set<std::string> set2);
    // publish & store
    void constructInvertedList(std::string fileName);
    // search
    // void constructSearchReq(Ipv4Address destAddress, std::string queryConcat);
    void constructInitSearchReq(Ipv4Address destAddress, std::vector<std::string> queryTerms);
  


    




  protected:
    virtual void DoDispose ();
    
  private:
    virtual void StartApplication (void);
    virtual void StopApplication (void);

    Ptr<PennChord> m_chord;
    uint32_t m_currentTransactionId;
    Ptr<Socket> m_socket;
    Time m_pingTimeout;
    uint16_t m_appPort, m_chordPort;
    // Timers
    Timer m_auditPingsTimer;
    // Ping tracker
    std::map<uint32_t, Ptr<PingRequest> > m_pingTracker;

    // m2
    // publish parsed read file data
    std::unordered_map<std::string, std::set<std::string> > m_invertLists;

    // data structure to store the key(keyword/term) and values(docIDs) whose key is hashed to this node
    std::unordered_map<std::string, std::set<std::string> > m_searchDatabase;

    // lookup chord node address
    Ipv4Address m_lookupNodeIp;

    // variables to keep track of lookup number & hop number
    uint32_t lookupNumber = 0;
    uint32_t hopNumber = 0;

    // to keep track of storing and searching jobs with transactionID
    struct SearchInfo {

      // same as payload of INVERTED_MSG
      std::string invertedMessage; // subtype, indicate the functionality/purpose of sending this 
                                    // message: store, search, etc.
      std::vector<std::string> keywords; // or terms, making it a vec so easier to handle search terms
      std::set<std::string> docIDs;
      
      uint32_t hopCount; // keep track of internal chord hop numbers of this lookup
      
      Ipv4Address originatorIp; 
      Ipv4Address destinationIp;

      // hash keys
      uint32_t termKey;
      uint32_t originatorKey;
      uint32_t destinationKey;
    };

    // store: txID maps to term whose docIDS set is To be Sent and store to the destIP while handling callback 
    // search: txID maps to related SearchInfo
    std::unordered_map<uint32_t, std::string> m_storeJobs;
    std::unordered_map<uint32_t, SearchInfo> m_searchJobs;




};
#endif


