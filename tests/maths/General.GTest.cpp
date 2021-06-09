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
	EXPECT_NEAR(Maths::integrate(functionOne, 0, 1),
				functionOneReal(0, 1), 0.0001);

	double result = Maths::integrate(functionTwo, 0, 12);
	EXPECT_NEAR(result,
	            functionTwoReal(0, 12), 0.01);

}