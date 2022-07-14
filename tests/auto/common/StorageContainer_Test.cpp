/**
 * \proj Библиотека вспомогательных решений С++ (auxiliary-cpp)
 * \file Файл исходного кода StorageContainer_Test.cpp
 * \brief Тесты класса StorageContainer
 *
 * Copyright (c) 2022 Rodion Kolovanov
 */

#include <auxiliary/common/storage/StorageContainer.h>
#include <QDateTime>
#include <gtest/gtest.h>

using namespace Auxiliary::Common;

namespace
{
  const QDateTime testDateTime = QDateTime::currentDateTime();
} // anonymous namespace

TEST(StorageContainer_Test, Common)
{
  auto container = StorageContainer{"abc"};

  EXPECT_EQ(container.name(), QStringLiteral("abc"));
  EXPECT_EQ(container.category().toString(), QString{});
  EXPECT_TRUE(container.data().isNull());

  container.setName("ABC");
  container.setCategory(StorageCategory{"settings:common", ':'});
  container.setData(testDateTime);

  EXPECT_EQ(container.name(), QStringLiteral("ABC"));
  EXPECT_EQ(container.category().getSeparator(), QChar{':'});
  EXPECT_EQ(container.category().toString(), QStringLiteral("settings:common"));
  ASSERT_TRUE(container.data().isValid());
  ASSERT_TRUE(container.data().canConvert<QDateTime>());
  EXPECT_EQ(container.data().toDateTime().toString(Qt::DateFormat::ISODateWithMs),
            testDateTime.toString(Qt::DateFormat::ISODateWithMs));
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
