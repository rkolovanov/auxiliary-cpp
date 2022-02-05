/**
 * \proj Библиотека вспомогательных решений С++ (auxiliary-cpp)
 * \file Заголовочный файл StorageContainerIndex.h
 * \brief Класс StorageContainerIndex
 *
 * Copyright (c) 2022 Rodion Kolovanov
 */

#ifndef AUXILIARY_COMMON_STORAGE_CONTAINER_INDEX_H
#define AUXILIARY_COMMON_STORAGE_CONTAINER_INDEX_H

#include <auxiliary/common/StorageCategory.h>

namespace Auxiliary
{
  namespace Common
  {
    struct StorageContainerIndex
    {
      QString m_name;
      StorageCategory m_category;
    }; // struct StorageContainerIndex
  } // namespace Common
} // namespace Auxiliary

#endif // AUXILIARY_COMMON_STORAGE_CONTAINER_INDEX_H
