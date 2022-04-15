#pragma once

#include "matrix.hpp"
#include "vector.hpp"

namespace phys::maths {

/**
 * @brief Converts a matrix into a upper triangle matrix using the Gaussian algorithm.
 * @param matrix[in,out] The matrix to be converted.
 * @return Conversion successful or not.
 */
template <std::size_t rows, std::size_t cols>
bool makeUpperTriangle(maths::Matrix<rows, cols>& matrix) {
        if (!matrix.isSquare())
            return false;

        double diagonal;
        size_t rowCount = matrix.rows();

        for (size_t i = 0; i < rowCount; i++){
            // Divide the i-th row by the diagonal element
            diagonal = matrix.at(i, i);
            for(size_t j = i; j < rowCount; j++){
                matrix.at(i, j) /= diagonal;
            }

            // Subtract the normalized equation from all the other rowCount of the matrix
            for(size_t k = i + 1; k < rowCount; k++){
                diagonal = matrix.at(k, i);

                for(size_t j = i; j < rowCount; j++)
                    matrix.at(k, j) -= matrix.at(i, j) * diagonal;
            }
        }

        return true;
    }

/**
 * @brief Solve a system of equations with component matrix and result vector.
 * @param components[in, out] Component matrix (Will be converted to upper-triangle matrix).
 * @param result[in, out] Result vector of the equation.
 * @return Result vector of the system of equations.
 */
template <std::size_t rows, std::size_t cols>
maths::Vector<double, cols> solveEquation(Matrix<rows, cols>& components, Vector<double, cols>& result) {
	if (components.rows() != result.size())
		throw std::invalid_argument("Result vector dimension does not line up with component row count!");

	double diagonal;
	size_t rowCount = components.rows();

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

	maths::Vector<double, cols> x;
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
