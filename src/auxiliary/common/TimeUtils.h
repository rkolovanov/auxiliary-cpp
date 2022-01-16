/**
 * \proj Библиотека вспомогательных решений С++ (auxiliary-cpp)
 * \file Заголовочный файл TimeUtils.h
 * \brief Класс TimeUtils
 *
 * Copyright (c) 2022 Rodion Kolovanov
 */

#ifndef TimeUtils_H_A38B9EF1_14FC_4247_AB5A_656F810C6E79
#define TimeUtils_H_A38B9EF1_14FC_4247_AB5A_656F810C6E79

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

#endif // TimeUtils_H_A38B9EF1_14FC_4247_AB5A_656F810C6E79

/*** End of file TimeUtils.h ***/
