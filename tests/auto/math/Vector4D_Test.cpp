/**
 * \proj Библиотека вспомогательных компонентов С++ (auxiliary-cpp)
 * \file Файл исходного кода Vector4D_Test.cpp
 * \brief Тесты класса Vector4D
 *
 * Copyright (c) 2022 Rodion Kolovanov
 */

#include <auxiliary-cpp/math/Vector4D.h>
#include <gtest/gtest.h>

namespace Auxiliary::Math
{
  Vector4D<> vector = {2.0, 4.0, 4.0, 3.0};
  Vector4D<> vector2 = {2.0};

  TEST(Vector4D_Test, Components)
  {
    EXPECT_EQ(vector.x, 2.0);
    EXPECT_EQ(vector.y, 4.0);
    EXPECT_EQ(vector.z, 4.0);
    EXPECT_EQ(vector.w, 3.0);

    EXPECT_EQ(vector2.x, 2.0);
    EXPECT_EQ(vector2.y, 2.0);
    EXPECT_EQ(vector2.z, 2.0);
    EXPECT_EQ(vector2.w, 2.0);
  }

  TEST(Vector4D_Test, Length)
  {
    EXPECT_EQ(vector.length(), sqrt(vector.squaredLength()));
    EXPECT_EQ(vector.squaredLength(), 45.0);
  }

  TEST(Vector4D_Test, Equal)
  {
    EXPECT_TRUE(vector.equal(vector));
    EXPECT_FALSE(vector.equal(Vector4D<>::Zero));
    EXPECT_TRUE(Vector4D<>::equal(vector, vector));
    EXPECT_FALSE(Vector4D<>::equal(vector, Vector4D<>::UnitX));
    EXPECT_TRUE(vector == vector);
    EXPECT_FALSE(vector == Vector4D<>::UnitZ);
    EXPECT_TRUE(vector != Vector4D<>::UnitY);
    EXPECT_FALSE(vector != vector);
  }

  TEST(Vector4D_Test, Negate)
  {
    EXPECT_EQ(-vector, Vector4D<>(-2.0, -4.0, -4.0, -3.0));
  }

  TEST(Vector4D_Test, Addition)
  {
    EXPECT_EQ(vector + vector, Vector4D<>(4.0, 8.0, 8.0, 6.0));
  }

  TEST(Vector4D_Test, Subtraction)
  {
    EXPECT_EQ(vector - vector, Vector4D<>::Zero);
  }

  TEST(Vector4D_Test, ScalarMultiplication)
  {
    EXPECT_EQ(vector * 2.0, Vector4D<>(4.0, 8.0, 8.0, 6.0));
  }

  TEST(Vector4D_Test, ScalarDivision)
  {
    EXPECT_EQ(vector / 2.0, Vector4D<>(1.0, 2.0, 2.0, 1.5));
  }

  TEST(Vector4D_Test, Normalize)
  {
    const auto normalizedVector = vector.normalize();
    EXPECT_FLOAT_EQ(vector.normalize().length(), 1.0);
    EXPECT_TRUE(vector.x / normalizedVector.x == vector.y / normalizedVector.y &&
                vector.x / normalizedVector.x == vector.z / normalizedVector.z &&
                vector.x / normalizedVector.x == vector.w / normalizedVector.w);
  }
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
