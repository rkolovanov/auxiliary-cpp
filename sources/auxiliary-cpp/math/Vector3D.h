/**
 * \proj Библиотека вспомогательных компонентов С++ (auxiliary-cpp)
 * \file Заголовочный файл Vector3D.h
 * \brief Класс вектора в пространстве размерности 3 (Vector3D)
 *
 * Copyright (c) 2022 Rodion Kolovanov
 */

#ifndef SOURCES_AUXILIARY_CPP_MATH_VECTOR3D_H
#define SOURCES_AUXILIARY_CPP_MATH_VECTOR3D_H

#include <auxiliary-cpp/common/Concepts.h>
#include <auxiliary-cpp/common/Types.h>
#include <cmath>
#include <stdexcept>

namespace Auxiliary::Math
{
  using namespace Auxiliary::Common::Concepts;
  using namespace Auxiliary::Common::Types;

  template<Number T = Real>
  class Vector3D final
  {
  public:
    static const Vector3D Zero;
    static const Vector3D UnitX;
    static const Vector3D UnitY;
    static const Vector3D UnitZ;

  public:
    Vector3D();
    Vector3D(T v);
    Vector3D(T x, T y, T z);
    ~Vector3D();

    Real length() const;
    Real squaredLength() const;

    bool equal(const Vector3D& vector, Real eps = 0.00001) const;
    bool operator==(const Vector3D& vector) const;
    bool operator!=(const Vector3D& vector) const;

    Vector3D operator-() const;
    Vector3D operator+(const Vector3D& vector) const;
    Vector3D operator-(const Vector3D& vector) const;
    Vector3D operator*(Real scalar) const;
    Vector3D operator/(Real scalar) const;

    Vector3D normalize() const;
    Vector3D dot(const Vector3D& vector) const;
    Vector3D cross(const Vector3D& vector) const;

    static bool equal(const Vector3D& left, const Vector3D& right, Real eps = 0.00001);
    static Vector3D dotProduct(const Vector3D& left, const Vector3D& right);
    static Vector3D crossProduct(const Vector3D& left, const Vector3D& right);

  public:
    T x {0};
    T y {0};
    T z {0};
  }; // class Vector3D
} // namespace Auxiliary::Math

namespace Auxiliary::Math
{
  template<Number T>
  const Vector3D<T> Vector3D<T>::Zero = {0, 0, 0};

  template<Number T>
  const Vector3D<T> Vector3D<T>::UnitX = {1, 0, 0};

  template<Number T>
  const Vector3D<T> Vector3D<T>::UnitY = {0, 1, 0};

  template<Number T>
  const Vector3D<T> Vector3D<T>::UnitZ = {0, 0, 1};

  template<Number T>
  Vector3D<T>::Vector3D() = default;

  template<Number T>
  Vector3D<T>::Vector3D(T v):
    x {v},
    y {v},
    z {v}
  {}

  template<Number T>
  Vector3D<T>::Vector3D(T x, T y, T z):
    x {x},
    y {y},
    z {z}
  {}

  template<Number T>
  Vector3D<T>::~Vector3D() = default;

  template<Number T>
  inline Real Vector3D<T>::length() const
  {
    return sqrt(squaredLength());
  }

  template<Number T>
  inline Real Vector3D<T>::squaredLength() const
  {
    return x * x + y * y + z * z;
  }

  template<Number T>
  inline bool Vector3D<T>::equal(const Vector3D& vector, Real eps) const
  {
    return operator-(vector).length() < eps;
  }

  template<Number T>
  inline bool Vector3D<T>::operator==(const Vector3D& vector) const
  {
    return equal(vector);
  }

  template<Number T>
  inline bool Vector3D<T>::operator!=(const Vector3D& vector) const
  {
    return !equal(vector);
  }

  template<Number T>
  inline Vector3D<T> Vector3D<T>::operator-() const
  {
    return {-x, -y, -z};
  }

  template<Number T>
  inline Vector3D<T> Vector3D<T>::operator+(const Vector3D& vector) const
  {
    return {x + vector.x, y + vector.y, z + vector.z};
  }

  template<Number T>
  inline Vector3D<T> Vector3D<T>::operator-(const Vector3D& vector) const
  {
    return {x - vector.x, y - vector.y, z - vector.z};
  }

  template<Number T>
  inline Vector3D<T> Vector3D<T>::operator*(Real scalar) const
  {
    return {x * scalar, y * scalar, z * scalar};
  }

  template<Number T>
  inline Vector3D<T> Vector3D<T>::operator/(Real scalar) const
  {
    if (scalar == 0.0)
    {
      throw std::domain_error {"Vector3D::operator/ division by zero"};
    }
    Real s = 1.0 / scalar;
    return {x * s, y * s, z * s};
  }

  template<Number T>
  inline Vector3D<T> Vector3D<T>::normalize() const
  {
    Real l = length();
    if (l == 0.0)
    {
      return Zero;
    }
    Real s = 1.0 / l;
    return {x * s, y * s, z * s};
  }

  template<Number T>
  inline Vector3D<T> Vector3D<T>::dot(const Vector3D& vector) const
  {
    return {x * vector.x, y * vector.y, z * vector.z};
  }

  template<Number T>
  inline Vector3D<T> Vector3D<T>::cross(const Vector3D& vector) const
  {
    return {y * vector.z - vector.y * z,
            z * vector.x - vector.z * x,
            x * vector.y - vector.x * y};
  }

  template<Number T>
  inline bool Vector3D<T>::equal(const Vector3D& left, const Vector3D& right, Real eps)
  {
    return left.equal(right, eps);
  }

  template<Number T>
  inline Vector3D<T> Vector3D<T>::dotProduct(const Vector3D& left, const Vector3D& right)
  {
    return left.dot(right);
  }

  template<Number T>
  inline Vector3D<T> Vector3D<T>::crossProduct(const Vector3D& left, const Vector3D& right)
  {
    return left.cross(right);
  }
} // namespace Auxiliary::Math

#endif // SOURCES_AUXILIARY_CPP_MATH_VECTOR3D_H
