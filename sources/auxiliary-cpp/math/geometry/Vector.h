/**
 * \proj Библиотека вспомогательных решений С++ (auxiliary-cpp)
 * \file Заголовочный файл Vector.h
 * \brief Класс Vector
 *
 * Copyright (c) 2022 Rodion Kolovanov
 */

#ifndef AUXILIARY_COMMON_VECTOR_H
#define AUXILIARY_COMMON_VECTOR_H

#include <cstdint>

namespace Auxiliary
{
  namespace Common
  {
    class Vector
    {
    public:
      virtual ~Vector() = 0;
      virtual void negate() = 0;
      virtual void normalize() = 0;
      virtual double getLength() const = 0;
      virtual uint32_t
    };
  } // namespace Common
} // namespace Auxiliary

#endif // AUXILIARY_COMMON_VECTOR_H
