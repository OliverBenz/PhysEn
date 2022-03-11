#pragma once

namespace PhysEn {
namespace Maths {

// TODO: Find analytical solution
// TODO: Only solve numerically if no analytical solution can be found

/**
 * @brief Return approximate numerical solution for integral in area.
 * @param function Function to be integrated.
 * @param limitA Lower bound limit of integration.
 * @param limitB Upper bound limit of integration.
 * @return Numeric solution for integral.
 */
double integrate(double (*function)(double x), double limitA, double limitB);

}
}