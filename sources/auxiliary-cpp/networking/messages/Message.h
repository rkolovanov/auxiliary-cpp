/**
 * \proj Библиотека вспомогательных компонентов С++ (auxiliary-cpp)
 * \file Заголовочный файл Message.h
 * \brief Класс Message
 *
 * Copyright (c) 2022 Rodion Kolovanov
 */

#ifndef SOURCES_AUXILIARY_CPP_NETWORKING_MESSAGES_MESSAGE_H
#define SOURCES_AUXILIARY_CPP_NETWORKING_MESSAGES_MESSAGE_H

#include <auxiliary-cpp/common/Concepts.h>
#include <cstdint>
#include <iostream>
#include <vector>

namespace
{
  const uint8_t UnsignedZero = static_cast<uint8_t>(0);
} // anonymous namespace

namespace Auxiliary::Networking
{
#pragma pack(push, 1)

  struct MessageHeader
  {
  private:
    uint8_t marker[4] = {UnsignedZero, UnsignedZero, UnsignedZero, UnsignedZero};
    uint32_t type = UnsignedZero;
    uint32_t size = UnsignedZero;
  }; // struct MessageHeader

#pragma pack(pop)

  class Message
  {
  public:
    template<typename T>
    requires Auxiliary::Common::UnsignedIntegerConvertable<T>
    void setType(T type);

    template<typename DataType>
    friend Message& operator<<(Message& message, const DataType& data);
    template<typename DataType>
    friend Message& operator>>(Message& message, DataType& data);

    friend std::ostream& operator<<(std::ostream& os, const Message& message);

  private:
    MessageHeader m_header;
    std::vector<uint8_t> m_data;
  }; // class Message
} // namespace Auxiliary::Network

#endif // SOURCES_AUXILIARY_CPP_NETWORKING_MESSAGES_MESSAGE_H
