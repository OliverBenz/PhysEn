#include "MatrixSolver.hpp"

namespace PhysEn {
namespace Maths {

bool makeUpperTriangle(Matrix& matrix){
	if (!matrix.getSize().isSquare())
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

bool solveEquation(Matrix& components, Vector& result){
    if (components.getSize().rows != result.getSize())
        return false;

    float diagonal;

    size_t n = components.getSize().rows;

    for (size_t i = 0; i < n; i++){
        // Divide the i-th row by the diagonal element
        diagonal = components[i][i];
        for(size_t j = i; j < n; j++){
            components[i][j] /= diagonal;
        }

        // Divide the i-th known term by the diagonal element
        result[i] /= diagonal;

        // Subtract the normalized equation from all the other rows of the components
        for(size_t k = i + 1; k < n; k++){
            diagonal = components[k][i];

            for(size_t j = i; j < n; j++)
                components[k][j] -= components[i][j] * diagonal;

            // Do the same also for the known terms
            result[k] -= diagonal * result[i];
        }
    }

    // TODO: Finish here
    /*
    double sum = 0;
    for (int k = n-1; k >= 0; k--) {
        sum = 0;
        for (int i = k+1; i < n; i++)
            sum += components[k][i] * x[i];

        x[k] = b[k] - sum;
    }
    */
    return true;
}

}
}