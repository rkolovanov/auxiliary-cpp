/**
 * \proj Библиотека вспомогательных компонентов С++ (auxiliary-cpp)
 * \file Заголовочный файл Vector3D.h
 * \brief Класс Vector3D
 *
 * Copyright (c) 2022 Rodion Kolovanov
 */

#ifndef SOURCES_AUXILIARY_CPP_MATH_VECTOR3D_H
#define SOURCES_AUXILIARY_CPP_MATH_VECTOR3D_H

namespace Auxiliary::Math
{
  class Vector3D final
  {
  public:
    static const Vector3D ZeroVector;
    static const Vector3D ForwardVector;
    static const Vector3D RightVector;
    static const Vector3D UpVector;

  public:
    Vector3D();
    Vector3D(double x, double y, double z);
    ~Vector3D();

    [[nodiscard]] double x() const;
    [[nodiscard]] double y() const;
    [[nodiscard]] double z() const;

    [[nodiscard]] double length() const;
    [[nodiscard]] double squaredLength() const;
    [[nodiscard]] bool equal(const Vector3D& vector, double eps = 0.0001) const;

    bool operator==(const Vector3D& vector) const;
    bool operator!=(const Vector3D& vector) const;

    Vector3D operator-() const;
    Vector3D operator+(const Vector3D& vector) const;
    Vector3D operator-(const Vector3D& vector) const;
    Vector3D operator*(double scalar) const;
    Vector3D operator/(double scalar) const;

    [[nodiscard]] Vector3D normalize() const;
    [[nodiscard]] Vector3D dot(const Vector3D& vector) const;
    [[nodiscard]] Vector3D cross(const Vector3D& vector) const;

  private:
    double m_x;
    double m_y;
    double m_z;
  }; // class Vector3D
} // namespace Auxiliary::Math

#endif // SOURCES_AUXILIARY_CPP_MATH_VECTOR3D_H
