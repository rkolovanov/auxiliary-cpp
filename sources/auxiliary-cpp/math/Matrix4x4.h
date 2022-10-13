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

namespace Auxiliary::Math
{
  using namespace Auxiliary::Common::Types;

  template<Number T = Real>
  class Matrix4x4
  {
  public:
    static const Size8 Rows;
    static const Size8 Columns;

  public:
    static Matrix4x4<T> Diagonal(T value);
    static Matrix4x4<T> Constant(T value);
    static Matrix4x4<T> Zero();
    static Matrix4x4<T> Identity();
    // TODO: Other basic Matrix4x4

  public:
    Matrix4x4();
    Matrix4x4(T value);

    T& get(Index8 row, Index8 column);
    T get(Index8 row, Index8 column) const;
    Vector4D<T> getRow(Index8 index) const;
    Vector4D<T> getColumn(Index8 index) const;

    // TODO: negate method
    Matrix4x4<T> operator+(const Matrix4x4<T>& matrix) const;
    // TODO: operator-
    Matrix4x4<T> operator*(const Matrix4x4<T>& matrix) const;
    Vector4D<T> operator*(const Vector4D<T>& vector) const;
    Matrix4x4<T> operator*(T value) const;

    // TODO: compare methods

    T operator[](Size8 i, Size8 j) const;
    T& operator[](Size8 i, Size8 j);

  private:
    std::array<std::array<T, Columns>, Rows> m_data {};
  }; // class Matrix

  template<Number T>
  const Size8 Matrix4x4<T>::Rows = 8;

  template<Number T>
  const Size8 Matrix4x4<T>::Columns = 8;

  template<Number T>
  inline Matrix4x4<T> Matrix4x4<T>::Diagonal(T value)
  {
    Matrix4x4<T> m;

    for (int i = 0; i < Rows && i < Columns; ++i)
    {
      m[i, i] = value;
    }

    return m;
  }

  template<Number T>
  inline Matrix4x4<T> Matrix4x4<T>::Constant(T value)
  {
    return Matrix4x4<T>(value);
  }

  template<Number T>
  inline Matrix4x4<T> Matrix4x4<T>::Zero()
  {
    return Constant(0);
  }

  template<Number T>
  inline Matrix4x4<T> Matrix4x4<T>::Identity()
  {
    return Diagonal(1);
  }

  template<Number T>
  Matrix4x4<T>::Matrix4x4() = default;

  template<Number T>
  Matrix4x4<T>::Matrix4x4(T value)
  {
    for (int i = 0; i < Rows; ++i)
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

    for (int i = 0; i < Columns; ++i)
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

    for (int i = 0; i < Rows; ++i)
    {
      column[i] = m_data[i][index];
    }

    return column;
  }

  template<Number T>
  Matrix4x4<T> Matrix4x4<T>::operator+(const Matrix4x4<T>& matrix) const
  {
    Matrix4x4<T> result;

    for (int i = 0; i < Rows; ++i)
    {
      for (int j = 0; j < Columns; ++j)
      {
        result[i, j] = m_data[i][j] + matrix[i, j];
      }
    }

    return result;
  }

  template<Number T>
  Matrix4x4<T> Matrix4x4<T>::operator*(const Matrix4x4<T>& matrix) const
  {
    auto result = Zero();

    for (int i = 0; i < Rows; ++i)
    {
      for (int j = 0; j < Columns; ++j)
      {
        result[i, j] += m_data[i][j] * matrix[j, i];
      }
    }

    return result;
  }

  template<Number T>
  Vector4D<T> Matrix4x4<T>::operator*(const Vector4D<T>& vector) const
  {
    auto result = Vector4D<T>::Zero;

    for (int i = 0; i < Rows; ++i)
    {
      for (int j = 0; j < Columns; ++j)
      {
        result[i] += m_data[i][j] * vector[j];
      }
    }

    return result;
  }

  template<Number T>
  Matrix4x4<T> Matrix4x4<T>::operator*(T value) const
  {
    Matrix4x4<T> result;

    for (int i = 0; i < Rows; ++i)
    {
      for (int j = 0; j < Columns; ++j)
      {
        result[i, j] = m_data[i][j] * value;
      }
    }

    return result;
  }

  template<Number T>
  inline T Matrix4x4<T>::operator[](Size8 row, Size8 column) const
  {
    return get(row, column);
  }

  template<Number T>
  inline T& Matrix4x4<T>::operator[](Size8 row, Size8 column)
  {
    return get(row, column);
  }
} // namespace Auxiliary::Math

#endif // SOURCES_AUXILIARY_CPP_MATH_MATRIX4X4_H
