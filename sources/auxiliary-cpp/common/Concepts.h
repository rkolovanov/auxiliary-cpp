/**
 * \proj Библиотека вспомогательных компонентов С++ (auxiliary-cpp)
 * \file Заголовочный файл Concepts.h
 * \brief Концепты
 *
 * Copyright (c) 2022 Rodion Kolovanov
 */

#ifndef SOURCES_AUXILIARY_CPP_COMMON_CONCEPTS_H
#define SOURCES_AUXILIARY_CPP_COMMON_CONCEPTS_H

#include <concepts>

namespace Auxiliary::Common
{
  template<typename T>
  concept UnsignedIntegerConvertable = std::integral<T> && std::is_enum_v<T>;

  template<typename T>
  concept Number = std::is_arithmetic_v<T>;
} // namespace Auxiliary::Common

#endif // SOURCES_AUXILIARY_CPP_COMMON_CONCEPTS_H
