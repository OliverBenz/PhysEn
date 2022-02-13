#pragma once
#include "Matrix.hpp"
#include "Vector.hpp"

namespace PhysEn::Maths {

/**
 * @brief Converts a matrix into a upper triangle matrix using the Gaussian algorithm.
 * @param matrix[in,out] The matrix to be converted.
 * @return Conversion successful or not.
 */
bool makeUpperTriangle(Maths::Matrix& matrix);

/**
 * @brief Solve a system of equations with component matrix and result vector.
 * @param components[in, out] Component matrix (Will be converted to upper-triangle matrix).
 * @param result[in, out] Result vector of the equation.
 * @return Result vector of the system of equations.
 */
Maths::Vector solveEquation(Matrix& components, Vector& result);

}