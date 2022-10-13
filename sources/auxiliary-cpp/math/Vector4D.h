/**
 * \proj Библиотека вспомогательных компонентов С++ (auxiliary-cpp)
 * \file Заголовочный файл Vector4D.h
 * \brief Класс вектора в пространстве размерности 4 (Vector4D)
 *
 * Copyright (c) 2022 Rodion Kolovanov
 */

#ifndef SOURCES_AUXILIARY_CPP_MATH_VECTOR4D_H
#define SOURCES_AUXILIARY_CPP_MATH_VECTOR4D_H

#include <auxiliary-cpp/common/Concepts.h>
#include <auxiliary-cpp/common/Types.h>
#include <cmath>
#include <stdexcept>

namespace Auxiliary::Math
{
  using namespace Auxiliary::Common::Concepts;
  using namespace Auxiliary::Common::Types;

  template<Number T = Real>
  class Vector4D final
  {
  public:
    static const Vector4D Zero;
    static const Vector4D UnitX;
    static const Vector4D UnitY;
    static const Vector4D UnitZ;
    static const Vector4D UnitW;

  public:
    Vector4D();
    Vector4D(T v);
    Vector4D(T x, T y, T z, T w);
    ~Vector4D();

    Real length() const;
    Real squaredLength() const;

    bool equal(const Vector4D& vector, Real eps = 0.00001) const;
    bool operator==(const Vector4D& vector) const;
    bool operator!=(const Vector4D& vector) const;

    Vector4D operator-() const;
    Vector4D operator+(const Vector4D& vector) const;
    Vector4D operator-(const Vector4D& vector) const;
    Vector4D operator*(Real scalar) const;
    Vector4D operator/(Real scalar) const;

    Vector4D normalize() const;

    static bool equal(const Vector4D& left, const Vector4D& right, Real eps = 0.00001);

  public:
    T x {0};
    T y {0};
    T z {0};
    T w {0};
  }; // class Vector4D
} // namespace Auxiliary::Math

namespace Auxiliary::Math
{
  template<Number T>
  const Vector4D<T> Vector4D<T>::Zero = {0, 0, 0, 0};

  template<Number T>
  const Vector4D<T> Vector4D<T>::UnitX = {1, 0, 0, 0};

  template<Number T>
  const Vector4D<T> Vector4D<T>::UnitY = {0, 1, 0, 0};

  template<Number T>
  const Vector4D<T> Vector4D<T>::UnitZ = {0, 0, 1, 0};

  template<Number T>
  const Vector4D<T> Vector4D<T>::UnitW = {0, 0, 0, 1};

  template<Number T>
  Vector4D<T>::Vector4D() = default;

  template<Number T>
  Vector4D<T>::Vector4D(T v):
    x {v},
    y {v},
    z {v},
    w {v}
  {}

  template<Number T>
  Vector4D<T>::Vector4D(T x, T y, T z, T w):
    x {x},
    y {y},
    z {z},
    w {w}
  {}

  template<Number T>
  Vector4D<T>::~Vector4D() = default;

  template<Number T>
  inline Real Vector4D<T>::length() const
  {
    return sqrt(squaredLength());
  }

  template<Number T>
  inline Real Vector4D<T>::squaredLength() const
  {
    return x * x + y * y + z * z + w * w;
  }

  template<Number T>
  inline bool Vector4D<T>::equal(const Vector4D& vector, Real eps) const
  {
    return operator-(vector).length() < eps;
  }

  template<Number T>
  inline bool Vector4D<T>::operator==(const Vector4D& vector) const
  {
    return equal(vector);
  }

  template<Number T>
  inline bool Vector4D<T>::operator!=(const Vector4D& vector) const
  {
    return !equal(vector);
  }

  template<Number T>
  inline Vector4D<T> Vector4D<T>::operator-() const
  {
    return {-x, -y, -z, -w};
  }

  template<Number T>
  inline Vector4D<T> Vector4D<T>::operator+(const Vector4D& vector) const
  {
    return {x + vector.x, y + vector.y, z + vector.z, w + vector.w};
  }

  template<Number T>
  inline Vector4D<T> Vector4D<T>::operator-(const Vector4D& vector) const
  {
    return {x - vector.x, y - vector.y, z - vector.z, w - vector.w};
  }

  template<Number T>
  inline Vector4D<T> Vector4D<T>::operator*(Real scalar) const
  {
    return {x * scalar, y * scalar, z * scalar, w * scalar};
  }

  template<Number T>
  inline Vector4D<T> Vector4D<T>::operator/(Real scalar) const
  {
    if (scalar == 0.0)
    {
      throw std::domain_error {"Vector4D::operator/ division by zero"};
    }
    Real s = 1.0 / scalar;
    return {x * s, y * s, z * s, w * s};
  }

  template<Number T>
  inline Vector4D<T> Vector4D<T>::normalize() const
  {
    Real l = length();
    if (l == 0.0)
    {
      return Zero;
    }
    Real s = 1.0 / l;
    return {x * s, y * s, z * s, w * s};
  }

  template<Number T>
  inline bool Vector4D<T>::equal(const Vector4D& left, const Vector4D& right, Real eps)
  {
    return left.equal(right, eps);
  }
} // namespace Auxiliary::Math

#endif // SOURCES_AUXILIARY_CPP_MATH_VECTOR4D_H
