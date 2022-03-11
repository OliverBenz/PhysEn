#pragma once

#include "matrix.hpp"
#include "vector.hpp"

namespace PhysEn {
namespace Maths {

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
template <std::size_t S>
Maths::Vector<double, S> solveEquation(Matrix& components, Vector<double, S>& result) {
	if (components.getSize().rows != result.size())
		throw std::invalid_argument("Result vector dimension does not line up with component row count!");

	double diagonal;
	size_t rowCount = components.getSize().rows;

	for (size_t i = 0; i < rowCount; i++){
		// Divide the i-th row by the diagonal element
		diagonal = components.at(i, i);
		for(size_t j = i; j < rowCount; j++){
			components.at(i, j) /= diagonal;
		}

		// Divide the i-th known term by the diagonal element
		result[i] /= diagonal;

		// Subtract the normalized equation from all the other rowCount of the components
		for(size_t k = i + 1; k < rowCount; k++){
			diagonal = components.at(k, i);

			for(size_t j = i; j < rowCount; j++)
				components.at(k, j) -= components.at(i, j) * diagonal;

			// Do the same also for the known terms
			result[k] -= diagonal * result[i];
		}
	}

	Maths::Vector<double, S> x;
	double sum = 0;
	// Index k is incremented for nested loop and will be -1 in the end!
	for (int k = (int)rowCount - 1; k >= 0; k--) {
		sum = 0;
		for (size_t i = k + 1; i < rowCount; i++)
			sum += components.at(k, i) * x[i];

		x[k] = result[k] - sum;
	}

	return x;
}

}
}