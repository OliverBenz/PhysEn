#include "Matrix.hpp"

#include <stdexcept>
#include <iomanip>

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

Matrix::Matrix(Size size, MatrixType type){
	switch(type){
		case MatrixType::Unity:
			// Init unity matrix square: rows x rows
			this->size = Size(size.rows);

			// Init Array
			this->values = new float*[size.rows];
			for(size_t i = 0; i < size.rows; i++)
				this->values[i] = new float[size.rows];

			// Fill Array
			for(size_t i = 0; i < size.rows; i++)
				for(size_t j = 0; j < size.rows; j++)
					this->values[i][j] = (i == j ? 1.0f : 0.0f);

			break;

		case MatrixType::Random:
			// Create size
			this->size = size;
	
			// Init Array
			this->values = new float*[size.rows];
			for(size_t i = 0; i < size.rows; i++)
				this->values[i] = new float[size.columns];

			// Fill Array
			for(size_t i = 0; i < size.rows; i++)
				for(size_t j = 0; j < size.columns; j++)
					this->values[i][j] = static_cast<float>(rand() % 20) + 1.0f;

			break;

		case MatrixType::Zero:
			// Create size
			this->size = size;
	
			// Init Array
			this->values = new float*[size.rows];
			for(size_t i = 0; i < size.rows; i++)
				this->values[i] = new float[size.columns];

			// Fill Array
			for(size_t i = 0; i < size.rows; i++)
				for(size_t j = 0; j < size.columns; j++)
					this->values[i][j] = 0;
		
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

	// Fill Matrix
	for(size_t i = 0; i < size.rows; i++)
		for(size_t j = 0; j < size.columns; j++)
			this->values[i][j] = list[i][j];
}

Matrix::~Matrix(){
	for(size_t i = 0; i < this->size.rows; i++)
		delete[] values[i];
	delete[] values;
}


//
// Class functions
//
float Matrix::getDeterminant(){
	// TODO: Implement
	// Save determinant in variable?
	// To avoid duplicate calculations
	// Would need var: DetAccurate (False if matrix has been changed)
	return 0.0f;
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