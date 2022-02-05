/**
 * \proj Библиотека вспомогательных решений С++ (auxiliary-cpp)
 * \file Заголовочный файл AbstractStorage.h
 * \brief Класс AbstractStorage
 *
 * Copyright (c) 2022 Rodion Kolovanov
 */

#ifndef AUXILIARY_COMMON_ABSTRACT_STORAGE_H
#define AUXILIARY_COMMON_ABSTRACT_STORAGE_H

#include <auxiliary/common/StorageContainer.h>

namespace Auxiliary
{
  namespace Common
  {
    class AbstractStorage
    {
    public:
      virtual const StorageContainer& getContainer(const StorageContainerIndex& index) const = 0;
      virtual void setContainer(const StorageContainer& index) = 0;
      virtual void save() = 0;
      virtual void reload() = 0;
    }; // class AbstractStorage
  } // namespace Common
} // namespace Auxiliary

#endif // AUXILIARY_COMMON_ABSTRACT_STORAGE_H
