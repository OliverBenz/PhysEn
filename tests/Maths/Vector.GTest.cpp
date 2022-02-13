#include "gtest/gtest.h"

#include "Maths/Vector.hpp"

namespace PhysEn::GTest {

TEST(Vector, CrossProduct) {
	{   // Positive test
		Maths::Vector vectorA({2, 3, 4});
		Maths::Vector vectorB({5, 6, 7});
		Maths::Vector vectorC = vectorA.getCrossProduct(vectorB);

		ASSERT_EQ(vectorC[0], -3);
		ASSERT_EQ(vectorC[1], 6);
		ASSERT_EQ(vectorC[2], -3);

		vectorA = Maths::Vector({-1, 2, 1});
		vectorB = Maths::Vector({1, 0, -1});
		vectorC = vectorA.getCrossProduct(vectorB);

		ASSERT_EQ(vectorC[0], -2);
		ASSERT_EQ(vectorC[1], 0);
		ASSERT_EQ(vectorC[2], -2);
	}

	{   // Invalid sizes
		Maths::Vector vectorA({2, 3});
		Maths::Vector vectorC({5, 6});
		Maths::Vector vectorB({2, 4, 3});

		EXPECT_THROW(vectorA.getCrossProduct(vectorB), std::invalid_argument);
		EXPECT_THROW(vectorA.getCrossProduct(vectorC), std::logic_error);
	}
}

TEST(Vector, Length) {
	Maths::Vector vectorStandard({2, 3, 4});
	EXPECT_NEAR(vectorStandard.getLength(), 5.385, 0.001);

	Maths::Vector vectorCustom({2, 5, -2.43, -5.55, 0, -4, 2.77, 7});
	EXPECT_NEAR(vectorCustom.getLength(), 11.76351563, 0.00001);

	Maths::Vector vectorZero({0, 0, 0, 0});
	EXPECT_NEAR(vectorZero.getLength(), 0, 0.00001);
}

TEST(Vector, Operators) {
	{   // Equality
		Maths::Vector vectorA({1, 1, 2});
		Maths::Vector vectorB({1, 1, 2});

		EXPECT_EQ(vectorA, vectorB);
		EXPECT_FALSE(vectorA != vectorB);
		vectorA[1] += 1;

		EXPECT_FALSE(vectorA == vectorB);
		EXPECT_TRUE(vectorA != vectorB);

		Maths::Vector vectorLarge({3, 2, 1, 2});
		EXPECT_THROW(vectorA == vectorLarge, std::invalid_argument);
	}

	{   // Addition / Subtraction
		Maths::Vector vectorA({0, 4, -2});
		Maths::Vector vectorB({1, -3, 2});
		EXPECT_EQ(vectorA + vectorB, Maths::Vector({1, 1, 0}));
		EXPECT_EQ(vectorA - vectorB, Maths::Vector({-1, 7, -4}));

		// Vector dimensions dont' line up
		Maths::Vector vectorC({2, 3, 0, -7});
		EXPECT_THROW(vectorA + vectorC, std::invalid_argument);
		EXPECT_THROW(vectorA - vectorC, std::invalid_argument);
	}

	{   // Vector multiplication
		Maths::Vector vectorA({-3.0,  4.1, -2.7});
		Maths::Vector vectorB({ 1.3, -3.0,  2.5});

		EXPECT_NEAR(vectorA * vectorB, -22.95, 0.01);
		EXPECT_NEAR(vectorA * vectorA, 33.1, 0.01);
		EXPECT_NEAR(vectorB * vectorB, 16.94, 0.01);

		// Vector dimensions dont' line up
		Maths::Vector vectorC({2, 3, 0, -7});
		EXPECT_THROW(vectorA + vectorC, std::invalid_argument);
	}

	{   // Scalar multiplication
		Maths::Vector vector({2.3, 0, -9.443});
		vector *= 6.4;

		EXPECT_NEAR(vector[0], 14.72, 0.001);
		EXPECT_NEAR(vector[1], 0, 0.001);
		EXPECT_NEAR(vector[2], -60.4352, 0.0001);
	}
}

TEST(Vector, Norms) {
	Maths::Vector vector{2, 5, 6, 3};
	EXPECT_NEAR(Maths::normTwo(vector), 8.602325267, 0.0001);
	EXPECT_NEAR(Maths::normSupremum(vector), 6, 0.0001);
}

}