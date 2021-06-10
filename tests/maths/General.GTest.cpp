#include <gtest/gtest.h>

#include "../../src/maths/Integration.hpp"

using namespace PhysEn;

// y: R->R; x -> x^2 - 2x
static double functionOne(double x)
	{ return x*x*x*x - 2*x; }
static double functionOneReal(double a, double b)
	{ return (-a * a * a * a * a + 5 * a * a + b * b * b * b * b - 5 * b * b) / 5; }

// y: R->R; x -> x^2
static double functionTwo(double x)
	{ return x*x; }
static double functionTwoReal(double a, double b)
	{ return (1.0/3.0) * b*b*b - (1.0/3.0) * a*a*a; }


TEST(General, Integration) {
	{   // y: R->R; x -> x^2 - 2x
		// Standard
		EXPECT_NEAR(Maths::integrate(functionOne, 0, 1),
		            functionOneReal(0, 1), 0.0001);

		// Zero Bounds
		EXPECT_NEAR(Maths::integrate(functionOne, 0, 0),
		            functionOneReal(0, 0), 0.0001);

		// Reversed Bounds
		EXPECT_NEAR(Maths::integrate(functionOne, 1, 0),
		            functionOneReal(1, 0), 0.0001);
	}

	{   // y: R->R; x -> x^2
		// Standard
		EXPECT_NEAR(Maths::integrate(functionTwo, 0, 12),
		            functionTwoReal(0, 12), 0.01);

		// Reversed Bounds
		EXPECT_NEAR(Maths::integrate(functionTwo, 12, 0),
		            functionTwoReal(12, 0), 0.01);

		// Zero Bounds
		EXPECT_NEAR(Maths::integrate(functionTwo, 0, 0),
		            - functionTwoReal(0, 0), 0.01);
	}

	// TODO: Diverging functions
	// TODO: Large intervals
}