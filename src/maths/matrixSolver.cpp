#include "matrixSolver.hpp"

namespace PhysEn::Maths {

// TODO: Append to not require square matrix
bool makeUpperTriangle(Matrix& matrix){
	if (!matrix.getSize().isSquare())
		return false;

	double diagonal;
	size_t rowCount = matrix.getSize().rows;

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

}