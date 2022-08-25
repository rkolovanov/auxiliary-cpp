/**
 * \proj Библиотека вспомогательных компонентов С++ (auxiliary-cpp)
 * \file Файл исходного кода Vector3D_Test.cpp
 * \brief Тесты класса Vector3D
 *
 * Copyright (c) 2022 Rodion Kolovanov
 */

#include <auxiliary-cpp/math/Vector3D.h>
#include <gtest/gtest.h>

namespace Auxiliary::Math
{
  Vector3D<> vector = {2.0, 4.0, 4.0};
  Vector3D<> vector2 = {2.0};

  TEST(Vector3D_Test, Components)
  {
    EXPECT_EQ(vector.x, 2.0);
    EXPECT_EQ(vector.y, 4.0);
    EXPECT_EQ(vector.z, 4.0);

    EXPECT_EQ(vector2.x, 2.0);
    EXPECT_EQ(vector2.y, 2.0);
    EXPECT_EQ(vector2.z, 2.0);
  }

  TEST(Vector3D_Test, Length)
  {
    EXPECT_EQ(vector.length(), 6.0);
    EXPECT_EQ(vector.squaredLength(), 36.0);
  }

  TEST(Vector3D_Test, Equal)
  {
    EXPECT_TRUE(vector.equal(vector));
    EXPECT_FALSE(vector.equal(Vector3D<>::Zero));
    EXPECT_TRUE(Vector3D<>::equal(vector, vector));
    EXPECT_FALSE(Vector3D<>::equal(vector, Vector3D<>::UnitX));
    EXPECT_TRUE(vector == vector);
    EXPECT_FALSE(vector == Vector3D<>::UnitZ);
    EXPECT_TRUE(vector != Vector3D<>::UnitY);
    EXPECT_FALSE(vector != vector);
  }

  TEST(Vector3D_Test, Negate)
  {
    EXPECT_EQ(-vector, Vector3D<>(-2.0, -4.0, -4.0));
  }

  TEST(Vector3D_Test, Addition)
  {
    EXPECT_EQ(vector + vector, Vector3D<>(4.0, 8.0, 8.0));
  }

  TEST(Vector3D_Test, Subtraction)
  {
    EXPECT_EQ(vector - vector, Vector3D<>::Zero);
  }

  TEST(Vector3D_Test, ScalarMultiplication)
  {
    EXPECT_EQ(vector * 2.0, Vector3D<>(4.0, 8.0, 8.0));
  }

  TEST(Vector3D_Test, ScalarDivision)
  {
    EXPECT_EQ(vector / 2.0, Vector3D<>(1.0, 2.0, 2.0));
  }

  TEST(Vector3D_Test, Normalize)
  {
    const auto normalizedVector = vector.normalize();
    EXPECT_EQ(vector.normalize().length(), 1.0);
    EXPECT_TRUE(vector.x / normalizedVector.x == vector.y / normalizedVector.y &&
                vector.x / normalizedVector.x == vector.z / normalizedVector.z);
  }

  TEST(Vector3D_Test, DotProduct)
  {
    EXPECT_EQ(vector.dot(vector), Vector3D<>(4.0, 16.0, 16.0));
    EXPECT_EQ(Vector3D<>::dotProduct(vector, vector), Vector3D<>(4.0, 16.0, 16.0));
  }

  TEST(Vector3D_Test, CrossProduct)
  {
    EXPECT_EQ(vector.cross(vector).dot(vector), Vector3D<>::Zero);
    EXPECT_EQ(Vector3D<>::crossProduct(vector, vector).dot(vector), Vector3D<>::Zero);
  }
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
