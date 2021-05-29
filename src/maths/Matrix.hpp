#pragma once

#include "../common/Size.hpp"
#include <ostream>
#include <vector>

namespace PhysEn{
namespace Maths{

enum class MatrixType {Unity, Random, Zero};

class Matrix{
	Size size = Size();
	float** values = nullptr;

public:
	/**
	 * @brief Construct a non-initialized zero-sized matrix.
	 */
	Matrix() = default;

	/**
	 * @brief Construct and initialize matrix of size 'size'.
	 * @param size Dimension of the matrix.
	 */
	Matrix(Size size);

	/**
	 * @brief Construct and initialize matrix of size 'size'.
	 * @param size Dimension of the matrix.
	 * @param type Standard matrix type. (Unity, Zero, Random)
	 */
	Matrix(Size size, MatrixType type);

	/**
	 * @brief Construct and initialize matrix of size 'size'.
	 * @param size Dimension of the matrix.
	 * @param list Values to be stored in the matrix. (Has to match 'size')
	 */
	Matrix(Size size, std::vector<std::vector<float>> list);
	~Matrix();

	/**
	 * @return Determinant of the matrix.
	 */
	float getDeterminant();

	/**
	 * @return Dimensions of the matrix.
	 */
	inline Size& getSize(){ return size; }

	/**
	 * @return Is the matrix invertible or not.
	 */
	inline bool isInvertible(){ return getDeterminant() != 0; };

	// Operators
	float* operator[](size_t row);
	friend Matrix operator*(float left, Matrix& right);
	friend Matrix operator*(Matrix& left, float right);
	friend Matrix operator*(Matrix& left, Matrix& right);
	friend Matrix& operator*=(Matrix& left, float right);

	friend bool operator==(Matrix& left, Matrix& right);
	
	friend std::ostream& operator <<(std::ostream& os, Matrix& m);
};

}
}