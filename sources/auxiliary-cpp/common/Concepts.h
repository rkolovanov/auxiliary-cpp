/**
 * \proj Библиотека вспомогательных решений С++ (auxiliary-cpp)
 * \file Заголовочный файл Common.h
 * \brief Концепты
 *
 * Copyright (c) 2022 Rodion Kolovanov
 */

#ifndef AUXILIARY_AUXILIARY_COMMON_H
#define AUXILIARY_AUXILIARY_COMMON_H

#include <concepts>
#include <cstdint>

namespace Auxiliary
{
  namespace Common
  {
    template<typename T>
    concept UnsignedIntegerConvertable = std::integral<T> && std::convertible_to<T, uint32_t>;
  } // namespace Common
} // namespace Auxiliary

#endif // AUXILIARY_AUXILIARY_COMMON_H
