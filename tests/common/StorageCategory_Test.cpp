/**
 * \proj Библиотека вспомогательных решений С++ (auxiliary-cpp)
 * \file Файл исходного кода StorageCategory_Test.cpp
 * \brief Тесты класса StorageCategory
 *
 * Copyright (c) 2022 Rodion Kolovanov
 */

#include <auxiliary/common/StorageCategory.h>
#include <gtest/gtest.h>

using namespace Auxiliary::Common;

TEST(StorageCategory_Test, ConstructionAndToString)
{
  auto category = StorageCategory{};

  EXPECT_EQ(category.getSeparator(), QChar{'|'});
  EXPECT_EQ(category.toString(), QString{});

  category = StorageCategory{':'};

  EXPECT_EQ(category.getSeparator(), QChar{':'});
  EXPECT_EQ(category.toString(), QString{});

  category = StorageCategory{"", ':'};

  EXPECT_EQ(category.getSeparator(), QChar{':'});
  EXPECT_EQ(category.toString(), QString{});

  category = StorageCategory{"settings", '|'};

  EXPECT_EQ(category.getSeparator(), QChar{'|'});
  EXPECT_EQ(category.toString(), QStringLiteral("settings"));

  category = StorageCategory{"settings|gui", '|'};

  EXPECT_EQ(category.getSeparator(), QChar{'|'});
  EXPECT_EQ(category.toString(), QStringLiteral("settings|gui"));

  category = StorageCategory{"settings:gui", ':'};

  EXPECT_EQ(category.getSeparator(), QChar{':'});
  EXPECT_EQ(category.toString(), QStringLiteral("settings:gui"));
}

TEST(StorageCategory_Test, AppendTopicAndGetChildCategory)
{
  auto category = StorageCategory{':'};

  category.appendTopic("settings");
  EXPECT_EQ(category.toString(), QStringLiteral("settings"));

  category.appendTopic("gui");
  EXPECT_EQ(category.toString(), QStringLiteral("settings:gui"));

  category.appendTopic("dialog");
  EXPECT_EQ(category.toString(), QStringLiteral("settings:gui:dialog"));

  auto childCategory = category.getChildCategory();
  EXPECT_EQ(childCategory.getSeparator(), category.getSeparator());
  EXPECT_EQ(childCategory.toString(), QStringLiteral("settings:gui"));

  childCategory = childCategory.getChildCategory();
  EXPECT_EQ(childCategory.getSeparator(), category.getSeparator());
  EXPECT_EQ(childCategory.toString(), QStringLiteral("settings"));

  childCategory = childCategory.getChildCategory();
  EXPECT_EQ(childCategory.getSeparator(), category.getSeparator());
  EXPECT_EQ(childCategory.toString(), QStringLiteral(""));
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

/*** End of file StorageCategory_Test.cpp ***/
