#include <gtest/gtest.h>

#include "maths/complex.hpp"

namespace phys::gtest {

TEST(ComplexNumbers, Construct) {
	{   // Default
		complex complex;
		EXPECT_EQ(complex.real(), 0);
		EXPECT_EQ(complex.imag(), 0);
	}

	{   // Standard
		complex complex(1.23, 5.45);
		EXPECT_NEAR(complex.real(), 1.23, 0.0001);
		EXPECT_NEAR(complex.imag(), 5.45, 0.0001);
	}

	{   // Initializer List
		complex complex{1.23, 5.45};
		EXPECT_NEAR(complex.real(), 1.23, 0.0001);
		EXPECT_NEAR(complex.imag(), 5.45, 0.0001);
	}
}

TEST(ComplexNumbers, Operators) {
	{   // Multiplication
		complex number{1.23, 5.45};
		complex complexOne{4.5, 3.1};

		// number * number
		complex result = number * complexOne;
		EXPECT_NEAR(result.real(), -11.36, 0.0001);
		EXPECT_NEAR(result.imag(), 28.338, 0.0001);

		// *= number
		number *= complexOne;
		EXPECT_NEAR(number.real(), -11.36, 0.0001);
		EXPECT_NEAR(number.imag(), 28.338, 0.0001);

		// *= double
		complexOne *= -6.2;
		EXPECT_NEAR(complexOne.real(), -27.9, 0.0001);
		EXPECT_NEAR(complexOne.imag(), -19.22, 0.0001);

		// double * number
		complex multiplier(2, 5);
		complex resultNew = 2.4 * multiplier;
		EXPECT_NEAR(resultNew.real(), 4.8, 0.0001);
		EXPECT_NEAR(resultNew.imag(), 12, 0.0001);

		// number * double
		complex resultNewNew = multiplier * 2.4;
		EXPECT_NEAR(resultNewNew.real(), 4.8, 0.0001);
		EXPECT_NEAR(resultNewNew.imag(), 12, 0.0001);
	}

	{   // Division
		complex number{1.23, 5.45};
		complex complexOne{4.5, 3.1};

		// number / number
		complex result = number / complexOne;
		EXPECT_NEAR(result.real(), 0.751172137, 0.0001);
		EXPECT_NEAR(result.imag(), 0.693636973, 0.0001);

		// /= number
		number /= complexOne;
		EXPECT_NEAR(number.real(), 0.751172137, 0.0001);
		EXPECT_NEAR(number.imag(), 0.693636973, 0.0001);

		// /= double
		complexOne /= -6.2;
		EXPECT_NEAR(complexOne.real(), -0.7258, 0.0001);
		EXPECT_NEAR(complexOne.imag(), -0.5, 0.0001);

		// double / number
		complex divisor(2, 5);
		complex resultNew = 2.4 / divisor;
		EXPECT_NEAR(resultNew.real(), 0.1655, 0.0001);
		EXPECT_NEAR(resultNew.imag(), -0.4138, 0.0001);

		// number / double
		complex resultNewNew = divisor / 2.4;
		EXPECT_NEAR(resultNewNew.real(), 0.8333, 0.0001);
		EXPECT_NEAR(resultNewNew.imag(), 2.0833, 0.0001);

		// Division by zero
		complex resZero{4, 6};
		complex zero{0, 0};
		EXPECT_THROW(resZero / zero, std::invalid_argument);
		EXPECT_THROW(resZero / 0.0f, std::invalid_argument);
		EXPECT_THROW(7.6f / zero, std::invalid_argument);
		EXPECT_THROW(resZero /= zero, std::invalid_argument);
		EXPECT_THROW(resZero /= 0.0f, std::invalid_argument);
	}

	{   // Addition
		complex number{1.23, 5.45};
		complex complexOne{4.5, 3.1};

		// number * number
		complex result = number + complexOne;
		EXPECT_NEAR(result.real(), 5.73, 0.0001);
		EXPECT_NEAR(result.imag(), 8.55, 0.0001);

		// += number
		number += complexOne;
		EXPECT_NEAR(number.real(), 5.73, 0.0001);
		EXPECT_NEAR(number.imag(), 8.55, 0.0001);

		// += double
		complexOne += 6.2;
		EXPECT_NEAR(complexOne.real(), 10.7, 0.0001);
		EXPECT_NEAR(complexOne.imag(), 3.1, 0.0001);

		// double + number
		complex apply(2, 5);
		complex resultNew = 2.4 + apply;
		EXPECT_NEAR(resultNew.real(), 4.4, 0.0001);
		EXPECT_NEAR(resultNew.imag(), 5, 0.0001);

		// number + double
		complex resultNewNew = apply + 2.4;
		EXPECT_NEAR(resultNewNew.real(), 4.4, 0.0001);
		EXPECT_NEAR(resultNewNew.imag(), 5, 0.0001);
	}

	{   // Subtraction
		complex number{1.23, 5.45};
		complex complexOne{4.5, 3.1};

		// number - number
		complex result = number - complexOne;
		EXPECT_NEAR(result.real(), -3.27, 0.0001);
		EXPECT_NEAR(result.imag(), 2.35, 0.0001);

		// -= number
		number -= complexOne;
		EXPECT_NEAR(number.real(), -3.27, 0.0001);
		EXPECT_NEAR(number.imag(), 2.35, 0.0001);

		// -= double
		complexOne -= 6.2;
		EXPECT_NEAR(complexOne.real(), -1.7, 0.0001);
		EXPECT_NEAR(complexOne.imag(), 3.1, 0.0001);

		// double - number
		complex subtract(2, 5);
		complex resultNew = 2.4 - subtract;
		EXPECT_NEAR(resultNew.real(), 0.4, 0.0001);
		EXPECT_NEAR(resultNew.imag(), 5, 0.0001);

		// number - double
		complex resultNewNew = subtract - 2.4;
		EXPECT_NEAR(resultNewNew.real(), -0.4, 0.0001);
		EXPECT_NEAR(resultNewNew.imag(), 5, 0.0001);
	}

	{   // Equality
		complex first{1, 4};
		complex second{1, 4};
		complex third{1, 0};
		complex fourth{3, 4};
		complex zero{0, 0};

		// complex
		EXPECT_TRUE(first == second);
		EXPECT_FALSE(first == third);
		EXPECT_FALSE(first == fourth);
		EXPECT_FALSE(third == fourth);

		// Number compare
		EXPECT_FALSE(first == 1);
		EXPECT_FALSE(1 == second);
		EXPECT_TRUE(1 == third);
		EXPECT_TRUE(third == 1);
		EXPECT_TRUE(zero == 0);
	}
}

TEST(ComplexNumbers, Functions) {
	{   // Getter / Setter
		complex complex{1.2, 2.46};
		EXPECT_EQ(complex.real(), complex.real());
		EXPECT_EQ(complex.imag(), complex.imag());

		complex.real() = 4.4;
		complex.imag() = 6.3;

		EXPECT_NEAR(complex.real(), 4.4, 0.0001);
		EXPECT_NEAR(complex.imag(), 6.3, 0.0001);
	}
}

TEST(ComplexNumbers, Norms) {
	complex complex{3.53, 5.22};
	EXPECT_NEAR(normTwo(complex), 6.30153156, 0.0001);
	EXPECT_NEAR(normSupremum(complex), 5.22, 0.0001);
}

}
