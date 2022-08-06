/**
 * \proj Библиотека вспомогательных решений С++ (auxiliary-cpp)
 * \file Заголовочный файл Vector.h
 * \brief Класс Vector
 *
 * Copyright (c) 2022 Rodion Kolovanov
 */

#ifndef SOURCES_AUXILIARY_CPP_MATH_GEOMETRY_VECTOR_H
#define SOURCES_AUXILIARY_CPP_MATH_GEOMETRY_VECTOR_H

#include <cstdint>

namespace Auxiliary::Math
{
  class Vector
  {
  public:
    virtual ~Vector() = 0;

    virtual void negate() = 0;

    virtual void normalize() = 0;

    virtual double getLength() const = 0;
  };
} // namespace Auxiliary::Math

#endif // SOURCES_AUXILIARY_CPP_MATH_GEOMETRY_VECTOR_H
