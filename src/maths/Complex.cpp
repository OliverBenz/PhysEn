#include "Complex.hpp"

#include <stdexcept>
#include <cmath>

namespace PhysEn {
namespace Maths {

Complex::Complex(double real, double imaginary) : real{real}, imaginary{imaginary} {}

Complex::Complex(std::initializer_list<double> list) {
	if (list.size() != 2)
		throw std::invalid_argument("Can only be constructed with two values!");

	this->real = *list.begin();
	this->imaginary = *(list.begin() + 1);
}

// Access
double &Complex::operator[](int value) {
	if (value == 0)
		return real;
	else if (value == 1)
		return imaginary;
	else
		throw std::invalid_argument("Enter [0]..real part OR [1]..imaginary part!");
}

// Multiplication
Complex operator*(double left, Complex &right) {
	return {right[0] * left, right[1] * left};
}
Complex operator*(Complex &left, double right) {
	return {left[0] * right, left[1] * right};
}
Complex operator*(Complex &left, Complex &right) {
	return {left[0] * right[0] - left[1] * right[1],
	               left[0] * right[1] + right[0] * left[1]};
}
Complex &operator*=(Complex &left, const double right) {
	left[0] *= right;
	left[1] *= right;

	return left;
}
Complex &operator*=(Complex &left, Complex &right) {
	Complex result(left[0] * right[0] - left[1] * right[1], left[0] * right[1] + right[0] * left[1]);
	left[0] = result[0];
	left[1] = result[1];

	return left;
}

// Division
Complex operator/(double left, Complex& right){
	if(right == 0)
		throw std::invalid_argument("Cannot divide by zero!");

	// float left === Complex(left, 0)
	return {
		(left*right[0]) / (right[0]*right[0] + right[1]*right[1]),
		(-left*right[1]) / (right[0]*right[0] + right[1]*right[1]),
	};
}
Complex operator/(Complex& left, double right){
	if (right == 0)
		throw std::invalid_argument("Cannot divide by zero!");

	// float right === Complex(right, 0)
	return {
		left[0] / right,
		left[1]/ right
	};
}
Complex operator/(Complex& left, Complex& right){
	if(right == 0)
		throw std::invalid_argument("Cannot divide by zero!");

	return {
		(left[0]*right[0]+left[1]*right[1]) / (right[0]*right[0] + right[1]*right[1]),
		(left[1]*right[0]-left[0]*right[1]) / (right[0]*right[0] + right[1]*right[1])
	};
}
Complex& operator/=(Complex& left, const double right){
	if (right == 0)
		throw std::invalid_argument("Cannot divide by zero!");

	// float right === Complex(right, 0)
	Complex result{
			left[0] / right,
			left[1]/ right
	};

	left[0] = result[0];
	left[1] = result[1];
	return left;
}
Complex& operator/=(Complex& left, Complex& right){
	if(right == 0)
		throw std::invalid_argument("Cannot divide by zero!");

	Complex result{
		(left[0]*right[0]+left[1]*right[1]) / (right[0]*right[0] + right[1]*right[1]),
		(left[1]*right[0]-left[0]*right[1]) / (right[0]*right[0] + right[1]*right[1])
	};

	left[0] = result[0];
	left[1] = result[1];
	return left;
}

// Addition
Complex operator+(Complex& left, Complex& right){
	return {left[0]+right[0], left[1]+right[1]};
}
Complex operator+(double left, Complex& right){
	return {left + right[0], right[1]};
}
Complex operator+(Complex& left, double right){
	return {left[0] + right, left[1]};
}
Complex& operator+=(Complex& left, Complex& right){
	left[0] += right[0];
	left[1] += right[1];

	return left;
}
Complex& operator+=(Complex& left, double right){
	left[0] += right;

	return left;
}

// Subtraction
Complex operator-(Complex& left, Complex& right){
	return {left[0]-right[0], left[1]-right[1]};
}
Complex operator-(double left, Complex& right){
	return {left - right[0], right[1]};
}
Complex operator-(Complex& left, double right){
	return {left[0] - right, left[1]};
}
Complex& operator-=(Complex& left, Complex& right){
	left[0] -= right[0];
	left[1] -= right[1];

	return left;
}
Complex& operator-=(Complex& left, double right){
	left[0] -= right;

	return left;
}

// Equality
bool operator==(Complex &left, Complex &right) {
	return left[0] == right[0] && left[1] == right[1];
}
bool operator==(Complex& left, double right){
	return left[0] == right && left[1] == 0;
}
bool operator==(double left, Complex& right){
	return right[0] == left && right[1] == 0;
}

// Extra
std::ostream &operator<<(std::ostream &os, Complex &comp) {
	os << "Complex(" << comp[0] << ", " << comp[1] << ");\n";
	return os;
}


// Non-Class Functions
double normTwo(Complex& value){
	return sqrt(value[0]*value[0] + value[1]*value[1]);
}

double normSupremum(Complex& value){
	if(value[0] > value[1])
		return value[0];
	return value[1];
}

}
}