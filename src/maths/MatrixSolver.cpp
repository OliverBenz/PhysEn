#include "MatrixSolver.hpp"

namespace PhysEn {
namespace Maths {

bool makeUpperTriangle(Matrix& matrix){
	if (! matrix.getSize().isSquare())
		return false;

	// float* b = (float*)calloc(matrix.getDimensions().rows, sizeof(float));
	float diagonal;

	size_t n = matrix.getSize().rows;

	for (size_t i = 0; i < n; i++){
		// Divide the i-th row by the diagonal element
		diagonal = matrix[i][i];
		for(size_t j = i; j < n; j++){
			matrix[i][j] /= diagonal;
		}

		// Divide the i-th known term by the diagonal element
	  	// b[i] /= diagonal;

		// Subtract the normalized equation from all the other rows of the matrix
	  	for(size_t k = i + 1; k < n; k++){
			diagonal = matrix[k][i];

	  	  	for(size_t j = i; j < n; j++)
				matrix[k][j] -= matrix[i][j] * diagonal;

	  	  	// Do the same also for the known terms
	  	  	// b[k] -= diagonal * b[i];
	  	}
	}

	return true;
}

}
}