#include "Integration.hpp"

#include <array>

namespace PhysEn {
namespace Maths {

// TODO: Calculate the amount values based on function and interval
static constexpr int AMOUNT_VALUES = 200000;


/**
 * @brief Split the integration area into specific sub-areas.
 * @param limitA  [in]  Lower bound integration limit.
 * @param limitB  [in]  Upper bound integration limit.
 * @param xValues [out] Vector containing resulting areas.
 */
static void generateXValues(double limitA, double limitB, std::array<double, AMOUNT_VALUES> &xValues) {
	double distance = (limitB - limitA) / (double) AMOUNT_VALUES;

	for (int i = 0; i < AMOUNT_VALUES; i++)
		xValues[i] = limitA + i * distance + (distance / 2);
}

/**
 * @brief Calculate integral using trapezoid rule with given value pairs.
 * @param xValues x-Values of the function.
 * @param yValues y-Values of the function. (Corresponding to x-Values)
 * @return Result of integral.
 */
static double compute_integral(std::array<double, AMOUNT_VALUES> &xValues,
                               std::array<double, AMOUNT_VALUES> &yValues) {
	double result = 0;

	for (int i = 0; i < AMOUNT_VALUES - 1; i++)
		result += (xValues[i + 1] - xValues[i]) * 0.5f * (yValues[i] + yValues[i + 1]);

	return result;
}

// TODO: Store values as std::array<std::pair<double, double>, AMOUNT_VALUES> ??
double integrate(double (*function)(double x), double limitA, double limitB) {
	std::array<double, AMOUNT_VALUES> xValues = {};
	std::array<double, AMOUNT_VALUES> yValues = {};

	// Calculate x values
	generateXValues(limitA, limitB, xValues);

	// Calculate y values from passed function
	for(int i = 0; i < AMOUNT_VALUES; i++)
		yValues[i] = (*function)(xValues[i]);

	return compute_integral(xValues, yValues);
}


}
}