/**
 * \proj Библиотека вспомогательных компонентов С++ (auxiliary-cpp)
 * \file Файл исходного кода Vector2D_Test.cpp
 * \brief Тесты класса Vector2D
 *
 * Copyright (c) 2022 Rodion Kolovanov
 */

#include <auxiliary-cpp/math/Vector2D.h>
#include <gtest/gtest.h>

namespace Auxiliary::Math
{
  Vector2D<> vector = {3.0, 4.0};
  Vector2D<> vector2 = {2.0};

  TEST(Vector3D_Test, Components)
  {
    EXPECT_FLOAT_EQ(vector.x, 3.0);
    EXPECT_FLOAT_EQ(vector.y, 4.0);

    EXPECT_FLOAT_EQ(vector2.x, 2.0);
    EXPECT_FLOAT_EQ(vector2.y, 2.0);
  }

  TEST(Vector3D_Test, Length)
  {
    EXPECT_FLOAT_EQ(vector.length(), sqrt(vector.squaredLength()));
    EXPECT_FLOAT_EQ(vector.squaredLength(), 25.0);
  }

  TEST(Vector3D_Test, Equal)
  {
    EXPECT_TRUE(vector.equal(vector));
    EXPECT_FALSE(vector.equal(Vector2D<>::Zero));
    EXPECT_TRUE(Vector2D<>::equal(vector, vector));
    EXPECT_FALSE(Vector2D<>::equal(vector, Vector2D<>::Zero));
    EXPECT_TRUE(vector == vector);
    EXPECT_FALSE(vector == Vector2D<>::UnitX);
    EXPECT_TRUE(vector != Vector2D<>::UnitY);
    EXPECT_FALSE(vector != vector);
  }

  TEST(Vector3D_Test, Negate)
  {
    EXPECT_EQ(-vector, Vector2D<>(-3.0, -4.0));
  }

  TEST(Vector3D_Test, Addition)
  {
    EXPECT_EQ(vector + vector, Vector2D<>(6.0, 8.0));
  }

  TEST(Vector3D_Test, Subtraction)
  {
    EXPECT_EQ(vector - vector, Vector2D<>::Zero);
  }

  TEST(Vector3D_Test, ScalarMultiplication)
  {
    EXPECT_EQ(vector * 2.0, Vector2D<>(6.0, 8.0));
  }

  TEST(Vector3D_Test, ScalarDivision)
  {
    EXPECT_EQ(vector / 2.0, Vector2D<>(1.5, 2.0));
  }

  TEST(Vector3D_Test, Normalize)
  {
    const auto normalizedVector = vector.normalize();
    EXPECT_FLOAT_EQ(normalizedVector.length(), 1.0);
    EXPECT_TRUE(vector.x / normalizedVector.x == vector.y / normalizedVector.y);
  }

  TEST(Vector3D_Test, DotProduct)
  {
    EXPECT_EQ(vector.dot(vector), Vector2D<>(9.0, 16.0));
    EXPECT_EQ(Vector2D<>::dotProduct(vector, vector), Vector2D<>(9.0, 16.0));
  }
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
