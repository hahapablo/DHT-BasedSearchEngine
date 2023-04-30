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

#include "ns3/penn-search-message.h"
#include "ns3/log.h"

using namespace ns3;

NS_LOG_COMPONENT_DEFINE ("PennSearchMessage");
NS_OBJECT_ENSURE_REGISTERED (PennSearchMessage);

PennSearchMessage::PennSearchMessage ()
{
}

PennSearchMessage::~PennSearchMessage ()
{
}

PennSearchMessage::PennSearchMessage (PennSearchMessage::MessageType messageType, uint32_t transactionId)
{
  m_messageType = messageType;
  m_transactionId = transactionId;
}

TypeId 
PennSearchMessage::GetTypeId (void)
{
  static TypeId tid = TypeId ("PennSearchMessage")
    .SetParent<Header> ()
    .AddConstructor<PennSearchMessage> ()
  ;
  return tid;
}

TypeId
PennSearchMessage::GetInstanceTypeId (void) const
{
  return GetTypeId ();
}


uint32_t
PennSearchMessage::GetSerializedSize (void) const
{
  // size of messageType, transaction id
  uint32_t size = sizeof (uint8_t) + sizeof (uint32_t);
  switch (m_messageType)
    {
      case PING_REQ:
        size += m_message.pingReq.GetSerializedSize ();
        break;
      case PING_RSP:
        size += m_message.pingRsp.GetSerializedSize ();
        break;
      case INVERTED_MSG:
        size += m_message.invertedMsg.GetSerializedSize();
        break; 
      default:
        NS_ASSERT (false);
    }
  return size;
}

void
PennSearchMessage::Print (std::ostream &os) const
{
  os << "\n****PennSearchMessage Dump****\n" ;
  os << "messageType: " << m_messageType << "\n";
  os << "transactionId: " << m_transactionId << "\n";
  os << "PAYLOAD:: \n";
  
  switch (m_messageType)
    {
      case PING_REQ:
        m_message.pingReq.Print (os);
        break;
      case PING_RSP:
        m_message.pingRsp.Print (os);
        break;
      case INVERTED_MSG:
        m_message.invertedMsg.Print(os);
        break;
      default:
        break;  
    }
  os << "\n****END OF MESSAGE****\n";
}

void
PennSearchMessage::Serialize (Buffer::Iterator start) const
{
  Buffer::Iterator i = start;
  i.WriteU8 (m_messageType);
  i.WriteHtonU32 (m_transactionId);

  switch (m_messageType)
    {
      case PING_REQ:
        m_message.pingReq.Serialize (i);
        break;
      case PING_RSP:
        m_message.pingRsp.Serialize (i);
        break;
      case INVERTED_MSG:
        m_message.invertedMsg.Serialize(i);
        break;
      default:
        NS_ASSERT (false);   
    }
}

uint32_t 
PennSearchMessage::Deserialize (Buffer::Iterator start)
{
  uint32_t size;
  Buffer::Iterator i = start;
  m_messageType = (MessageType) i.ReadU8 ();
  m_transactionId = i.ReadNtohU32 ();

  size = sizeof (uint8_t) + sizeof (uint32_t);

  switch (m_messageType)
    {
      case PING_REQ:
        size += m_message.pingReq.Deserialize (i);
        break;
      case PING_RSP:
        size += m_message.pingRsp.Deserialize (i);
        break;
      case INVERTED_MSG:
        m_message.invertedMsg.Deserialize(i);
        break;
      default:
        NS_ASSERT (false);
    }
  return size;
}

/* PING_REQ */

uint32_t 
PennSearchMessage::PingReq::GetSerializedSize (void) const
{
  uint32_t size;
  size = sizeof(uint16_t) + pingMessage.length();
  return size;
}

void
PennSearchMessage::PingReq::Print (std::ostream &os) const
{
  os << "PingReq:: Message: " << pingMessage << "\n";
}

void
PennSearchMessage::PingReq::Serialize (Buffer::Iterator &start) const
{
  start.WriteU16 (pingMessage.length ());
  start.Write ((uint8_t *) (const_cast<char*> (pingMessage.c_str())), pingMessage.length());
}

uint32_t
PennSearchMessage::PingReq::Deserialize (Buffer::Iterator &start)
{  
  uint16_t length = start.ReadU16 ();
  char* str = (char*) malloc (length);
  start.Read ((uint8_t*)str, length);
  pingMessage = std::string (str, length);
  free (str);
  return PingReq::GetSerializedSize ();
}

void
PennSearchMessage::SetPingReq (std::string pingMessage)
{
  if (m_messageType == 0)
    {
      m_messageType = PING_REQ;
    }
  else
    {
      NS_ASSERT (m_messageType == PING_REQ);
    }
  m_message.pingReq.pingMessage = pingMessage;
}

PennSearchMessage::PingReq
PennSearchMessage::GetPingReq ()
{
  return m_message.pingReq;
}

/* PING_RSP */

uint32_t 
PennSearchMessage::PingRsp::GetSerializedSize (void) const
{
  uint32_t size;
  size = sizeof(uint16_t) + pingMessage.length();
  return size;
}

void
PennSearchMessage::PingRsp::Print (std::ostream &os) const
{
  os << "PingReq:: Message: " << pingMessage << "\n";
}

void
PennSearchMessage::PingRsp::Serialize (Buffer::Iterator &start) const
{
  start.WriteU16 (pingMessage.length ());
  start.Write ((uint8_t *) (const_cast<char*> (pingMessage.c_str())), pingMessage.length());
}

uint32_t
PennSearchMessage::PingRsp::Deserialize (Buffer::Iterator &start)
{  
  uint16_t length = start.ReadU16 ();
  char* str = (char*) malloc (length);
  start.Read ((uint8_t*)str, length);
  pingMessage = std::string (str, length);
  free (str);
  return PingRsp::GetSerializedSize ();
}

void
PennSearchMessage::SetPingRsp (std::string pingMessage)
{
  if (m_messageType == 0)
    {
      m_messageType = PING_RSP;
    }
  else
    {
      NS_ASSERT (m_messageType == PING_RSP);
    }
  m_message.pingRsp.pingMessage = pingMessage;
}

PennSearchMessage::PingRsp
PennSearchMessage::GetPingRsp ()
{
  return m_message.pingRsp;
}

// m2
/* Inverted Msg
  // Payload
      std::string invertedMessage; // subtype, indicate the functionality/purpose of sending this 
                                    // message: store, search
      std::string keyword;
      std::set<std::string> docIDs;
      
      uint32_t hopCount; // keep track of internal chord hop numbers of this lookup
      
      Ipv4Address originatorIp; 
      Ipv4Address destinationIp;

      // hash keys
      uint32_t termKey;
      uint32_t originatorKey;
      uint32_t destinationKey;
*/
uint32_t
PennSearchMessage::InvertedMsg::GetSerializedSize(void) const
{
  uint32_t size = 0;
  /*
        // Payload
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
  */

  size = sizeof(uint16_t) + invertedMessage.length() + 2 * IPV4_ADDRESS_SIZE + 4 * sizeof(uint32_t);
  
  // size of vector
  size += sizeof(uint16_t);
  // iterate the vec
  for (std::string term : keywords) {
    // size of term
    size += sizeof(uint16_t);
    // length of keyword
    size += term.length();
  }


  size += sizeof(uint16_t);
  // iterate the set, and add each string's # of chars + actual string
  for (std::string doc : docIDs) {
    size += sizeof(uint16_t);
    size += doc.length();
  }
  
  return size;
}
void PennSearchMessage::InvertedMsg::Print(std::ostream &os) const
{
  os << "InvertedMsg:: Message: " << invertedMessage << "\n";
}

void PennSearchMessage::InvertedMsg::Serialize(Buffer::Iterator &start) const
{
  // first 16 bit stands for the length of inverted message
  start.WriteU16(invertedMessage.length());
  // write inverted message string
  start.Write((uint8_t *)(const_cast<char *>(invertedMessage.c_str())), invertedMessage.length());
  

  // size of keywords
  start.WriteU16(keywords.size());
  // write each term in keywords
  for (std::string term : keywords) {
    start.WriteU16(term.size());
    start.Write((uint8_t *)(const_cast<char *>(term.c_str())), term.length());
  
  }

  // size of set
  start.WriteU16(docIDs.size());
  // write each docIdstring in docIds set
  for (std::string doc : docIDs) {
    start.WriteU16(doc.length());
    start.Write((uint8_t *)(const_cast<char *>(doc.c_str())), doc.length());
  }
  
  // write others
  start.WriteHtonU32(hopCount);
  start.WriteHtonU32(originatorIp.Get());
  start.WriteHtonU32(destinationIp.Get());
  start.WriteHtonU32(termKey);
  start.WriteHtonU32(originatorKey);
  start.WriteHtonU32(destinationKey);
}

uint32_t
PennSearchMessage::InvertedMsg::Deserialize(Buffer::Iterator &start)
{

  // inverted message
  uint16_t length = start.ReadU16();
  char *str = (char *)malloc(length);
  start.Read((uint8_t *)str, length);
  invertedMessage = std::string(str, length);
  free(str);

  // keywords
  uint16_t vcecSize = start.ReadU16();

  for (size_t i = 0; i < vcecSize; ++i) {
    length = start.ReadU16();
    
    char *str2 = (char *)malloc(length);
    start.Read((uint8_t *)str2, length);
    keywords.push_back(std::string(str2, length));
    
    free(str2);
  }


  // size of the docIDs set
  uint16_t setSize = start.ReadU16();
  // iterate each docId
  for (size_t i = 0; i < setSize; ++i) {
    // length
    length = start.ReadU16();
    // then actual string
    char *str = (char *)malloc(length);
    start.Read((uint8_t *)str, length);
    docIDs.insert(std::string(str, length));
    free(str);
  }

  // others
  hopCount = start.ReadNtohU32();
  originatorIp = Ipv4Address(start.ReadNtohU32());
  destinationIp = Ipv4Address(start.ReadNtohU32());
  termKey = start.ReadNtohU32();
  originatorKey = start.ReadNtohU32();
  destinationKey = start.ReadNtohU32();

  return InvertedMsg::GetSerializedSize();
}
/* end of Inverted Msg */

/* */

// getter and setter for inverted message //
PennSearchMessage::InvertedMsg PennSearchMessage::GetInvertedMessage() {
  return m_message.invertedMsg;;
}


void PennSearchMessage::SetInvertedMessage(std::string invertedMessage, std::vector<std::string> keywords, std::set<std::string> docIDs,
                      uint32_t hopCount, Ipv4Address originatorIp, Ipv4Address destinationIp, uint32_t termKey, 
                      uint32_t originatorKey, uint32_t destinationKey) {

  if (m_messageType == 0)
  {
    m_messageType = PING_RSP;
  }
  else
  {
    NS_ASSERT(m_messageType == INVERTED_MSG);
  }
  m_message.invertedMsg.invertedMessage = invertedMessage;

  m_message.invertedMsg.keywords = keywords;

  m_message.invertedMsg.docIDs = docIDs;

  m_message.invertedMsg.hopCount = hopCount;

  m_message.invertedMsg.originatorIp = originatorIp;

  m_message.invertedMsg.destinationIp = destinationIp;

  m_message.invertedMsg.termKey = termKey;

  m_message.invertedMsg.originatorKey = originatorKey;

  m_message.invertedMsg.destinationKey = destinationKey;


}

/* */

//
//
//

void
PennSearchMessage::SetMessageType (MessageType messageType)
{
  m_messageType = messageType;
}

PennSearchMessage::MessageType
PennSearchMessage::GetMessageType () const
{
  return m_messageType;
}

void
PennSearchMessage::SetTransactionId (uint32_t transactionId)
{
  m_transactionId = transactionId;
}

uint32_t 
PennSearchMessage::GetTransactionId (void) const
{
  return m_transactionId;
}

