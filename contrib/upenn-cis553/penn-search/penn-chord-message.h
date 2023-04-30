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

#ifndef PENN_CHORD_MESSAGE_H
#define PENN_CHORD_MESSAGE_H

#include "ns3/header.h"
#include "ns3/ipv4-address.h"
#include "ns3/object.h"
#include "ns3/packet.h"

using namespace ns3;

#define IPV4_ADDRESS_SIZE 4

class PennChordMessage : public Header
{
public:
  PennChordMessage();
  virtual ~PennChordMessage();

  enum MessageType
  {
    PING_REQ = 1,
    PING_RSP = 2,
    // Define extra message types when needed
    LOOKUP_MSG = 3,
    STABILIZE_MSG = 4,
  };

  PennChordMessage(PennChordMessage::MessageType messageType, uint32_t transactionId);

  /**
   *  \brief Sets message type
   *  \param messageType message type
   */
  void SetMessageType(MessageType messageType);

  /**
   *  \returns message type
   */
  MessageType GetMessageType() const;

  /**
   *  \brief Sets Transaction Id
   *  \param transactionId Transaction Id of the request
   */
  void SetTransactionId(uint32_t transactionId);

  /**
   *  \returns Transaction Id
   */
  uint32_t GetTransactionId() const;

private:
  /**
   *  \cond
   */
  MessageType m_messageType;
  uint32_t m_transactionId;
  /**
   *  \endcond
   */
public:
  static TypeId GetTypeId(void);
  virtual TypeId GetInstanceTypeId(void) const;
  void Print(std::ostream &os) const;
  uint32_t GetSerializedSize(void) const;
  void Serialize(Buffer::Iterator start) const;
  uint32_t Deserialize(Buffer::Iterator start);

  struct PingReq
  {
    void Print(std::ostream &os) const;
    uint32_t GetSerializedSize(void) const;
    void Serialize(Buffer::Iterator &start) const;
    uint32_t Deserialize(Buffer::Iterator &start);
    // Payload
    std::string pingMessage;
  };

  struct PingRsp
  {
    void Print(std::ostream &os) const;
    uint32_t GetSerializedSize(void) const;
    void Serialize(Buffer::Iterator &start) const;
    uint32_t Deserialize(Buffer::Iterator &start);
    // Payload
    std::string pingMessage;
  };

  struct LookupMsg
  {
    void Print(std::ostream &os) const;
    uint32_t GetSerializedSize(void) const;
    void Serialize(Buffer::Iterator &start) const;
    uint32_t Deserialize(Buffer::Iterator &start);
    // Payload
    std::string lookupMessage; // indicate the functionality of the message

    uint32_t originatorKey; // used for printing when found the targetkey
    Ipv4Address originatorIp;

    uint32_t payload;      // in a reply to join request, i.e. 40 returns "58" (payload) to 50
    Ipv4Address payloadIp; // i.e. the ip address of node 58

    uint32_t targetKey;        // keyword we want to find, this field can be null if we use message to join
    Ipv4Address destinationIp; // the destination of the message, will be updated during packet travel
  };

  struct StabilizeMsg
  {
    void Print(std::ostream &os) const;
    uint32_t GetSerializedSize(void) const;
    void Serialize(Buffer::Iterator &start) const;
    uint32_t Deserialize(Buffer::Iterator &start);

    // Payload
    std::string stabilizeMessage; // indicate the functionality/purpose of sending this message
    // notify, stabilize request, stabilize reply
    uint32_t predecessorKey;   // should be filled in in stabilize request
    uint32_t successorKey;     // should be filled in in stabilize reply
    Ipv4Address originatorIp;  // sender Ip address
    Ipv4Address destinationIp; // recevier Ip address
    Ipv4Address predecessorIp; // predecessorIp (optional)
    Ipv4Address successorIp;   // successorIp (optional)
  };

private:
  struct
  {
    PingReq pingReq;
    PingRsp pingRsp;
    LookupMsg lookupMsg;
    StabilizeMsg stabilizeMsg;
  } m_message;

public:
  /**
   *  \returns PingReq Struct
   */
  PingReq GetPingReq();

  /**
   *  \brief Sets PingReq message params
   *  \param message Payload String
   */

  void SetPingReq(std::string message);

  /**
   * \returns PingRsp Struct
   */
  PingRsp GetPingRsp();
  /**
   *  \brief Sets PingRsp message params
   *  \param message Payload String
   */
  void SetPingRsp(std::string message);

  /**
   *  \ getter for lookupmessage
   */
  LookupMsg GetLookupMessage();

  /**
   *  \brief Sets lookup message params
   *  \param message Payload String
   */
  void SetLookupMessage(std::string message, uint32_t originatorKey, Ipv4Address originatorIp, uint32_t payload,
                        Ipv4Address payloadIp, uint32_t targetKey, Ipv4Address destinationIp);

  /**
   *  \ getter for Stabilizemessage
   */
  StabilizeMsg GetStabilizeMessage();

  /**
   *  \brief Sets Stabilize message params
   *  \param message Payload String
   */
  void SetStabilizeMessage(std::string message, uint32_t predecessorKey,
                           uint32_t successorKey,
                           Ipv4Address originatorIp,
                           Ipv4Address destinationIp, Ipv4Address predIp,
                           Ipv4Address succIp);

}; // class PennChordMessage

static inline std::ostream &operator<<(std::ostream &os, const PennChordMessage &message)
{
  message.Print(os);
  return os;
}

#endif