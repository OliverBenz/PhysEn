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
	/**
	 * @brief Construct a complex number: 0 + 0i
	 */
	Complex() = default;
	/**
	 * @brief Construct a complex number with specified values.
	 * @param real Real part of the number.
	 * @param imaginary Imaginary part of the number.
	 */
	Complex(double real, double imaginary);
	/**
	 * @brief Construct a complex number from the list.
	 * @note The size of the list has to be 2!
	 * @param list First number: Real part, Second number: Imaginary part.
	 */
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
	/**
	 * @brief Returns the real/imaginary part of the complex number.
	 * @param value 0..real part, 1..imaginary part.
	 * @return Real or imaginary part of the complex number.
	 */
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

/**
 * @brief Get the 2-Norm of a complex number.
 * @param value Number.
 * @return 2-Norm of the number.
 */
double normTwo(Complex& value);
/**
 * @brief Get the supremum norm of a complex number. (infinity-norm)
 * @param value Number.
 * @return Supremum norm of the number.
 */
double normSupremum(Complex& value);

}
}
