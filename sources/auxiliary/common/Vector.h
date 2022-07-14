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
    template<size_t N, class T = double>
    class VectorBase
    {
    public:
      VectorBase() = default;

    private:
      T m_data[N];
    }; // class Vector

    using Vector2D = VectorBase<2, double>;
    using Vector3D = VectorBase<3, double>;
  } // namespace Common
} // namespace Auxiliary

#endif // AUXILIARY_COMMON_VECTOR_H
