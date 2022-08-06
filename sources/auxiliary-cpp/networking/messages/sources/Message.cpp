/**
 * \proj Библиотека вспомогательных решений С++ (auxiliary-cpp)
 * \file Файл исходного кода Message.cpp
 *
 * Copyright (c) 2022 Rodion Kolovanov
 */

#include <auxiliary-cpp/networking/messages/Message.h>

namespace Auxiliary::Networking
{
  template<typename T>
  requires Auxiliary::Common::UnsignedIntegerConvertable<T>
  void Message::setType(T type)
  {
    m_header.type = static_cast<uint32_t>(type);
  }

  template<typename DataType>
  Message& operator<<(Message& message, const DataType& data)
  {
    // TODO: Дописать
    return message;
  }

  template<typename DataType>
  Message& operator>>(Message& message, DataType& data)
  {
    // TODO: Дописать
    return message;
  }

  std::ostream& operator<<(std::ostream& os, const Message& message)
  {
    // TODO: Дописать
    return os;
  }
} // namespace Auxiliary::Networking
