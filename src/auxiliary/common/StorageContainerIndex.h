/**
 * \proj Библиотека вспомогательных решений С++ (auxiliary-cpp)
 * \file Заголовочный файл StorageContainerIndex.h
 * \brief Класс StorageContainerIndex
 *
 * Copyright (c) 2022 Rodion Kolovanov
 */

#ifndef StorageContainerIndex_H_9879412F_5247_4A89_BF15_D18D173452B7
#define StorageContainerIndex_H_9879412F_5247_4A89_BF15_D18D173452B7

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

#endif // StorageContainerIndex_H_9879412F_5247_4A89_BF15_D18D173452B7

/*** End of file StorageContainerIndex.h ***/
