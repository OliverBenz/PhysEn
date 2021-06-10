#include "Complex.hpp"

#include <stdexcept>

namespace PhysEn {
namespace Maths {

Complex::Complex(float real, float imaginary) : real{real}, imaginary{imaginary} {}

Complex::Complex(std::initializer_list<float> list) {
	if (list.size() != 2)
		throw std::invalid_argument("Can only be constructed with two values!");

	this->real = *list.begin();
	this->imaginary = *(list.begin() + 1);
}

// Access
float &Complex::operator[](int value) {
	if (value == 0)
		return real;
	else if (value == 1)
		return imaginary;
	else
		throw std::invalid_argument("Enter [0]..real part OR [1]..imaginary part!");
}

// Multiplication
Complex operator*(float left, Complex &right) {
	return Complex(right[0] * left, right[1] * left);
}
Complex operator*(Complex &left, float right) {
	return Complex(left[0] * right, left[1] * right);
}
Complex operator*(Complex &left, Complex &right) {
	return Complex(left[0] * right[0] - left[1] * right[1],
	               left[0] * right[1] + right[0] * left[1]);

}
Complex &operator*=(Complex &left, const float right) {
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

// Addition
Complex operator+(Complex& left, Complex& right){
	return Complex(left[0]+right[0], left[1]+right[1]);
}
Complex operator+(float left, Complex& right){
	return Complex(right[0] + left, right[1]);
}
Complex operator+(Complex& left, float right){
	return Complex(left[0] + right, left[1]);
}
Complex& operator+=(Complex& left, Complex& right){
	left[0] += right[0];
	left[1] += right[1];

	return left;
}
Complex& operator+=(Complex& left, float right){
	left[0] += right;

	return left;
}

// Subtraction
Complex operator-(Complex& left, Complex& right){
	return Complex(left[0]-right[0], left[1]-right[1]);
}
Complex operator-(float left, Complex& right){
	return Complex(right[0] - left, right[1]);
}
Complex operator-(Complex& left, float right){
	return Complex(left[0] - right, left[1]);
}
Complex& operator-=(Complex& left, Complex& right){
	left[0] -= right[0];
	left[1] -= right[1];

	return left;
}
Complex& operator-=(Complex& left, float right){
	left[0] -= right;

	return left;
}

// Equality
bool operator==(Complex &left, Complex &right) {
	return left[0] == right[0] && left[1] == right[1];
}

// Extra
std::ostream &operator<<(std::ostream &os, Complex &comp) {
	os << "Complex(" << comp[0] << ", " << comp[1] << ");\n";
	return os;
}

}
}