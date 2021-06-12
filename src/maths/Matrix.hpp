#pragma once

#include "../common/Size.hpp"
#include <ostream>
#include <vector>

namespace PhysEn{
namespace Maths{

enum class MatrixType {Unity, Random, Zero};

/**
 * @brief Mathematical Matrix implementation.
 */
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
	explicit Matrix(Size size);

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
	 * @brief Returns a new Matrix with the specified row/column removed.
	 * @note Start at row and column number 0!
	 *
	 * @param deleteRow Row to be deleted. Range[0, rowCount-1]
	 * @param deleteColumn Column to be deleted. Range[0, colCount-1]
	 * @return Matrix with specified row and column deleted.
	 */
	Matrix getSubMatrix(size_t deleteRow, size_t deleteColumn);

	/**
	 * @return Determinant of the matrix.
	 */
	float getDeterminant();

	/**
	 * @return Dimensions of the matrix.
	 */
	inline Size& getSize()
	{ return size; };

	/**
	 * @return Is the matrix invertible or not.
	 */
	inline bool isInvertible()
	{ return getDeterminant() != 0; };

	// Operators
	float* operator[](size_t row);
	friend Matrix operator*(const float left, Matrix& right);
	friend Matrix operator*(Matrix& left, float right);
	friend Matrix operator*(Matrix& left, Matrix& right);
	friend Matrix& operator*=(Matrix& left, const float right);

	friend bool operator==(Matrix& left, Matrix& right);
	
	friend std::ostream& operator <<(std::ostream& os, Matrix& m);
};

}
}