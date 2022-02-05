/**
 * \proj Библиотека вспомогательных решений С++ (auxiliary-cpp)
 * \file Файл исходного кода TimeUtils_Test.cpp
 * \brief Тесты класса TimeUtils
 *
 * Copyright (c) 2022 Rodion Kolovanov
 */

#include "auxiliary/common/TimeUtils.h"
#include <gtest/gtest.h>

using namespace Auxiliary::Common;

TEST(TimeUtils_Test, toBoostDateTime)
{
  const auto boostDateTime = boost::posix_time::from_iso_extended_string("2022-10-15T10:20:30.123");
  auto qtDateTime = QDateTime::fromString("2022-10-15T10:20:30.123", Qt::ISODateWithMs);

  EXPECT_EQ(boostDateTime, TimeUtils::toBoostDateTime(qtDateTime));

  qtDateTime = qtDateTime.addMSecs(1);

  EXPECT_NE(boostDateTime, TimeUtils::toBoostDateTime(qtDateTime));
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
