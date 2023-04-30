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

#ifndef PENN_CHORD_H
#define PENN_CHORD_H
#define FINGER_SIZE 32

#include "ns3/penn-application.h"
#include "ns3/penn-chord-message.h"
#include "ns3/ping-request.h"
#include <openssl/sha.h>

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
#include "penn-key-helper.h"

using namespace ns3;

class PennChord : public PennApplication
{
public:
  static TypeId GetTypeId(void);
  PennChord();
  virtual ~PennChord();

  void SendPing(Ipv4Address destAddress, std::string pingMessage);
  void RecvMessage(Ptr<Socket> socket);
  void ProcessPingReq(PennChordMessage message, Ipv4Address sourceAddress, uint16_t sourcePort);
  void ProcessPingRsp(PennChordMessage message, Ipv4Address sourceAddress, uint16_t sourcePort);
  void AuditPings();
  uint32_t GetNextTransactionId();
  void StopChord();

  // Callback with Application Layer (add more when required)
  void SetPingSuccessCallback(Callback<void, Ipv4Address, std::string> pingSuccessFn);
  void SetPingFailureCallback(Callback<void, Ipv4Address, std::string> pingFailureFn);
  void SetPingRecvCallback(Callback<void, Ipv4Address, std::string> pingRecvFn);
  // m2
  void SetSearchSuccessCallback(Callback<void, Ipv4Address, std::string, uint32_t> searchSuccessCallback);
  // m2b
  void SetNodeJoinCallback(Callback<void, Ipv4Address> nodeJoinCallback);
  void SetNodeLeaveCallback(Callback<void, Ipv4Address> nodeLeaveCallback);
  
  // From PennApplication
  virtual void ProcessCommand(std::vector<std::string> tokens);

  // *** CHORD ***
  // Setters
  void setOwnKey();
  void setPredKey(uint32_t pred);
  void setPredIP(Ipv4Address ip);
  void setSuccKey(uint32_t succ);
  void setSuccIP(Ipv4Address ip);
  void setisChord(bool isChord);

  // helper functions
  uint32_t findSucc();
  Ipv4Address findSuccIp();
  void printRingStateHelper();
  void forwardingLookupMessage(PennChordMessage lookupMessage, Ipv4Address destination);
  void processLookupMsg(PennChordMessage message);
  void processStabilizeMsg(PennChordMessage message);

  // initialization
  void joiningNodeInitialization(std::string joiningViaNodeNum);
  void landmarkNodeInitialization();

  // join and lookup process functions
  void processNodeJoinPacket(PennChordMessage message);
  void processJoiningRespPacket(PennChordMessage message);
  void ringStateInvoke();
  void processRingStatePacket(PennChordMessage message);

  // stable and notify process functions
  void sendStablizePacket();
  void sendNotifyPacket();
  void processStablizeRequest(PennChordMessage message);
  void processStablizeResp(PennChordMessage message);
  void processNotify(PennChordMessage message);

  // leave process functions
  void processLeaveOfSucc(PennChordMessage message);
  void processLeaveOfPred(PennChordMessage message);

  // finger table
  void fixFinger();
  // determine if y is between x and z (key in terms of clockwise)
  bool isClockWise(uint32_t x, uint32_t y, uint32_t z);
  void processFixReqPacket(PennChordMessage message);
  void processFixRespPacket(PennChordMessage message);
  void printFingerTable();

  // integrate with penn-search
  void processSearchReqPacket(PennChordMessage searchMessage);
  void processSearchResp(PennChordMessage message);
  void sendSearchReqPacket(uint32_t searchKey, uint32_t transactionId);

  // 1 <= i <= 32
  void setIthFingerEntery(int i, Ipv4Address addr);
  // given ith entry, calculate the corresponding key
  uint32_t getIthEntryKey(int i);
  Ipv4Address closest_preceding_finger(uint32_t key);

  // set timer
  void SetStableTimer();

protected:
  virtual void DoDispose();

private:
  virtual void StartApplication(void);
  virtual void StopApplication(void);

  uint32_t m_currentTransactionId;
  Ptr<Socket> m_socket;
  Time m_pingTimeout;
  Time m_stableTimeout;
  Time m_fixFingerTimeout;
  uint16_t m_appPort;
  // Timers
  Timer m_auditPingsTimer;
  Timer m_stableTimer;
  Timer m_fingerTimer;
  // Ping tracker
  std::map<uint32_t, Ptr<PingRequest>> m_pingTracker;
  // Callbacks
  Callback<void, Ipv4Address, std::string> m_pingSuccessFn;
  Callback<void, Ipv4Address, std::string> m_pingFailureFn;
  Callback<void, Ipv4Address, std::string> m_pingRecvFn;
  Callback<void, Ipv4Address, std::string, uint32_t> m_searchSuccessCallback;
  // m2b
  Callback<void, Ipv4Address> m_nodeLeaveCallback;
  Callback<void, Ipv4Address> m_nodeJoinCallback;

  // chord
  std::uint32_t myKey;
  std::uint32_t predKey;
  std::uint32_t succKey;
  Ipv4Address succIP; // get via joining and update via stablization
  Ipv4Address predIP; // get via stablization
  bool isChord = false;
  Ipv4Address unInitiazlied;
  // finger table
  // index, node key, ip address
  std::vector<std::tuple<uint32_t, Ipv4Address>> fingerTable;
  // std::map<uint32_t, std::tuple<uint32_t, Ipv4Address>> fingerTable;
  // std::map<uint32_t, Ipv4Address> fingerTable;
};

#endif
