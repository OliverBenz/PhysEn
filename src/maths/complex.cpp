#include "complex.hpp"

#include <stdexcept>
#include <limits>
#include <cmath>

namespace phys::maths {

Complex::Complex(double real, double imaginary) : m_real{real}, m_imaginary{imaginary} {}

Complex::Complex(std::initializer_list<double> list) {
	if (list.size() != 2)
		throw std::invalid_argument("Can only be constructed with two values!");

	this->m_real = *list.begin();
	this->m_imaginary = *(list.begin() + 1);
}

// Multiplication
Complex operator*(double left, Complex &right) {
	return {right.m_real * left, right.m_imaginary * left};
}
Complex operator*(Complex &left, double right) {
	return {left.m_real * right, left.m_imaginary * right};
}
Complex operator*(Complex &left, Complex &right) {
	return {left.m_real * right.m_real - left.m_imaginary * right.m_imaginary,
	               left.m_real * right.m_imaginary + right.m_real * left.m_imaginary};
}
Complex &operator*=(Complex &left, const double right) {
	left.m_real *= right;
	left.m_imaginary *= right;

	return left;
}
Complex &operator*=(Complex &left, Complex &right) {
	Complex result(left.m_real * right.m_real - left.m_imaginary * right.m_imaginary,
				   left.m_real * right.m_imaginary + right.m_real * left.m_imaginary);
	left.m_real = result.m_real;
	left.m_imaginary = result.m_imaginary;

	return left;
}

// Division
Complex operator/(double left, Complex& right){
	if(right == 0)
		throw std::invalid_argument("Cannot divide by zero!");

	// float left === Complex(left, 0)
	return {
		(left*right.m_real) / (right.m_real*right.m_real + right.m_imaginary*right.m_imaginary),
		(-left*right.m_imaginary) / (right.m_real*right.m_real + right.m_imaginary*right.m_imaginary),
	};
}
Complex operator/(Complex& left, double right){
	if (right == 0)
		throw std::invalid_argument("Cannot divide by zero!");

	// float right === Complex(right, 0)
	return {
		left.m_real / right,
		left.m_imaginary/ right
	};
}
Complex operator/(Complex& left, Complex& right){
	if(right == 0)
		throw std::invalid_argument("Cannot divide by zero!");

	return {
		(left.m_real*right.m_real+left.m_imaginary*right.m_imaginary) / (right.m_real*right.m_real + right.m_imaginary*right.m_imaginary),
		(left.m_imaginary*right.m_real-left.m_real*right.m_imaginary) / (right.m_real*right.m_real + right.m_imaginary*right.m_imaginary)
	};
}
Complex& operator/=(Complex& left, const double right){
	if (right == 0)
		throw std::invalid_argument("Cannot divide by zero!");

	// float right === Complex(right, 0)
	Complex result{
			left.m_real / right,
			left.m_imaginary/ right
	};

	left.m_real = result.m_real;
	left.m_imaginary = result.m_imaginary;
	return left;
}
Complex& operator/=(Complex& left, Complex& right){
	if(right == 0)
		throw std::invalid_argument("Cannot divide by zero!");

	Complex result{
		(left.m_real*right.m_real+left.m_imaginary*right.m_imaginary) / (right.m_real*right.m_real + right.m_imaginary*right.m_imaginary),
		(left.m_imaginary*right.m_real-left.m_real*right.m_imaginary) / (right.m_real*right.m_real + right.m_imaginary*right.m_imaginary)
	};

	left.m_real = result.m_real;
	left.m_imaginary = result.m_imaginary;
	return left;
}

// Addition
Complex operator+(Complex& left, Complex& right){
	return {left.m_real+right.m_real, left.m_imaginary+right.m_imaginary};
}
Complex operator+(double left, Complex& right){
	return {left + right.m_real, right.m_imaginary};
}
Complex operator+(Complex& left, double right){
	return {left.m_real + right, left.m_imaginary};
}
Complex& operator+=(Complex& left, Complex& right){
	left.m_real += right.m_real;
	left.m_imaginary += right.m_imaginary;

	return left;
}
Complex& operator+=(Complex& left, double right){
	left.m_real += right;

	return left;
}

// Subtraction
Complex operator-(Complex& left, Complex& right){
	return {left.m_real-right.m_real, left.m_imaginary-right.m_imaginary};
}
Complex operator-(double left, Complex& right){
	return {left - right.m_real, right.m_imaginary};
}
Complex operator-(Complex& left, double right){
	return {left.m_real - right, left.m_imaginary};
}
Complex& operator-=(Complex& left, Complex& right){
	left.m_real -= right.m_real;
	left.m_imaginary -= right.m_imaginary;

	return left;
}
Complex& operator-=(Complex& left, double right){
	left.m_real -= right;

	return left;
}

// Equality
bool operator==(Complex &left, Complex &right) {
	return fabs(left.m_real - right.m_real) < std::numeric_limits<double>::epsilon()
		&& fabs(left.m_imaginary - right.m_imaginary) < std::numeric_limits<double>::epsilon();
}
bool operator==(Complex& left, double right){
	return fabs(left.m_real - right) < std::numeric_limits<double>::epsilon()
		&& fabs(left.m_imaginary) <= std::numeric_limits<double>::epsilon();
}
bool operator==(double left, Complex& right){
	return fabs(right.m_real - left) < std::numeric_limits<double>::epsilon()
		&& fabs(right.m_imaginary) < std::numeric_limits<double>::epsilon();
}

// Extra
std::ostream &operator<<(std::ostream &os, Complex &comp) {
	os << "Complex(" << comp.m_real << ", " << comp.m_imaginary << ");\n";
	return os;
}


// Non-Class Functions
double normTwo(Complex& value){
	return sqrt(value.real() * value.real() + value.imag() * value.imag());
}

double normSupremum(Complex& value){
	if(value.real() > value.imag())
		return value.real();
	return value.imag();
}

}
