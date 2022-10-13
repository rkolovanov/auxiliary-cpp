/**
 * \proj Библиотека вспомогательных компонентов С++ (auxiliary-cpp)
 * \file Заголовочный файл Types.h
 * \brief Типы
 *
 * Copyright (c) 2022 Rodion Kolovanov
 */

#ifndef SOURCES_AUXILIARY_CPP_COMMON_TYPES_H
#define SOURCES_AUXILIARY_CPP_COMMON_TYPES_H

#include <cstdint>
#include <cfloat>

namespace Auxiliary::Common::Types
{
  using Size8 = uint8_t;
  using Size16 = uint16_t;
  using Size32 = uint32_t;
  using Size64 = uint64_t;

  using Index8 = uint8_t;
  using Index16 = uint16_t;
  using Index32 = uint32_t;
  using Index64 = uint64_t;

  using Int8 = int8_t;
  using Int16 = int16_t;
  using Int32 = int32_t;
  using Int64 = int64_t;
  using Int = Int32;

  using Real4 = float;
  using Real8 = double;
  using Real16 = long double;

  using Byte = Int8;
  using Size = Size64;
  using Index = Index64;
  using Real = Real16;
} // namespace Auxiliary::Common::Types

#endif // SOURCES_AUXILIARY_CPP_COMMON_TYPES_H
