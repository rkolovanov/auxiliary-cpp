/**
 * \proj Библиотека вспомогательных решений С++ (auxiliary-cpp)
 * \file Заголовочный файл Vector.h
 * \brief Класс Vector
 *
 * Copyright (c) 2022 Rodion Kolovanov
 */

#ifndef AUXILIARY_COMMON_VECTOR_H
#define AUXILIARY_COMMON_VECTOR_H

#include <cstddef>

namespace Auxiliary
{
  namespace Common
  {
    class Vector
    {
    public:
      virtual ~Vector() = 0;
      virtual double getLength() const = 0;
    };
  } // namespace Common
} // namespace Auxiliary

#endif // AUXILIARY_COMMON_VECTOR_H
