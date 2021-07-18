#pragma once

#include "../Common/Size.hpp"
#include <ostream>
#include <vector>
#include <initializer_list>

namespace PhysEn {
namespace Maths {

enum class MatrixType {Unity, Random, Zero};

/**
 * @brief Mathematical Matrix implementation.
 */
class Matrix{
	Size size = Size();
	std::vector<double> values;

public:
	// Constructors
	/**
	 * @brief Construct a zero-initialized zero-sized matrix.
	 */
	Matrix() = default;
	/**
	 * @brief Construct and zero-initialize matrix of size 'size'.
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
	 * @brief Construct and initialize matrix.
	 * @param list Values to be stored in the matrix.
	 */
	Matrix(std::initializer_list<std::initializer_list<double>> list);

	// Member functions
	double& at(size_t row, size_t column);

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
	double getDeterminant();

	/**
	 * @return Dimensions of the matrix.
	 */
	inline Size& getSize() { return size; };

	/**
	 * @return Is the matrix invertible or not.
	 */
	inline bool isInvertible() { return getDeterminant() != 0; };

	// Operators
	friend Matrix operator*(const double left, Matrix& right);
	friend Matrix operator*(Matrix& left, double right);
	friend Matrix operator*(Matrix& left, Matrix& right);
	friend Matrix& operator*=(Matrix& left, const double right);

	friend bool operator==(Matrix& left, Matrix& right);
	friend bool operator!=(Matrix& left, Matrix& right);

	friend std::ostream& operator <<(std::ostream& os, Matrix& m);
};

}
}