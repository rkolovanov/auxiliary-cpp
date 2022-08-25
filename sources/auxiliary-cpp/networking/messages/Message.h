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
#include <auxiliary-cpp/common/Types.h>
#include <iostream>
#include <vector>

using namespace Auxiliary::Common::Types;

namespace Auxiliary::Networking
{
#pragma pack(push, 1)

  struct MessageHeader
  {
    Byte marker[4] = {0, 0, 0, 0};
    Index type = 0;
    Size size = 0;
  }; // struct MessageHeader

#pragma pack(pop)

  class Message
  {
  public:
    template<typename T> requires Auxiliary::Common::UnsignedIntegerConvertable<T>
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
