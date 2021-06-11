#include "Vector.hpp"

#include <algorithm>
#include <numeric>
#include <math.h>

namespace PhysEn{
namespace Maths{

// Used in the normTwo function to accumulate a vector with each element squared.
template<typename T>
struct square {
	T operator()(const T& left, const T& right) const {
		return (left + right*right);
	}
};

Vector::Vector(size_t size){
	for(size_t i = 0; i < size; i++)
		this->values.push_back(0);
}

Vector::Vector(std::initializer_list<float> list) : values{list}{ }

float Vector::getLength(){
	float result = 0;
	for(size_t i = 0; i < getSize(); i++)
		result += values[i] * values[i];

	return sqrt(result);
}

Vector Vector::getCrossProduct(Vector& right){
	if(this->getSize() != right.getSize())
		throw std::invalid_argument("Vectors are not of equal dimension!");
	if(this->getSize() != 3)
		throw std::logic_error("Cross product only defined for vectors of dimension 3!");

	Vector res({
		values[1] * right[2] - values[2] * right[1],
		values[2] * right[0] - values[0] * right[2],
		values[0] * right[1] - values[1] * right[0]
	});
	return res;
}


// Addition
Vector operator +(const Vector& left, const Vector& right){
	if (left.getSize() != right.getSize())
		throw std::invalid_argument("Vectors are not of equal dimension!");

	Vector result(left.getSize());
	for (size_t i = 0; i < result.getSize(); i++)
		result[i] = left[i] + right[i];
	return result;
}

// Subtraction
Vector operator -(const Vector& left, const Vector& right){
	if (left.getSize() != right.getSize())
		throw std::invalid_argument("Vectors are not of equal dimension!");

	Vector result(left.getSize());
	for (size_t i = 0; i < result.getSize(); i++)
		result[i] = left[i] - right[i];
	return result;
}

// Vector Product
float operator *(const Vector& left, const Vector& right){
	if (left.getSize() != right.getSize())
		throw std::invalid_argument("Vectors are not of equal dimension!");

	float result = 0;
	for(size_t i = 0; i < left.getSize(); i++)
		result += left[i] * right[i];
	return result;
}

// Scalar Product
Vector operator *(const float left, const Vector& right){
	Vector result(right.getSize());
	for(size_t i = 0; i < right.getSize(); i++)
		result[i] = right[i] * left;
	return result;
}

Vector operator *(const Vector& left, const float right){
	return right * left;
}

void operator *=(Vector& left, float right){
	for(size_t i = 0; i < left.getSize(); i++)
		left[i] *= right;
}

bool operator ==(const Vector& left, const Vector& right){
	if (left.getSize() != right.getSize())
		throw std::invalid_argument("Vectors are not of equal dimension!");

	for(size_t i = 0; i < left.getSize(); i++)
		if(left[i] != right[i])
			return false;
	return true;
}

bool operator !=(const Vector& left, const Vector& right){
	return !(left == right);
}

float& Vector::operator[](size_t row){
	if(row > values.size())
		throw std::out_of_range("Vector row number out of range!");
	else
		return values[row];
}

float Vector::operator[](size_t row) const {
	if(row > values.size())
		throw std::out_of_range("Vector row number out of range!");
	else
		return values[row];
}

std::ostream& operator << (std::ostream& os, const Vector& vec){
	os << "(";
	for(size_t i = 0; i < vec.getSize() - 1; i++)
		os << vec[i] << " ,";
	return (os << vec[vec.getSize()-1] << ")\n");
}

// Non-Class Functions
float normTwo(Vector& value){
	return sqrt(std::accumulate(value.begin(), value.end(), 0.0f, square<float>()));
}
float normSupremum(Vector& value){
	return *std::max_element(value.begin(), value.end());
}

}
}