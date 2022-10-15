/**
 * \proj Библиотека вспомогательных компонентов С++ (auxiliary-cpp)
 * \file Заголовочный файл Matrix4x4.h
 * \brief Класс Matrix4x4
 *
 * Copyright (c) 2022 Rodion Kolovanov
 */

#ifndef SOURCES_AUXILIARY_CPP_MATH_MATRIX4X4_H
#define SOURCES_AUXILIARY_CPP_MATH_MATRIX4X4_H

#include <auxiliary-cpp/common/Types.h>
#include <auxiliary-cpp/math/Vector3D.h>
#include <auxiliary-cpp/math/Vector4D.h>
#include <array>
#include <functional>

namespace Auxiliary::Math
{
  using namespace Auxiliary::Common::Types;

  template<Number T = Real>
  class Matrix4x4
  {
  public:
    static const Size8 Rows;
    static const Size8 Columns;
    static const Matrix4x4 Zero;
    static const Matrix4x4 Identity;

  public:
    static Matrix4x4 Diagonal(T value);
    static Matrix4x4 Constant(T value);
    static Matrix4x4 Displacement(const Vector3D<T>& delta);
    // TODO: static Matrix4x4 Rotate(const Vector3D<T>& rotator);
    static Matrix4x4 Scale(const Vector3D<T>& factor);
    // TODO: Other basic Matrix4x4

  public:
    Matrix4x4();
    Matrix4x4(T value);

    T& get(Index8 row, Index8 column);
    T get(Index8 row, Index8 column) const;
    Vector4D<T> getRow(Index8 index) const;
    Vector4D<T> getColumn(Index8 index) const;

    // TODO: Matrix4x4 negate() const;
    // TODO: Matrix4x4 inverse() const;

    Matrix4x4 operator+(const Matrix4x4& matrix) const;
    // TODO: Matrix4x4 operator+=(const Matrix4x4& matrix);
    // TODO: Matrix4x4 operator-(const Matrix4x4& matrix) const;
    // TODO: Matrix4x4 operator-=(const Matrix4x4& matrix);
    Matrix4x4 operator*(const Matrix4x4& matrix) const;
    // TODO: Matrix4x4 operator*=(const Matrix4x4& matrix);
    Vector4D<T> operator*(const Vector4D<T>& vector) const;
    Matrix4x4 operator*(T value) const;
    // TODO: Matrix4x4 operator*=(T value);
    // TODO: Matrix4x4 operator/(T value) const;
    // TODO: Matrix4x4 operator/=(T value);

    // TODO: Matrix4x4 operator==(const Matrix4x4& matrix) const;
    // TODO: Matrix4x4 operator!=(const Matrix4x4& matrix) const;

  private:
    std::array<std::array<T, Columns>, Rows> m_data {};
  }; // class Matrix

  template<Number T>
  const Size8 Matrix4x4<T>::Rows = 4;

  template<Number T>
  const Size8 Matrix4x4<T>::Columns = 4;

  template<Number T>
  const Matrix4x4<T> Matrix4x4<T>::Zero = Matrix4x4<T>(0);

  template<Number T>
  const Matrix4x4<T> Matrix4x4<T>::Identity = Matrix4x4<T>::Diagonal(1);

  template<Number T>
  inline Matrix4x4<T> Matrix4x4<T>::Diagonal(T value)
  {
    Matrix4x4<T> m;

    for (Index16 i = 0; i < Rows && i < Columns; ++i)
    {
      m.m_data[i][i] = value;
    }

    return m;
  }

  template<Number T>
  inline Matrix4x4<T> Matrix4x4<T>::Constant(T value)
  {
    return Matrix4x4<T>(value);
  }

  template<Number T>
  inline Matrix4x4<T> Matrix4x4<T>::Displacement(const Vector3D<T>& delta)
  {
    const auto result = Matrix4x4<T>::Identity;

    result.m_data[0][3] = delta.x;
    result.m_data[1][3] = delta.y;
    result.m_data[2][3] = delta.z;

    return Matrix4x4();
  }

  template<Number T>
  inline Matrix4x4<T> Matrix4x4<T>::Scale(const Vector3D<T>& factor)
  {
    const auto result = Matrix4x4<T>::Identity;

    result.m_data[0][0] = factor.x;
    result.m_data[1][1] = factor.y;
    result.m_data[2][2] = factor.z;

    return Matrix4x4();
  }

  template<Number T>
  Matrix4x4<T>::Matrix4x4() = default;

  template<Number T>
  Matrix4x4<T>::Matrix4x4(T value)
  {
    for (Index16 i = 0; i < Rows; ++i)
    {
      m_data[i].fill(value);
    }
  }

  template<Number T>
  T& Matrix4x4<T>::get(Index8 row, Index8 column)
  {
    if (row >= Rows || column >= Columns)
    {
      throw std::range_error {"Matrix4x4::operator[]: invalid row or column index"};
    }
    return m_data[row][column];
  }

  template<Number T>
  T Matrix4x4<T>::get(Index8 row, Index8 column) const
  {
    if (row >= Rows || column >= Columns)
    {
      throw std::range_error {"Matrix4x4::operator[]: invalid row or column index"};
    }
    return m_data[row][column];
  }

  template<Number T>
  Vector4D<T> Matrix4x4<T>::getRow(Index8 index) const
  {
    if (index > Rows)
    {
      throw std::range_error {"Matrix4x4::getRow: invalid row index"};
    }

    Vector4D<T> row;

    for (Index16 i = 0; i < Columns; ++i)
    {
      row[i] = m_data[index][i];
    }

    return row;
  }

  template<Number T>
  Vector4D<T> Matrix4x4<T>::getColumn(Index8 index) const
  {
    if (index > Columns)
    {
      throw std::range_error {"Matrix4x4::getColumn: invalid column index"};
    }

    Vector4D<T> column;

    for (Index16 i = 0; i < Rows; ++i)
    {
      column[i] = m_data[i][index];
    }

    return column;
  }

  template<Number T>
  Matrix4x4<T> Matrix4x4<T>::operator+(const Matrix4x4<T>& matrix) const
  {
    Matrix4x4<T> result;

    for (Index16 i = 0; i < Rows; ++i)
    {
      for (Index16 j = 0; j < Columns; ++j)
      {
        result.m_data[i][j] = m_data[i][j] + matrix.m_data[i][j];
      }
    }

    return result;
  }

  template<Number T>
  Matrix4x4<T> Matrix4x4<T>::operator*(const Matrix4x4<T>& matrix) const
  {
    auto result = Zero;

    for (Index16 i = 0; i < Rows; ++i)
    {
      for (Index16 j = 0; j < Columns; ++j)
      {
        for (Index16 k = 0; k < Rows; ++k)
        {
          result.m_data[i][j] += m_data[i][k] * matrix.m_data[k][j];
        }
      }
    }

    return result;
  }

  template<Number T>
  Vector4D<T> Matrix4x4<T>::operator*(const Vector4D<T>& vector) const
  {
    Vector4D<T> result;

    result.x = m_data[0][0] * vector.x + m_data[0][1] * vector.y + m_data[0][2] * vector.z + m_data[0][3] * vector.w;
    result.y = m_data[1][0] * vector.x + m_data[1][1] * vector.y + m_data[1][2] * vector.z + m_data[1][3] * vector.w;
    result.z = m_data[2][0] * vector.x + m_data[2][1] * vector.y + m_data[2][2] * vector.z + m_data[2][3] * vector.w;
    result.w = m_data[3][0] * vector.x + m_data[3][1] * vector.y + m_data[3][2] * vector.z + m_data[3][3] * vector.w;

    return result;
  }

  template<Number T>
  Matrix4x4<T> Matrix4x4<T>::operator*(T value) const
  {
    Matrix4x4<T> result;

    for (Index16 i = 0; i < Rows; ++i)
    {
      for (Index16 j = 0; j < Columns; ++j)
      {
        result.m_data[i][j] = m_data[i][j] * value;
      }
    }

    return result;
  }
} // namespace Auxiliary::Math

#endif // SOURCES_AUXILIARY_CPP_MATH_MATRIX4X4_H
