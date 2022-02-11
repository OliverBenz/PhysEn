#include "Matrix.hpp"

#include <stdexcept>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <limits>

namespace PhysEn{
namespace Maths{

//
// Constructors
//
Matrix::Matrix(Size size) : size{size} {
	values = std::vector<double>(size.rows*size.columns, 0);
}

Matrix::Matrix(Size size, MatrixType type) : size{size} {
	if(type == MatrixType::Unity && ! size.isSquare())
		throw std::invalid_argument("Unity matrix has to be square!");

	// Init Array
	values = std::vector<double>(size.rows * size.columns, 0);

	// Fill Array
	switch(type){
		case MatrixType::Unity:
			for(size_t i = 0; i < size.rows; i++)
				for(size_t j = 0; j < size.columns; j++)
					values[i * size.columns + j] = (i == j ? 1 : 0);
			break;

		case MatrixType::Random:
			std::generate(values.begin(), values.end(),
						  [](){return rand() % 20 + 1;});
			break;

		case MatrixType::Zero:
			std::fill(values.begin(), values.end(), 0);
			break;
	}
}

//Matrix::Matrix(Size size, std::initializer_list<double> list) : size(size), values(list)
//{}
Matrix::Matrix(std::initializer_list<std::initializer_list<double>> list){
	// rows -> Length list
	// cols -> Length of FIRST columns list
	size = Size(list.size(), list.begin()->size());

	// Check that all columns have same size
	for(auto li = list.begin(); li != list.end(); li++)
		if (li->size() != size.columns)
			throw std::invalid_argument("Not all rows share the same columns size!");

	// Initialize values vector
	values = std::vector<double>(size.rows * size.columns, 0);

	// Add all initializer lists to values vector
	auto valuesIterator = values.begin();
	for(size_t i = 0; i < list.size(); i++) {
		// TODO: CHeck if copy is best way of doing this
		std::copy(
				(list.begin() + i)->begin(),
				(list.begin() + i)->end(),
				valuesIterator
				);
		std::advance(valuesIterator, size.columns);
	}
}

//
// Class functions
//
double& Matrix::at(size_t row, size_t column) {
	if (row > size.rows)
		throw std::out_of_range("Row number exceeds matrix row count!");
	else if (column > size.columns)
		throw std::out_of_range("Column number exceeds matrix column count!");

	return values[row * size.columns + column];
}

Matrix Matrix::getSubMatrix(size_t deleteRow, size_t deleteColumn){
	if(deleteRow > size.rows - 1 || deleteColumn > size.columns - 1)
		throw std::invalid_argument("deleteRow/deleteColumn out of range! Start at row/column number 0!");

	Matrix result(Size(size.rows - 1, size.columns - 1));

	size_t resRow = 0;
	size_t resCol = 0;
	for(size_t i = 0; i < size.rows; i++){
		if(i == deleteRow)
			continue;

		resCol = 0;
		for(size_t j = 0; j < size.columns; j++){
			if(j == deleteColumn)
				continue;

			result.at(resRow, resCol) = values[i * size.columns + j];
			++resCol;
		}
		++resRow;
	}

	return result;
}

double Matrix::getDeterminant(){
	if (!size.isSquare())
		throw std::invalid_argument("Determinant cannot be calculated for a non-square matrix!");

	if (size == Size(2))
		return values[0] * values[3] - values[1] * values[2];

	// Check if row or columns has more 0-entries.
	// index > 0 : More 0 in columns.
	// index < 0 : More 0 in rows.
	int zeroIndex = 0;
	for(size_t i = 0; i < size.rows; i++) {
	    if (values[i * size.columns] == 0)
	        zeroIndex -= 1;
	    if (values[i] == 0)
	        zeroIndex += 1;
	}

	// Calculate determinant
	double sgn = 1.0;
	double determinant = 0.0f;
	if(zeroIndex >= 0) {
		for (size_t j = 0; j < size.columns; j++) {
			if(values[j] != 0)  // We can skip computation of any sub-matrix that would be multiplied by 0!
				determinant += sgn * values[j] * getSubMatrix(0, j).getDeterminant();
		    sgn = -sgn;
		}
	} else {
		for (size_t i = 0; i < size.rows; i++) {
			if(values[i * size.columns] != 0)  // We can skip computation of any sub-matrix that would be multiplied by 0!
				determinant += sgn * values[i * size.columns] * getSubMatrix(i, 0).getDeterminant();
		    sgn = -sgn;
		}
	}

	return determinant;
}

//
// Operators
//
Matrix operator*(const double left, Matrix& right){
	Matrix res(right.getSize());

	for(size_t i = 0; i < right.getSize().rows; i++){
		for(size_t j = 0; j < right.getSize().columns; j++){
			res.at(i, j) = right.at(i, j) * left;
		}
	}
	return res;
}

Matrix& operator*=(Matrix& left, const double right){
	for(size_t i = 0; i < left.getSize().rows; i++)
		for(size_t j = 0; j < left.getSize().columns; j++)
			left.at(i, j) *= right;

	return left;
}

Matrix operator*(Matrix& left, double right){
	return (right * left);
}

Matrix operator*(Matrix& left, Matrix& right){
	if(left.getSize().columns != right.getSize().rows)
		throw std::invalid_argument("Matrix sizes do not line up for multiplication!");

	Matrix result(Size(left.getSize().rows, right.getSize().columns));
	
	for(size_t res_i = 0; res_i < result.getSize().rows; res_i++){
		for(size_t res_j = 0; res_j < result.getSize().columns; res_j++){
			result.at(res_i, res_j) = 0;

			for(size_t r = 0; r < left.getSize().columns; r++)
				result.at(res_i, res_j) += left.at(res_i, r) * right.at(r, res_j);
		}
	}

	return result;
}

bool operator==(Matrix& left, Matrix& right){
	if(left.getSize() != right.getSize())
		return false;
	
	for(size_t row = 0; row < left.getSize().rows; row++)
		for(size_t col = 0; col < left.getSize().columns; col++)
			if(fabs(left.at(row, col) - right.at(row, col)) > std::numeric_limits<double>::epsilon())
				return false;
	
	return true;
}
bool operator!=(Matrix& left, Matrix& right){
	return !(left == right);
}

std::ostream& operator <<(std::ostream& os, Matrix& m){
	for(size_t i = 0; i < m.getSize().rows; i++){
		for(size_t j = 0; j < m.getSize().columns; j++)
			os << std::setw(4) << m.at(i, j);
		os << "\n";
	}
	return os;
}

}
}