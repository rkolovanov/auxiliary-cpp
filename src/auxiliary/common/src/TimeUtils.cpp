/**
 * \proj Библиотека вспомогательных решений С++ (auxiliary-cpp)
 * \file Файл исходного кода TimeUtils.cpp
 *
 * Copyright (c) 2022 Rodion Kolovanov
 */

#include <auxiliary/common/TimeUtils.h>

namespace Auxiliary
{
  namespace Common
  {
    boost::posix_time::ptime TimeUtils::toBoostDateTime(const QDateTime& dateTime) {
      const auto dateTimeString = dateTime.toString(Qt::DateFormat::ISODateWithMs).toStdString();
      return boost::posix_time::from_iso_extended_string(dateTimeString);
    }
  } // namespace Common
} // namespace Auxiliary

/*** End of file TimeUtils.cpp ***/
