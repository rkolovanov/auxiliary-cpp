/**
 * \proj Библиотека вспомогательных компонентов С++ (auxiliary-cpp)
 * \file Файл исходного кода Matrix4x4_Test.cpp
 * \brief Тесты класса Matrix4x4
 *
 * Copyright (c) 2022 Rodion Kolovanov
 */

#include <auxiliary-cpp/math/Matrix4x4.h>
#include <gtest/gtest.h>

namespace Auxiliary::Math
{
  TEST(Matrix4x4_Test, Constants)
  {
    ASSERT_EQ(Matrix4x4<>::Rows, 4);
    ASSERT_EQ(Matrix4x4<>::Columns, 4);

    const auto zero = Matrix4x4<>::Zero;
    for (int i = 0; i < zero.Rows; ++i)
    {
      for (int j = 0; j < zero.Columns; ++j)
      {
        EXPECT_FLOAT_EQ(zero.get(i, j), 0);
      }
    }

    const auto identity = Matrix4x4<>::Identity;
    for (int i = 0; i < identity.Rows; ++i)
    {
      for (int j = 0; j < identity.Columns; ++j)
      {
        EXPECT_FLOAT_EQ(identity.get(i, j) == 1, i == j);
      }
    }
  }
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
