/**
 * \proj Библиотека вспомогательных решений С++ (auxiliary-cpp)
 * \file Заголовочный файл AbstractStorage.h
 * \brief Класс AbstractStorage
 *
 * Copyright (c) 2022 Rodion Kolovanov
 */

#ifndef AbstractStorage_H_026E6F60_9F3A_4E04_9DCA_518215EE2A26
#define AbstractStorage_H_026E6F60_9F3A_4E04_9DCA_518215EE2A26

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

#endif // AbstractStorage_H_026E6F60_9F3A_4E04_9DCA_518215EE2A26

/*** End of file AbstractStorage.h ***/
