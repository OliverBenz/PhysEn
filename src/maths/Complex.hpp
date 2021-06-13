#pragma once

#include <iostream>

namespace PhysEn {
namespace Maths {

/**
 * @brief Complex number implementation.
 */
class Complex {
	double real = 0.0f;
	double imaginary = 0.0f;

public:
	// Constructors
	Complex() = default;
	Complex(double real, double imaginary);
	Complex(std::initializer_list<double> list);

	// Member functions
	/**
	 * @brief Returns the real part. (Note: [0] operator can be used.)
	 * @return Real part of complex number.
	 */
	inline double& getReal() { return real; };
	/**
	 * @brief Set the real part. (Note: [0] operator can be used.)
	 * @param value Value to set the real part to.
	 */
	inline void setReal(double value) { real = value; }

	/**
	 * @brief Returns the imaginary part. (Note [1] operator can be used.)
	 * @return Imaginary part of complex number.
	 */
	inline double& getImaginary() { return imaginary; };
	/**
	 * @brief Set the imaginary part. (Note: [1] operator can be used.)
	 * @param value Value to set the imaginary part to.
	 */
	inline void setImaginary(double value) { imaginary = value; }

	// Operators
	double& operator[](int value);

	friend Complex operator*(double left, Complex& right);
	friend Complex operator*(Complex& left, double right);
	friend Complex operator*(Complex& left, Complex& right);
	friend Complex& operator*=(Complex& left, const double right);
	friend Complex& operator*=(Complex& left, Complex& right);

	friend Complex operator/(double left, Complex& right);
	friend Complex operator/(Complex& left, double right);
	friend Complex operator/(Complex& left, Complex& right);
	friend Complex& operator/=(Complex& left, const double right);
	friend Complex& operator/=(Complex& left, Complex& right);

	friend Complex operator+(Complex& left, Complex& right);
	friend Complex operator+(double left, Complex& right);
	friend Complex operator+(Complex& left, double right);
	friend Complex& operator+=(Complex& left, Complex& right);
	friend Complex& operator+=(Complex& left, double right);

	friend Complex operator-(Complex& left, Complex& right);
	friend Complex operator-(double left, Complex& right);
	friend Complex operator-(Complex& left, double right);
	friend Complex& operator-=(Complex& left, Complex& right);
	friend Complex& operator-=(Complex& left, double right);

	friend bool operator==(Complex& left, Complex& right);
	friend bool operator==(Complex& left, double right);
	friend bool operator==(double left, Complex& right);

	friend std::ostream& operator <<(std::ostream& os, Complex& m);
};

double normTwo(Complex& value);
double normSupremum(Complex& value);

}
}
