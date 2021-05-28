#include "gtest/gtest.h"

#include "../../src/maths/Vector.hpp"

using namespace PhysEn;

TEST(Vector, CrossProduct) {
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

TEST(Vector, Length) {
	Maths::Vector vector({2, 3, 4});

	ASSERT_NEAR(vector.getLength(), 5.385, 0.001);
}

TEST(Vector, Operators) {
	{   // Equality
		Maths::Vector vectorA({1, 1, 2});
		Maths::Vector vectorB({1, 1, 2});

		EXPECT_EQ(vectorA, vectorB);
		EXPECT_EQ(vectorA != vectorB, false);
		vectorA[1] += 1;

		EXPECT_EQ(vectorA == vectorB, false);
		EXPECT_EQ(vectorA != vectorB, true);
	}

	{   // Addition / Subtraction
		Maths::Vector vectorA({0, 4, -2});
		Maths::Vector vectorB({1, -3, 2});

		EXPECT_EQ(vectorA + vectorB, Maths::Vector({1, 1, 0}));
		EXPECT_EQ(vectorA - vectorB, Maths::Vector({-1, 7, -4}));
	}

	{   // Multiplication
		Maths::Vector vectorA({-3, 4, -2});
		Maths::Vector vectorB({1, -3, 2});

		EXPECT_EQ(vectorA * vectorB, -19);
		EXPECT_EQ(vectorA * vectorA, 29);
		EXPECT_EQ(vectorB * vectorB, 14);
	}
}