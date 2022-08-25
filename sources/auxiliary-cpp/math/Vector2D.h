/**
 * \proj Библиотека вспомогательных компонентов С++ (auxiliary-cpp)
 * \file Заголовочный файл Vector2D.h
 * \brief Класс вектора в пространстве размерности 2 (Vector2D)
 *
 * Copyright (c) 2022 Rodion Kolovanov
 */

#ifndef SOURCES_AUXILIARY_CPP_MATH_VECTOR2D_H
#define SOURCES_AUXILIARY_CPP_MATH_VECTOR2D_H

#include <auxiliary-cpp/common/Concepts.h>
#include <auxiliary-cpp/common/Types.h>
#include <cmath>
#include <stdexcept>

using namespace Auxiliary::Common::Types;

namespace Auxiliary::Math
{
  template<Common::Number T = Real>
  class Vector2D final
  {
  public:
    static const Vector2D Zero;
    static const Vector2D UnitX;
    static const Vector2D UnitY;

  public:
    Vector2D();
    Vector2D(T v);
    Vector2D(T x, T y);
    ~Vector2D();

    Real length() const;
    Real squaredLength() const;

    bool equal(const Vector2D& vector, Real eps = 0.00001) const;
    bool operator==(const Vector2D& vector) const;
    bool operator!=(const Vector2D& vector) const;

    Vector2D operator-() const;
    Vector2D operator+(const Vector2D& vector) const;
    Vector2D operator-(const Vector2D& vector) const;
    Vector2D operator*(Real scalar) const;
    Vector2D operator/(Real scalar) const;

    Vector2D normalize() const;
    Vector2D dot(const Vector2D& vector) const;

    static bool equal(const Vector2D& left, const Vector2D& right, Real eps = 0.00001);
    static Vector2D dotProduct(const Vector2D& left, const Vector2D& right);

  public:
    T x;
    T y;
  }; // class Vector2D
} // namespace Auxiliary::Math

namespace Auxiliary::Math
{
  template<Common::Number T>
  const Vector2D<T> Vector2D<T>::Zero = {0, 0};

  template<Common::Number T>
  const Vector2D<T> Vector2D<T>::UnitX = {1, 0};

  template<Common::Number T>
  const Vector2D<T> Vector2D<T>::UnitY = {0, 1};

  template<Common::Number T>
  Vector2D<T>::Vector2D() = default;

  template<Common::Number T>
  Vector2D<T>::Vector2D(T x, T y):
    x {x},
    y {y}
  {}

  template<Common::Number T>
  Vector2D<T>::Vector2D(T v):
    x {v},
    y {v}
  {}

  template<Common::Number T>
  Vector2D<T>::~Vector2D() = default;

  template<Common::Number T>
  inline Real Vector2D<T>::length() const
  {
    return sqrt(squaredLength());
  }

  template<Common::Number T>
  inline Real Vector2D<T>::squaredLength() const
  {
    return x * x + y * y;
  }

  template<Common::Number T>
  inline bool Vector2D<T>::equal(const Vector2D& vector, Real eps) const
  {
    return operator-(vector).length() < eps;
  }

  template<Common::Number T>
  inline bool Vector2D<T>::operator==(const Vector2D& vector) const
  {
    return equal(vector);
  }

  template<Common::Number T>
  inline bool Vector2D<T>::operator!=(const Vector2D& vector) const
  {
    return !equal(vector);
  }

  template<Common::Number T>
  inline Vector2D<T> Vector2D<T>::operator-() const
  {
    return {-x, -y};
  }

  template<Common::Number T>
  inline Vector2D<T> Vector2D<T>::operator+(const Vector2D& vector) const
  {
    return {x + vector.x, y + vector.y};
  }

  template<Common::Number T>
  inline Vector2D<T> Vector2D<T>::operator-(const Vector2D& vector) const
  {
    return {x - vector.x, y - vector.y};
  }

  template<Common::Number T>
  inline Vector2D<T> Vector2D<T>::operator*(Real scalar) const
  {
    return {x * scalar, y * scalar};
  }

  template<Common::Number T>
  inline Vector2D<T> Vector2D<T>::operator/(Real scalar) const
  {
    if (scalar == 0.0)
    {
      throw std::domain_error {"Vector2D::operator/ division by zero"};
    }
    Real s = 1.0 / scalar;
    return {x * s, y * s};
  }

  template<Common::Number T>
  inline Vector2D<T> Vector2D<T>::normalize() const
  {
    Real l = length();
    if (l == 0.0)
    {
      return Zero;
    }
    return {x / l, y / l};
  }

  template<Common::Number T>
  inline Vector2D<T> Vector2D<T>::dot(const Vector2D& vector) const
  {
    return {x * vector.x, y * vector.y};
  }

  template<Common::Number T>
  inline bool Vector2D<T>::equal(const Vector2D& left, const Vector2D& right, Real eps)
  {
    return left.equal(right, eps);
  }

  template<Common::Number T>
  inline Vector2D<T> Vector2D<T>::dotProduct(const Vector2D& left, const Vector2D& right)
  {
    return left.dot(right);
  }
} // namespace Auxiliary::Math


#endif // SOURCES_AUXILIARY_CPP_MATH_VECTOR2D_H
