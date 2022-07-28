/**
 * \proj Библиотека вспомогательных решений С++ (auxiliary-cpp)
 * \file Заголовочный файл StorageContainerIndex.h
 * \brief Класс StorageContainerIndex
 *
 * Copyright (c) 2022 Rodion Kolovanov
 */

#ifndef AUXILIARY_COMMON_STORAGE_CONTAINER_INDEX_H
#define AUXILIARY_COMMON_STORAGE_CONTAINER_INDEX_H

namespace Auxiliary
{
  namespace Common
  {
    class StorageCategory;

    struct StorageContainerIndex
    {
      QString m_name;
      StorageCategory m_category;
    };
  } // namespace Common
} // namespace Auxiliary

#endif // AUXILIARY_COMMON_STORAGE_CONTAINER_INDEX_H
