/**
 * \proj Библиотека вспомогательных решений С++ (auxiliary-cpp)
 * \file Заголовочный файл StorageContainer.h
 * \brief Класс StorageContainer
 *
 * Copyright (c) 2022 Rodion Kolovanov
 */

#ifndef StorageContainer_H_0F5CFF19_A15A_40BD_83AE_F4D921B90523
#define StorageContainer_H_0F5CFF19_A15A_40BD_83AE_F4D921B90523

#include <auxiliary/common/StorageCategory.h>
#include <auxiliary/common/StorageContainerIndex.h>
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
    }; // class StorageContainer
  } // namespace Common
} // namespace Auxiliary

#endif // StorageContainer_H_0F5CFF19_A15A_40BD_83AE_F4D921B90523

/*** End of file StorageContainer.h ***/
