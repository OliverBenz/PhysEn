#include "complex.hpp"

#include <stdexcept>
#include <limits>
#include <cmath>

namespace phys {

complex::complex(double real, double imaginary) : m_real{real}, m_imaginary{imaginary} {}

complex::complex(std::initializer_list<double> list) {
	if (list.size() != 2)
		throw std::invalid_argument("Can only be constructed with two values!");

	this->m_real = *list.begin();
	this->m_imaginary = *(list.begin() + 1);
}

// Multiplication
complex operator*(double left, complex &right) {
	return {right.m_real * left, right.m_imaginary * left};
}
complex operator*(complex &left, double right) {
	return {left.m_real * right, left.m_imaginary * right};
}
complex operator*(complex &left, complex &right) {
	return {left.m_real * right.m_real - left.m_imaginary * right.m_imaginary,
	               left.m_real * right.m_imaginary + right.m_real * left.m_imaginary};
}
complex &operator*=(complex &left, const double right) {
	left.m_real *= right;
	left.m_imaginary *= right;

	return left;
}
complex &operator*=(complex &left, complex &right) {
	complex result(left.m_real * right.m_real - left.m_imaginary * right.m_imaginary,
				   left.m_real * right.m_imaginary + right.m_real * left.m_imaginary);
	left.m_real = result.m_real;
	left.m_imaginary = result.m_imaginary;

	return left;
}

// Division
complex operator/(double left, complex& right){
	if(right == 0)
		throw std::invalid_argument("Cannot divide by zero!");

	// float left === complex(left, 0)
	return {
		(left*right.m_real) / (right.m_real*right.m_real + right.m_imaginary*right.m_imaginary),
		(-left*right.m_imaginary) / (right.m_real*right.m_real + right.m_imaginary*right.m_imaginary),
	};
}
complex operator/(complex& left, double right){
	if (right == 0)
		throw std::invalid_argument("Cannot divide by zero!");

	// float right === complex(right, 0)
	return {
		left.m_real / right,
		left.m_imaginary/ right
	};
}
complex operator/(complex& left, complex& right){
	if(right == 0)
		throw std::invalid_argument("Cannot divide by zero!");

	return {
		(left.m_real*right.m_real+left.m_imaginary*right.m_imaginary) / (right.m_real*right.m_real + right.m_imaginary*right.m_imaginary),
		(left.m_imaginary*right.m_real-left.m_real*right.m_imaginary) / (right.m_real*right.m_real + right.m_imaginary*right.m_imaginary)
	};
}
complex& operator/=(complex& left, const double right){
	if (right == 0)
		throw std::invalid_argument("Cannot divide by zero!");

	// float right === complex(right, 0)
	complex result{
			left.m_real / right,
			left.m_imaginary/ right
	};

	left.m_real = result.m_real;
	left.m_imaginary = result.m_imaginary;
	return left;
}
complex& operator/=(complex& left, complex& right){
	if(right == 0)
		throw std::invalid_argument("Cannot divide by zero!");

	complex result{
		(left.m_real*right.m_real+left.m_imaginary*right.m_imaginary) / (right.m_real*right.m_real + right.m_imaginary*right.m_imaginary),
		(left.m_imaginary*right.m_real-left.m_real*right.m_imaginary) / (right.m_real*right.m_real + right.m_imaginary*right.m_imaginary)
	};

	left.m_real = result.m_real;
	left.m_imaginary = result.m_imaginary;
	return left;
}

// Addition
complex operator+(complex& left, complex& right){
	return {left.m_real+right.m_real, left.m_imaginary+right.m_imaginary};
}
complex operator+(double left, complex& right){
	return {left + right.m_real, right.m_imaginary};
}
complex operator+(complex& left, double right){
	return {left.m_real + right, left.m_imaginary};
}
complex& operator+=(complex& left, complex& right){
	left.m_real += right.m_real;
	left.m_imaginary += right.m_imaginary;

	return left;
}
complex& operator+=(complex& left, double right){
	left.m_real += right;

	return left;
}

// Subtraction
complex operator-(complex& left, complex& right){
	return {left.m_real-right.m_real, left.m_imaginary-right.m_imaginary};
}
complex operator-(double left, complex& right){
	return {left - right.m_real, right.m_imaginary};
}
complex operator-(complex& left, double right){
	return {left.m_real - right, left.m_imaginary};
}
complex& operator-=(complex& left, complex& right){
	left.m_real -= right.m_real;
	left.m_imaginary -= right.m_imaginary;

	return left;
}
complex& operator-=(complex& left, double right){
	left.m_real -= right;

	return left;
}

// Equality
bool operator==(complex &left, complex &right) {
	return fabs(left.m_real - right.m_real) < std::numeric_limits<double>::epsilon()
		&& fabs(left.m_imaginary - right.m_imaginary) < std::numeric_limits<double>::epsilon();
}
bool operator==(complex& left, double right){
	return fabs(left.m_real - right) < std::numeric_limits<double>::epsilon()
		&& fabs(left.m_imaginary) <= std::numeric_limits<double>::epsilon();
}
bool operator==(double left, complex& right){
	return fabs(right.m_real - left) < std::numeric_limits<double>::epsilon()
		&& fabs(right.m_imaginary) < std::numeric_limits<double>::epsilon();
}

// Extra
std::ostream &operator<<(std::ostream &os, complex &comp) {
	os << "complex(" << comp.m_real << ", " << comp.m_imaginary << ");\n";
	return os;
}


// Non-Class Functions
double normTwo(complex& value){
	return sqrt(value.real() * value.real() + value.imag() * value.imag());
}

double normSupremum(complex& value){
	if(value.real() > value.imag())
		return value.real();
	return value.imag();
}

}
