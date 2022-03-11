#include "gtest/gtest.h"

#include "maths/vector.hpp"

namespace PhysEn {
namespace GTest {

template <std::size_t S>
using Vector = Maths::Vector<double, S>;

TEST(Vector, CrossProduct) {
	{   // Positive test
		Vector<3> vectorA{2, 3, 4};
		Vector<3> vectorB{5, 6, 7};
		Vector<3> vectorC = Vector<3>::crossProduct(vectorA, vectorB);

		ASSERT_EQ(vectorC[0], -3);
		ASSERT_EQ(vectorC[1], 6);
		ASSERT_EQ(vectorC[2], -3);

		vectorA = Vector<3>{-1, 2, 1};
		vectorB = Vector<3>{1, 0, -1};
		vectorC = Vector<3>::crossProduct(vectorA, vectorB);

		ASSERT_EQ(vectorC[0], -2);
		ASSERT_EQ(vectorC[1], 0);
		ASSERT_EQ(vectorC[2], -2);
	}
}

TEST(Vector, Length) {
	Vector<3> vectorStandard{2, 3, 4};
	EXPECT_NEAR(Maths::normTwo(vectorStandard), 5.385, 0.001);

	Vector<8> vectorCustom{2, 5, -2.43, -5.55, 0, -4, 2.77, 7};
	EXPECT_NEAR(Maths::normTwo(vectorCustom), 11.76351563, 0.00001);

	Vector<4> vectorZero{0, 0, 0, 0};
	EXPECT_NEAR(Maths::normTwo(vectorZero), 0, 0.00001);
}

TEST(Vector, Operators) {
	{   // Equality
		Vector<3> vectorA{1, 1, 2};
		Vector<3> vectorB{1, 1, 2};

		EXPECT_EQ(vectorA, vectorB);
		EXPECT_FALSE(vectorA != vectorB);
		vectorA[1] += 1;

		EXPECT_FALSE(vectorA == vectorB);
		EXPECT_TRUE(vectorA != vectorB);
	}

	{   // Addition / Subtraction
		Vector<3> vectorA{0, 4, -2};
		Vector<3> vectorB{1, -3, 2};
		EXPECT_EQ(vectorA + vectorB, Vector<3>({1, 1, 0}));
		EXPECT_EQ(vectorA - vectorB, Vector<3>({-1, 7, -4}));
	}

	{   // Vector multiplication
		Vector<3> vectorA{-3.0,  4.1, -2.7};
		Vector<3> vectorB{ 1.3, -3.0,  2.5};

		EXPECT_NEAR(vectorA * vectorB, -22.95, 0.01);
		EXPECT_NEAR(vectorA * vectorA, 33.1, 0.01);
		EXPECT_NEAR(vectorB * vectorB, 16.94, 0.01);
	}

	{   // Scalar multiplication
		Vector<3> vector{2.3, 0, -9.443};
		vector *= 6.4;

		EXPECT_NEAR(vector[0], 14.72, 0.001);
		EXPECT_NEAR(vector[1], 0, 0.001);
		EXPECT_NEAR(vector[2], -60.4352, 0.0001);
	}
}

TEST(Vector, Norms) {
	Vector<4> vector{2, 5, 6, 3};
	EXPECT_NEAR(Maths::normTwo(vector), 8.602325267, 0.0001);
	EXPECT_NEAR(Maths::normSupremum(vector), 6, 0.0001);
}

} // namespace GTest
} // namespace PhysEn
