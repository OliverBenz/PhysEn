#include <gtest/gtest.h>
#include "../../src/maths/Complex.hpp"

using namespace PhysEn;

TEST(ComplexNumbers, Construct) {
	{   // Default
		Maths::Complex complex;
		EXPECT_EQ(complex[0], 0);
		EXPECT_EQ(complex[1], 0);
	}

	{   // Standard
		Maths::Complex complex(1.23, 5.45);
		EXPECT_NEAR(complex[0], 1.23, 0.0001);
		EXPECT_NEAR(complex[1], 5.45, 0.0001);
	}

	{   // Initializer List
		Maths::Complex complex{1.23, 5.45};
		EXPECT_NEAR(complex[0], 1.23, 0.0001);
		EXPECT_NEAR(complex[1], 5.45, 0.0001);
	}
}

TEST(ComplexNumbers, Operators) {
	{   // Access
		Maths::Complex complex{1.23, 5.45};
		EXPECT_NEAR(complex[0], 1.23, 0.0001);
		EXPECT_NEAR(complex[1], 5.45, 0.0001);

		EXPECT_THROW(complex[-1], std::invalid_argument);
		EXPECT_THROW(complex[3], std::invalid_argument);
	}

	{   // Multiplication
		Maths::Complex complex{1.23, 5.45};
		Maths::Complex complexOne{4.5, 3.1};

		// Complex * Complex
		Maths::Complex result = complex * complexOne;
		EXPECT_NEAR(result[0], -11.36, 0.0001);
		EXPECT_NEAR(result[1], 28.338, 0.0001);

		// *= Complex
		complex *= complexOne;
		EXPECT_NEAR(complex[0], -11.36, 0.0001);
		EXPECT_NEAR(complex[1], 28.338, 0.0001);

		// *= double
		complexOne *= -6.2;
		EXPECT_NEAR(complexOne[0], -27.9, 0.0001);
		EXPECT_NEAR(complexOne[1], -19.22, 0.0001);

		// double * Complex
		Maths::Complex multiplier(2, 5);
		Maths::Complex resultNew = 2.4 * multiplier;
		EXPECT_NEAR(resultNew[0], 4.8, 0.0001);
		EXPECT_NEAR(resultNew[1], 12, 0.0001);

		// Complex * double
		Maths::Complex resultNewNew = multiplier * 2.4;
		EXPECT_NEAR(resultNewNew[0], 4.8, 0.0001);
		EXPECT_NEAR(resultNewNew[1], 12, 0.0001);
	}

	{   // Division
		Maths::Complex complex{1.23, 5.45};
		Maths::Complex complexOne{4.5, 3.1};

		// Complex / Complex
		Maths::Complex result = complex / complexOne;
		EXPECT_NEAR(result[0], 0.751172137, 0.0001);
		EXPECT_NEAR(result[1], 0.693636973, 0.0001);

		// /= Complex
		complex /= complexOne;
		EXPECT_NEAR(complex[0], 0.751172137, 0.0001);
		EXPECT_NEAR(complex[1], 0.693636973, 0.0001);

		// /= double
		complexOne /= -6.2;
		EXPECT_NEAR(complexOne[0], -0.7258, 0.0001);
		EXPECT_NEAR(complexOne[1], -0.5, 0.0001);

		// double / Complex
		Maths::Complex divisor(2, 5);
		Maths::Complex resultNew = 2.4 / divisor;
		EXPECT_NEAR(resultNew[0], 0.1655, 0.0001);
		EXPECT_NEAR(resultNew[1], -0.4138, 0.0001);

		// Complex / double
		Maths::Complex resultNewNew = divisor / 2.4;
		EXPECT_NEAR(resultNewNew[0], 0.8333, 0.0001);
		EXPECT_NEAR(resultNewNew[1], 2.0833, 0.0001);

		// Division by zero
		Maths::Complex resZero{4, 6};
		Maths::Complex zero{0, 0};
		EXPECT_THROW(resZero / zero, std::invalid_argument);
		EXPECT_THROW(resZero / 0.0f, std::invalid_argument);
		EXPECT_THROW(7.6f / zero, std::invalid_argument);
		EXPECT_THROW(resZero /= zero, std::invalid_argument);
		EXPECT_THROW(resZero /= 0.0f, std::invalid_argument);
	}

	{   // Addition
		Maths::Complex complex{1.23, 5.45};
		Maths::Complex complexOne{4.5, 3.1};

		// Complex * Complex
		Maths::Complex result = complex + complexOne;
		EXPECT_NEAR(result[0], 5.73, 0.0001);
		EXPECT_NEAR(result[1], 8.55, 0.0001);

		// += Complex
		complex += complexOne;
		EXPECT_NEAR(complex[0], 5.73, 0.0001);
		EXPECT_NEAR(complex[1], 8.55, 0.0001);

		// += double
		complexOne += 6.2;
		EXPECT_NEAR(complexOne[0], 10.7, 0.0001);
		EXPECT_NEAR(complexOne[1], 3.1, 0.0001);

		// double + Complex
		Maths::Complex apply(2, 5);
		Maths::Complex resultNew = 2.4 + apply;
		EXPECT_NEAR(resultNew[0], 4.4, 0.0001);
		EXPECT_NEAR(resultNew[1], 5, 0.0001);

		// Complex + double
		Maths::Complex resultNewNew = apply + 2.4;
		EXPECT_NEAR(resultNewNew[0], 4.4, 0.0001);
		EXPECT_NEAR(resultNewNew[1], 5, 0.0001);
	}

	{   // Subtraction
		Maths::Complex complex{1.23, 5.45};
		Maths::Complex complexOne{4.5, 3.1};

		// Complex - Complex
		Maths::Complex result = complex - complexOne;
		EXPECT_NEAR(result[0], -3.27, 0.0001);
		EXPECT_NEAR(result[1], 2.35, 0.0001);

		// -= Complex
		complex -= complexOne;
		EXPECT_NEAR(complex[0], -3.27, 0.0001);
		EXPECT_NEAR(complex[1], 2.35, 0.0001);

		// -= double
		complexOne -= 6.2;
		EXPECT_NEAR(complexOne[0], -1.7, 0.0001);
		EXPECT_NEAR(complexOne[1], 3.1, 0.0001);

		// double - Complex
		Maths::Complex subtract(2, 5);
		Maths::Complex resultNew = 2.4 - subtract;
		EXPECT_NEAR(resultNew[0], 0.4, 0.0001);
		EXPECT_NEAR(resultNew[1], 5, 0.0001);

		// Complex - double
		Maths::Complex resultNewNew = subtract - 2.4;
		EXPECT_NEAR(resultNewNew[0], -0.4, 0.0001);
		EXPECT_NEAR(resultNewNew[1], 5, 0.0001);
	}

	{   // Equality
		Maths::Complex first{1, 4};
		Maths::Complex second{1, 4};
		Maths::Complex third{1, 0};
		Maths::Complex fourth{3, 4};
		Maths::Complex zero{0, 0};

		// Complex
		EXPECT_EQ(first == second, true);
		EXPECT_EQ(first == third, false);
		EXPECT_EQ(first == fourth, false);
		EXPECT_EQ(third == fourth, false);

		// Number compare
		EXPECT_EQ(first == 1, false);
		EXPECT_EQ(1 == second, false);
		EXPECT_EQ(1 == third, true);
		EXPECT_EQ(third == 1, true);
		EXPECT_EQ(zero == 0, true);
	}
}

TEST(ComplexNumbers, Functions) {
	{   // Getter / Setter
		Maths::Complex complex{1.2, 2.46};
		EXPECT_EQ(complex[0], complex.getReal());
		EXPECT_EQ(complex[1], complex.getImaginary());

		complex.setReal(4.4);
		complex.setImaginary(6.3);

		EXPECT_NEAR(complex[0], 4.4, 0.0001);
		EXPECT_NEAR(complex[1], 6.3, 0.0001);
	}
}

TEST(ComplexNumbers, Norms) {
	Maths::Complex complex{3.53, 5.22};
	EXPECT_NEAR(Maths::normTwo(complex), 6.30153156, 0.0001);
	EXPECT_NEAR(Maths::normSupremum(complex), 5.22, 0.0001);
}
