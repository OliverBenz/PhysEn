#include "gtest/gtest.h"

#include "../src/maths/Vector.hpp"
#include "../src/maths/Matrix.hpp"

using namespace Physics;
/*
class MathsTests: public ::testing::Test {
    MathsTests() { }

    void SetUp() {

    }

    void TearDown() { }
};
*/

TEST(Vector, CrossProduct) {
    Maths::Vector vectorA(2, 3, 4);
    Maths::Vector vectorB(5, 6, 7);
    Maths::Vector vectorC = vectorA.getCrossProduct(vectorB);

    ASSERT_EQ(vectorC.x, -3);
    ASSERT_EQ(vectorC.y, 6);
    ASSERT_EQ(vectorC.z, -3);

    vectorA = Maths::Vector(-1, 2, 1);
    vectorB = Maths::Vector(1, 0, -1);
    vectorC = vectorA.getCrossProduct(vectorB);

    ASSERT_EQ(vectorC.x, -2);
    ASSERT_EQ(vectorC.y, 0);
    ASSERT_EQ(vectorC.z, -2);
}

TEST(Vector, Length) {
    Maths::Vector vector(2, 3, 4);

    ASSERT_NEAR(vector.getLength(), 5.385, 0.001);
}

TEST(Vector, Operators) {
    {   // Equality
        Maths::Vector vectorA(1, 1, 2);
        Maths::Vector vectorB(1, 1, 2);

        EXPECT_EQ(vectorA, vectorB);
        EXPECT_EQ(vectorA != vectorB, false);
        vectorA.y += 1;

        EXPECT_EQ(vectorA == vectorB, false);
        EXPECT_EQ(vectorA != vectorB, true);
    }
    
    {   // Addition / Subtraction
        Maths::Vector vectorA(0, 4, -2);
        Maths::Vector vectorB(1, -3, 2);

        EXPECT_EQ(vectorA + vectorB, Maths::Vector(1, 1, 0));
        EXPECT_EQ(vectorA - vectorB, Maths::Vector(-1, 7, -4));
    }

    {   // Multiplication
        Maths::Vector vectorA(-3, 4, -2);
        Maths::Vector vectorB(1, -3, 2);

        EXPECT_EQ(vectorA * vectorB, -19);
        EXPECT_EQ(vectorA * vectorA, 29);
        EXPECT_EQ(vectorB * vectorB, 14);
    }
}

TEST(Matrix, Calculations) {
    // TODO: Write tests

    Maths::Matrix m1(Maths::MatrixType::Unity, Size(5, 5));
    Maths::Matrix m2 = (float)2*m1;

    Maths::Matrix multOne(Maths::MatrixType::Random, Size(3,2));
    Maths::Matrix multTwo(Maths::MatrixType::Random, Size(2, 7));
    Maths::Matrix m3 = multOne * multTwo;

    EXPECT_EQ(true, true);
}