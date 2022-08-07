/**
 * \proj Библиотека вспомогательных решений С++ (auxiliary-cpp)
 * \file Файл исходного кода Vector3D_Test.cpp
 * \brief Тесты класса Vector3D
 *
 * Copyright (c) 2022 Rodion Kolovanov
 */

#include <auxiliary-cpp/math/Vector3D.h>
#include <gtest/gtest.h>

namespace Auxiliary::Math
{
  Vector3D vector = {2.0, 4.0, 4.0};

  TEST(Vector3D_Test, Components)
  {
    EXPECT_EQ(vector.x(), 2.0);
    EXPECT_EQ(vector.y(), 4.0);
    EXPECT_EQ(vector.z(), 4.0);
  }

  TEST(Vector3D_Test, Length)
  {
    EXPECT_EQ(vector.length(), 6.0);
    EXPECT_EQ(vector.squaredLength(), 36.0);
  }

  TEST(Vector3D_Test, Equal)
  {
    EXPECT_TRUE(vector.equal(vector));
    EXPECT_FALSE(vector.equal(Vector3D::ZeroVector));

    EXPECT_TRUE(vector == vector);
    EXPECT_FALSE(vector == Vector3D::UpVector);
    EXPECT_TRUE(vector != Vector3D::RightVector);
    EXPECT_FALSE(vector != vector);
  }

  TEST(Vector3D_Test, Negate)
  {
    EXPECT_EQ(-vector, Vector3D(-2.0, -4.0, -4.0));
  }

  TEST(Vector3D_Test, Addition)
  {
    EXPECT_EQ(vector + vector, Vector3D(4.0, 8.0, 8.0));
  }

  TEST(Vector3D_Test, Subtraction)
  {
    EXPECT_EQ(vector - vector, Vector3D::ZeroVector);
  }

  TEST(Vector3D_Test, ScalarMultiplication)
  {
    EXPECT_EQ(vector * 2.0, Vector3D(4.0, 8.0, 8.0));
  }

  TEST(Vector3D_Test, ScalarDivision)
  {
    EXPECT_EQ(vector / 2.0, Vector3D(1.0, 2.0, 2.0));
  }

  TEST(Vector3D_Test, Normalize)
  {
    EXPECT_EQ(vector.normalize().length(), 1.0);
  }

  TEST(Vector3D_Test, DotProduct)
  {
    EXPECT_EQ(vector.dot(vector), Vector3D(4.0, 16.0, 16.0));
  }

  TEST(Vector3D_Test, CrossProduct)
  {
    EXPECT_EQ(vector.cross(vector).dot(vector), Vector3D::ZeroVector);
  }
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
