#include "MatrixSolver.hpp"

namespace PhysEn {
namespace Maths {

bool makeUpperTriangle(Matrix& matrix){
	if (!matrix.getSize().isSquare())
		return false;

	float diagonal;
	size_t rowCount = matrix.getSize().rows;

	for (size_t i = 0; i < rowCount; i++){
		// Divide the i-th row by the diagonal element
		diagonal = matrix[i][i];
		for(size_t j = i; j < rowCount; j++){
			matrix[i][j] /= diagonal;
		}

		// Subtract the normalized equation from all the other rowCount of the matrix
	  	for(size_t k = i + 1; k < rowCount; k++){
			diagonal = matrix[k][i];

	  	  	for(size_t j = i; j < rowCount; j++)
				matrix[k][j] -= matrix[i][j] * diagonal;
	  	}
	}

	return true;
}

Maths::Vector solveEquation(Matrix& components, Vector& result){
    if (components.getSize().rows != result.getSize())
        return false;

    float diagonal;
    size_t rowCount = components.getSize().rows;

    for (size_t i = 0; i < rowCount; i++){
        // Divide the i-th row by the diagonal element
        diagonal = components[i][i];
        for(size_t j = i; j < rowCount; j++){
            components[i][j] /= diagonal;
        }

        // Divide the i-th known term by the diagonal element
        result[i] /= diagonal;

        // Subtract the normalized equation from all the other rowCount of the components
        for(size_t k = i + 1; k < rowCount; k++){
            diagonal = components[k][i];

            for(size_t j = i; j < rowCount; j++)
                components[k][j] -= components[i][j] * diagonal;

            // Do the same also for the known terms
            result[k] -= diagonal * result[i];
        }
    }

    Maths::Vector x(result.getSize());
    float sum = 0;
    // Index k is incremented for nested loop and will be -1 in the end!
    for (int k = (int)rowCount - 1; k >= 0; k--) {
        sum = 0;
        for (size_t i = k + 1; i < rowCount; i++)
            sum += components[k][i] * x[i];

        x[k] = result[k] - sum;
    }

    return x;
}

}
}