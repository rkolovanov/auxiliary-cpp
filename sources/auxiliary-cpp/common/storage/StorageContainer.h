/**
 * \proj Библиотека вспомогательных решений С++ (auxiliary-cpp)
 * \file Заголовочный файл StorageContainer.h
 * \brief Класс StorageContainer
 *
 * Copyright (c) 2022 Rodion Kolovanov
 */

#ifndef AUXILIARY_COMMON_STORAGE_CONTAINER_H
#define AUXILIARY_COMMON_STORAGE_CONTAINER_H

#include "StorageCategory.h"
#include "StorageContainerIndex.h"
#include <QVariant>

namespace Auxiliary
{
  namespace Common
  {
    class StorageContainer
    {
    public:
      explicit StorageContainer(const QString& name, const QVariant& data = {},
                                const StorageCategory& category = StorageCategory{});

      void setName(const QString& name);
      void setData(const QVariant& data);
      void setCategory(const StorageCategory& category);
      const QString& name() const;
      const QVariant& data() const;
      const StorageCategory& category() const;

    private:
      StorageContainerIndex m_index;
      QVariant m_data;
    };
  } // namespace Common
} // namespace Auxiliary

#endif // AUXILIARY_COMMON_STORAGE_CONTAINER_H
