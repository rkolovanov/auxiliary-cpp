/**
 * \proj Библиотека вспомогательных решений С++ (auxiliary-cpp)
 * \file Файл исходного кода StorageContainer.cpp
 *
 * Copyright (c) 2022 Rodion Kolovanov
 */

#include <auxiliary-cpp/common/storage/StorageContainer.h>

namespace Auxiliary
{
  namespace Common
  {
    StorageContainer::StorageContainer(const QString& name, const QVariant& data, const StorageCategory& category):
      m_index{name, category},
      m_data{data}
    {}

    void StorageContainer::setName(const QString& name)
    {
      m_index.m_name = name;
    }

    void StorageContainer::setData(const QVariant& data)
    {
      m_data = data;
    }

    void StorageContainer::setCategory(const StorageCategory& category)
    {
      m_index.m_category = category;
    }

    const QString& StorageContainer::name() const
    {
      return m_index.m_name;
    }

    const QVariant& StorageContainer::data() const
    {
      return m_data;
    }

    const StorageCategory& StorageContainer::category() const
    {
      return m_index.m_category;
    }
  } // namespace Common
} // namespace Auxiliary
