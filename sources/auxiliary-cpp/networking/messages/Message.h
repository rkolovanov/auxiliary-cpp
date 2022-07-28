/**
 * \proj Библиотека вспомогательных решений С++ (auxiliary-cpp)
 * \file Заголовочный файл Message.h
 * \brief Класс Message
 *
 * Copyright (c) 2022 Rodion Kolovanov
 */

#ifndef AUXILIARY_AUXILIARY_MESSAGE_H
#define AUXILIARY_AUXILIARY_MESSAGE_H

#include <auxiliary-cpp/common/Concepts.h>
#include <cstdint>
#include <iostream>
#include <vector>

namespace Auxiliary
{
  namespace Networking
  {
    #pragma pack(push, 1)

    struct MessageHeader
    {
      uint8_t marker[4] = {0, 0, 0, 0};
      uint32_t type = 0;
      uint32_t size = 0;
    };

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
    };
  } // namespace Networking
} // namespace Auxiliary

#endif // AUXILIARY_AUXILIARY_MESSAGE_H
