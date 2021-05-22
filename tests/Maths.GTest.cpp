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
}

TEST(Vector, Operators) {
    Maths::Vector vectorA(1, 1, 2);
    Maths::Vector vectorB(1, 1, 2);

    // Equality
    EXPECT_EQ(vectorA, vectorB);
    EXPECT_EQ(vectorA != vectorB, false);

    // Addition
    EXPECT_EQ(vectorA + vectorB, Maths::Vector(2, 2, 4));

    // Multiplication
    EXPECT_EQ(vectorB * vectorB, 6);
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