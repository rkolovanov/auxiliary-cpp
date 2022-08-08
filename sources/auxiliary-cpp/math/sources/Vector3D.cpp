/**
 * \proj Библиотека вспомогательных компонентов С++ (auxiliary-cpp)
 * \file Файл исходного кода Vector3D.cpp
 *
 * Copyright (c) 2022 Rodion Kolovanov
 */

#include <auxiliary-cpp/math/Vector3D.h>
#include <cmath>
#include <stdexcept>

namespace Auxiliary::Math
{
  const Vector3D Vector3D::ZeroVector = {0.0, 0.0, 0.0};
  const Vector3D Vector3D::ForwardVector = {1.0, 0.0, 0.0};
  const Vector3D Vector3D::RightVector = {0.0, 1.0, 0.0};
  const Vector3D Vector3D::UpVector = {0.0, 0.0, 1.0};

  Vector3D::Vector3D():
    m_x {0.0},
    m_y {0.0},
    m_z {0.0}
  {}

  Vector3D::Vector3D(double x, double y, double z):
    m_x {x},
    m_y {y},
    m_z {z}
  {}

  Vector3D::~Vector3D() = default;

  double Vector3D::x() const
  {
    return m_x;
  }

  double Vector3D::y() const
  {
    return m_y;
  }

  double Vector3D::z() const
  {
    return m_z;
  }

  double Vector3D::length() const
  {
    return sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
  }

  double Vector3D::squaredLength() const
  {
    return m_x * m_x + m_y * m_y + m_z * m_z;
  }

  bool Vector3D::equal(const Vector3D& vector, double eps) const
  {
    return operator-(vector).length() < eps;
  }

  bool Vector3D::operator==(const Vector3D& vector) const
  {
    return equal(vector);
  }

  bool Vector3D::operator!=(const Vector3D& vector) const
  {
    return !equal(vector);
  }

  Vector3D Vector3D::operator-() const
  {
    return {-m_x, -m_y, -m_z};
  }

  Vector3D Vector3D::operator+(const Vector3D& vector) const
  {
    return {m_x + vector.m_x, m_y + vector.m_y, m_z + vector.m_z};
  }

  Vector3D Vector3D::operator-(const Vector3D& vector) const
  {
    return {m_x - vector.m_x, m_y - vector.m_y, m_z - vector.m_z};
  }

  Vector3D Vector3D::operator*(double scalar) const
  {
    return {m_x * scalar, m_y * scalar, m_z * scalar};
  }

  Vector3D Vector3D::operator/(double scalar) const
  {
    if (scalar == 0.0)
    {
      throw std::domain_error {"Vector3D::operator/(double scalar): division by zero"};
    }
    double s = 1.0 / scalar;
    return {m_x * s, m_y * s, m_z * s};
  }

  Vector3D Vector3D::normalize() const
  {
    double l = length();
    if (l == 0.0)
    {
      return ZeroVector;
    }
    return {m_x / l, m_y / l, m_z / l};
  }

  Vector3D Vector3D::dot(const Vector3D& vector) const
  {
    return {m_x * vector.m_x, m_y * vector.m_y, m_z * vector.m_z};
  }

  Vector3D Vector3D::cross(const Vector3D& vector) const
  {
    return {m_y * vector.m_z - vector.m_y * m_z,
      m_z * vector.m_x - vector.m_z * m_x,
      m_x * vector.m_y - vector.m_x * m_y};
  }
} // namespace Auxiliary::Math
