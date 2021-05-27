#pragma once

#include "../common/Size.hpp"
#include <ostream>
#include <vector>

namespace PhysEn{
namespace Maths{

enum class MatrixType {Unity, Random, Zero};

class Matrix{
	Size size;
	float** values = nullptr;

public:
	//! Returns a rows x rows matrix for UNITY matrix
	Matrix();
	Matrix(MatrixType type, Size size);
	Matrix(Size size);
	Matrix(Size size, std::vector<std::vector<float>> list);
	~Matrix();

	float getDeterminant();

	inline Size& getSize(){ return size; }
	inline bool isInversible(){return getDeterminant() != 0; };

	float* operator[](size_t row);
	//TODO: +, -
	friend Matrix operator*(float left, Matrix& right);
	friend Matrix operator*(Matrix& left, float right);
	friend Matrix operator*(Matrix& left, Matrix& right);

	friend Matrix& operator*=(Matrix& left, float right);

	friend bool operator==(Matrix& left, Matrix& right);
	
	friend std::ostream& operator <<(std::ostream& os, Matrix& m);
};

}
}