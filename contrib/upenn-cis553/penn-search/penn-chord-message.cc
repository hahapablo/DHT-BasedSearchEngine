/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
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

#include "ns3/penn-chord-message.h"
#include "ns3/log.h"

using namespace ns3;

NS_LOG_COMPONENT_DEFINE("PennChordMessage");
NS_OBJECT_ENSURE_REGISTERED(PennChordMessage);

PennChordMessage::PennChordMessage()
{
}

PennChordMessage::~PennChordMessage()
{
}

PennChordMessage::PennChordMessage(PennChordMessage::MessageType messageType, uint32_t transactionId)
{
  m_messageType = messageType;
  m_transactionId = transactionId;
}

TypeId
PennChordMessage::GetTypeId(void)
{
  static TypeId tid = TypeId("PennChordMessage")
                          .SetParent<Header>()
                          .AddConstructor<PennChordMessage>();
  return tid;
}

TypeId
PennChordMessage::GetInstanceTypeId(void) const
{
  return GetTypeId();
}

uint32_t
PennChordMessage::GetSerializedSize(void) const
{
  // size of messageType, transaction id
  uint32_t size = sizeof(uint8_t) + sizeof(uint32_t);
  switch (m_messageType)
  {
  case PING_REQ:
    size += m_message.pingReq.GetSerializedSize();
    break;
  case PING_RSP:
    size += m_message.pingRsp.GetSerializedSize();
    break;
  case LOOKUP_MSG:
    size += m_message.lookupMsg.GetSerializedSize();
    break;
  case STABILIZE_MSG:
    size += m_message.stabilizeMsg.GetSerializedSize();
    break;
  default:
    NS_ASSERT(false);
  }
  return size;
}

void PennChordMessage::Print(std::ostream &os) const
{
  os << "\n****PennChordMessage Dump****\n";
  os << "messageType: " << m_messageType << "\n";
  os << "transactionId: " << m_transactionId << "\n";
  os << "PAYLOAD:: \n";

  switch (m_messageType)
  {
  case PING_REQ:
    m_message.pingReq.Print(os);
    break;
  case PING_RSP:
    m_message.pingRsp.Print(os);
    break;
  case LOOKUP_MSG:
    m_message.lookupMsg.Print(os);
    break;
  case STABILIZE_MSG:
    m_message.stabilizeMsg.Print(os);
  default:
    break;
  }
  os << "\n****END OF MESSAGE****\n";
}

void PennChordMessage::Serialize(Buffer::Iterator start) const
{
  Buffer::Iterator i = start;
  i.WriteU8(m_messageType);
  i.WriteHtonU32(m_transactionId);

  switch (m_messageType)
  {
  case PING_REQ:
    m_message.pingReq.Serialize(i);
    break;
  case PING_RSP:
    m_message.pingRsp.Serialize(i);
    break;
  case LOOKUP_MSG:
    m_message.lookupMsg.Serialize(i);
    break;
  case STABILIZE_MSG:
    m_message.stabilizeMsg.Serialize(i);
    break;
  default:
    NS_ASSERT(false);
  }
}

uint32_t
PennChordMessage::Deserialize(Buffer::Iterator start)
{
  uint32_t size;
  Buffer::Iterator i = start;
  m_messageType = (MessageType)i.ReadU8();
  m_transactionId = i.ReadNtohU32();

  size = sizeof(uint8_t) + sizeof(uint32_t);

  switch (m_messageType)
  {
  case PING_REQ:
    size += m_message.pingReq.Deserialize(i);
    break;
  case PING_RSP:
    size += m_message.pingRsp.Deserialize(i);
    break;
  case LOOKUP_MSG:
    m_message.lookupMsg.Deserialize(i);
    break;
  case STABILIZE_MSG:
    m_message.stabilizeMsg.Deserialize(i);
    break;
  default:
    NS_ASSERT(false);
  }
  return size;
}

/* PING_REQ */

uint32_t
PennChordMessage::PingReq::GetSerializedSize(void) const
{
  uint32_t size;
  size = sizeof(uint16_t) + pingMessage.length();
  return size;
}

void PennChordMessage::PingReq::Print(std::ostream &os) const
{
  os << "PingReq:: Message: " << pingMessage << "\n";
}

void PennChordMessage::PingReq::Serialize(Buffer::Iterator &start) const
{
  start.WriteU16(pingMessage.length());
  start.Write((uint8_t *)(const_cast<char *>(pingMessage.c_str())), pingMessage.length());
}

uint32_t
PennChordMessage::PingReq::Deserialize(Buffer::Iterator &start)
{
  uint16_t length = start.ReadU16();
  char *str = (char *)malloc(length);
  start.Read((uint8_t *)str, length);
  pingMessage = std::string(str, length);
  free(str);
  return PingReq::GetSerializedSize();
}

void PennChordMessage::SetPingReq(std::string pingMessage)
{
  if (m_messageType == 0)
  {
    m_messageType = PING_REQ;
  }
  else
  {
    NS_ASSERT(m_messageType == PING_REQ);
  }
  m_message.pingReq.pingMessage = pingMessage;
}

PennChordMessage::PingReq
PennChordMessage::GetPingReq()
{
  return m_message.pingReq;
}

/* PING_RSP */

uint32_t
PennChordMessage::PingRsp::GetSerializedSize(void) const
{
  uint32_t size;
  size = sizeof(uint16_t) + pingMessage.length();
  return size;
}

void PennChordMessage::PingRsp::Print(std::ostream &os) const
{
  os << "PingReq:: Message: " << pingMessage << "\n";
}

void PennChordMessage::PingRsp::Serialize(Buffer::Iterator &start) const
{
  start.WriteU16(pingMessage.length());
  start.Write((uint8_t *)(const_cast<char *>(pingMessage.c_str())), pingMessage.length());
}

uint32_t
PennChordMessage::PingRsp::Deserialize(Buffer::Iterator &start)
{
  uint16_t length = start.ReadU16();
  char *str = (char *)malloc(length);
  start.Read((uint8_t *)str, length);
  pingMessage = std::string(str, length);
  free(str);
  return PingRsp::GetSerializedSize();
}

/* LOOKUP_MSG*/
uint32_t
PennChordMessage::LookupMsg::GetSerializedSize(void) const
{
  uint32_t size;
  // lookupmessage # of chars
  // originator key + originator IP +  target key + destination IP
  size = sizeof(uint16_t) + lookupMessage.length() + sizeof(uint32_t) * 3 + IPV4_ADDRESS_SIZE * 3;
  return size;
}
void PennChordMessage::LookupMsg::Print(std::ostream &os) const
{
  os << "LoookupMsg:: Message: " << lookupMessage << "\n";
}

void PennChordMessage::LookupMsg::Serialize(Buffer::Iterator &start) const
{
  // first 16 bit stands for the length of loookup message
  start.WriteU16(lookupMessage.length());
  // write lookup message string
  start.Write((uint8_t *)(const_cast<char *>(lookupMessage.c_str())), lookupMessage.length());
  start.WriteHtonU32(originatorKey);
  start.WriteHtonU32(originatorIp.Get());

  start.WriteHtonU32(payload);
  start.WriteHtonU32(payloadIp.Get());

  start.WriteHtonU32(targetKey);
  start.WriteHtonU32(destinationIp.Get());
}

uint32_t
PennChordMessage::LookupMsg::Deserialize(Buffer::Iterator &start)
{

  uint16_t length = start.ReadU16();
  char *str = (char *)malloc(length);
  start.Read((uint8_t *)str, length);
  lookupMessage = std::string(str, length);
  free(str);

  originatorKey = start.ReadNtohU32();
  originatorIp = Ipv4Address(start.ReadNtohU32());

  payload = start.ReadNtohU32();
  payloadIp = Ipv4Address(start.ReadNtohU32());

  targetKey = start.ReadNtohU32();
  destinationIp = Ipv4Address(start.ReadNtohU32());

  return LookupMsg::GetSerializedSize();
}
/* end of LookupMsg */

/* Stabilize_MSG*/
uint32_t
PennChordMessage::StabilizeMsg::GetSerializedSize(void) const
{
  uint32_t size;
  // stabilize message # of chars
  // 2 IPs and 2 uint32_t
  size = sizeof(uint16_t) + stabilizeMessage.length() + sizeof(uint32_t) * 2 + IPV4_ADDRESS_SIZE * 4;
  return size;
}
void PennChordMessage::StabilizeMsg::Print(std::ostream &os) const
{
  os << "StabilizeMsg:: Message: " << stabilizeMessage << "\n";
}

void PennChordMessage::StabilizeMsg::Serialize(Buffer::Iterator &start) const
{
  // first 16 bit stands for the length of stabilize message
  start.WriteU16(stabilizeMessage.length());
  // // write stabilize message string
  start.Write((uint8_t *)(const_cast<char *>(stabilizeMessage.c_str())), stabilizeMessage.length());
  start.WriteHtonU32(predecessorKey);
  start.WriteHtonU32(successorKey);
  start.WriteHtonU32(originatorIp.Get());
  start.WriteHtonU32(destinationIp.Get());
  start.WriteHtonU32(predecessorIp.Get());
  start.WriteHtonU32(successorIp.Get());
}

uint32_t
PennChordMessage::StabilizeMsg::Deserialize(Buffer::Iterator &start)
{

  uint16_t length = start.ReadU16();
  char *str = (char *)malloc(length);
  start.Read((uint8_t *)str, length);
  stabilizeMessage = std::string(str, length);
  free(str);

  predecessorKey = start.ReadNtohU32();
  successorKey = start.ReadNtohU32();
  originatorIp = Ipv4Address(start.ReadNtohU32());
  destinationIp = Ipv4Address(start.ReadNtohU32());
  predecessorIp = Ipv4Address(start.ReadNtohU32());
  successorIp = Ipv4Address(start.ReadNtohU32());

  return StabilizeMsg::GetSerializedSize();
}
/* end of StabilizeMsg */

void PennChordMessage::SetPingRsp(std::string pingMessage)
{
  if (m_messageType == 0)
  {
    m_messageType = PING_RSP;
  }
  else
  {
    NS_ASSERT(m_messageType == PING_RSP);
  }
  m_message.pingRsp.pingMessage = pingMessage;
}

PennChordMessage::PingRsp
PennChordMessage::GetPingRsp()
{
  return m_message.pingRsp;
}

// getter and setter for lookup message //

void PennChordMessage::SetLookupMessage(std::string lookupMessage, uint32_t originatorKey, Ipv4Address originatorIp, uint32_t payload,
                                        Ipv4Address payloadIp, uint32_t targetKey, Ipv4Address destinationIp)
{
  if (m_messageType == 0)
  {
    m_messageType = PING_RSP;
  }
  else
  {
    NS_ASSERT(m_messageType == LOOKUP_MSG);
  }
  m_message.lookupMsg.lookupMessage = lookupMessage;
  m_message.lookupMsg.originatorKey = originatorKey;
  m_message.lookupMsg.originatorIp = originatorIp;
  m_message.lookupMsg.payload = payload,
  m_message.lookupMsg.payloadIp = payloadIp,
  m_message.lookupMsg.targetKey = targetKey;
  m_message.lookupMsg.destinationIp = destinationIp;
}

PennChordMessage::LookupMsg
PennChordMessage::GetLookupMessage()
{
  return m_message.lookupMsg;
}
/* */

// getter and setter for stabilize message //

void PennChordMessage::SetStabilizeMessage(std::string stabilizeMessage, uint32_t predecessorKey,
                                           uint32_t successorKey,
                                           Ipv4Address originatorIp,
                                           Ipv4Address destinationIp, Ipv4Address predIp,
                                           Ipv4Address succIp)
{
  if (m_messageType == 0)
  {
    m_messageType = PING_RSP;
  }
  else
  {
    NS_ASSERT(m_messageType == STABILIZE_MSG);
  }
  m_message.stabilizeMsg.stabilizeMessage = stabilizeMessage;

  m_message.stabilizeMsg.predecessorKey = predecessorKey;

  m_message.stabilizeMsg.successorKey = successorKey;

  m_message.stabilizeMsg.originatorIp = originatorIp;

  m_message.stabilizeMsg.destinationIp = destinationIp;

  m_message.stabilizeMsg.predecessorIp = predIp;

  m_message.stabilizeMsg.successorIp = succIp;
}

PennChordMessage::StabilizeMsg
PennChordMessage::GetStabilizeMessage()
{
  return m_message.stabilizeMsg;
}

/* */

void PennChordMessage::SetMessageType(MessageType messageType)
{
  m_messageType = messageType;
}

PennChordMessage::MessageType
PennChordMessage::GetMessageType() const
{
  return m_messageType;
}

void PennChordMessage::SetTransactionId(uint32_t transactionId)
{
  m_transactionId = transactionId;
}

uint32_t
PennChordMessage::GetTransactionId(void) const
{
  return m_transactionId;
}