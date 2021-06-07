#include "Matrix.hpp"

#include <stdexcept>
#include <iomanip>
#include <algorithm>

namespace PhysEn{
namespace Maths{

//
// Constructors
//
Matrix::Matrix(Size size) : size{size} {
	// Init Array
	this->values = new float*[size.rows];
	for(size_t i = 0; i < size.rows; i++)
		this->values[i] = new float[size.columns];
}

Matrix::Matrix(Size size, MatrixType type) : size{size} {
	if(type == MatrixType::Unity && ! size.isSquare())
		throw std::invalid_argument("Unity matrix has to be square!");

	// Init Array
	this->values = new float*[size.rows];
	for(size_t i = 0; i < size.rows; i++)
		this->values[i] = new float[size.columns];

	// Fill Array
	switch(type){
		case MatrixType::Unity:
			for(size_t i = 0; i < size.rows; i++)
				for(size_t j = 0; j < size.columns; j++)
					this->values[i][j] = (i == j ? 1.0f : 0.0f);
			break;

		case MatrixType::Random:
			for(size_t i = 0; i < size.rows; i++)
				std::generate(&values[i][0],
							  &values[i][size.columns],
							  [](){return rand() %20 + 1.0;});
			break;

		case MatrixType::Zero:
			for(size_t i = 0; i < size.rows; i++)
				std::fill( &values[i][0],
						   &values[i][size.columns],
						   0);
			break;
	}
}

Matrix::Matrix(Size size, std::vector<std::vector<float>> list) : size{size} {
	// Check if the specified size matches the provided list sizes.
	if(list.size() != size.rows)
		throw std::invalid_argument("List row count does not match specified matrix size!");

	for(auto& i : list)
		if(i.size() != size.columns)
			throw std::invalid_argument("List column count does not match specified matrix size!");

	// Init Array
	this->values = new float*[size.rows];
	for(size_t i = 0; i < size.rows; i++)
		this->values[i] = new float[size.columns];

	// Move values
	for(size_t i = 0; i < size.rows; i++)
		std::copy(list[i].begin(), list[i].end(), &values[i][0]);
}

Matrix::~Matrix(){
	for(size_t i = 0; i < this->size.rows; i++)
		delete[] values[i];
	delete[] values;
}


//
// Class functions
//
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

			result[resRow][resCol] = values[i][j];
			++resCol;
		}
		++resRow;
	}

	return result;
}

float Matrix::getDeterminant(){
	if (!size.isSquare())
		throw std::invalid_argument("Determinant cannot be calculated for a non-square matrix!");

	if (size == Size(2))
		return values[0][0] * values[1][1] - values[0][1] * values[1][0];

	// Check if row or columns has more 0-entries
	int zeroRow = 0;
	int zeroCol = 0;
	for(size_t i = 0; i < size.rows; i++){
		for(size_t j = 0; j < size.columns; j++){
			if(values[0][j] == 0)
				zeroRow += 1;
			else if(values[i][0] == 0)
				zeroCol += 1;
		}
	}

	// returns: (-1)^{val}
	auto sgn = [](size_t val) -> float {
		if(val % 2 == 0)
			return 1.0f;
		else
			return -1.0f;
	};

	// Calculate determinant
	float determinant = 0.0f;
	if(zeroRow >= zeroCol) {
		for (size_t j = 0; j < size.columns; j++) {
			if(values[0][j] != 0)  // We can skip computation of any sub-matrix that would be multiplied by 0!
				determinant += sgn(j) * values[0][j] * getSubMatrix(0, j).getDeterminant();
		}
	} else {
		for (size_t i = 0; i < size.rows; i++) {
			if(values[0][i] != 0)  // We can skip computation of any sub-matrix that would be multiplied by 0!
				determinant += sgn(i) * values[i][0] * getSubMatrix(i, 0).getDeterminant();
		}
	}

	return determinant;
}

//
// Operators
//
float* Matrix::operator[](size_t row){
	if(row > size.rows)
		throw std::out_of_range("Matrix index out of range!");
	else if(values == nullptr)
		throw std::logic_error("Trying to access an uninitialized class!");
	else
		return values[row];
}

Matrix operator*(const float left, Matrix& right){
	Matrix res(right.getSize());

	for(size_t i = 0; i < right.getSize().rows; i++){
		for(size_t j = 0; j < right.getSize().columns; j++){
			res[i][j] = right[i][j] * left;
		}
	}
	return res;
}

Matrix& operator*=(Matrix& left, const float right){
	for(size_t i = 0; i < left.getSize().rows; i++)
		for(size_t j = 0; j < left.getSize().columns; j++)
			left[i][j] *= right;

	return left;
}

Matrix operator*(Matrix& left, float right){
	return (right * left);
}

Matrix operator*(Matrix& left, Matrix& right){
	if(left.getSize().columns != right.getSize().rows)
		throw std::invalid_argument("Matrix sizes do not line up for multiplication!");

	Matrix result(Size(left.getSize().rows, right.getSize().columns));
	
	for(size_t res_i = 0; res_i < result.getSize().rows; res_i++){
		for(size_t res_j = 0; res_j < result.getSize().columns; res_j++){
			result[res_i][res_j] = 0;

			for(size_t r = 0; r < left.getSize().columns; r++)
				result[res_i][res_j] += left[res_i][r] * right[r][res_j];
		}
	}

	return result;
}

bool operator==(Matrix& left, Matrix& right){
	if(! (left.getSize() == right.getSize()))
		return false;
	
	for(size_t row = 0; row < left.getSize().rows; row++)
		for(size_t col = 0; col < left.getSize().columns; col++)
			if(left[row][col] != right[row][col])
				return false;
	
	return true;
}

std::ostream& operator <<(std::ostream& os, Matrix& m){
	for(size_t i = 0; i < m.getSize().rows; i++){
		for(size_t j = 0; j < m.getSize().columns; j++)
			os << std::setw(4) << m[i][j];
		os << "\n";
	}
	return os;
}

}
}