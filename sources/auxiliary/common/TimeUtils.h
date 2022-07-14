/**
 * \proj Библиотека вспомогательных решений С++ (auxiliary-cpp)
 * \file Заголовочный файл TimeUtils.h
 * \brief Класс TimeUtils
 *
 * Copyright (c) 2022 Rodion Kolovanov
 */

#ifndef AUXILIARY_COMMON_TIME_UTILS_H
#define AUXILIARY_COMMON_TIME_UTILS_H

#include <QDateTime>
#include <boost/date_time.hpp>

namespace Auxiliary
{
  namespace Common
  {
    class TimeUtils
    {
    public:
      static boost::posix_time::ptime toBoostDateTime(const QDateTime& dateTime);
    }; // class TimeUtils
  } // namespace Common
} // namespace Auxiliary

#endif // AUXILIARY_COMMON_TIME_UTILS_H
