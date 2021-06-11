#pragma once

#include <iostream>

namespace PhysEn {
namespace Maths {

class Complex {
	float real = 0.0f;
	float imaginary = 0.0f;

public:
	Complex() = default;
	Complex(float real, float imaginary);
	Complex(std::initializer_list<float> list);

	// Simple access
	/**
	 * @brief Returns the real part. (Note: [0] operator can be used.)
	 * @return Real part of complex number.
	 */
	inline float& getReal()
	{ return real; };

	/**
	 * @brief Set the real part. (Note: [0] operator can be used.)
	 * @param value Value to set the real part to.
	 */
	inline void setReal(float value)
	{ real = value; }

	/**
	 * @brief Returns the imaginary part. (Note [1] operator can be used.)
	 * @return Imaginary part of complex number.
	 */
	inline float& getImaginary()
	{ return imaginary; };

	/**
	 * @brief Set the imaginary part. (Note: [1] operator can be used.)
	 * @param value Value to set the imaginary part to.
	 */
	inline void setImaginary(float value)
	{ imaginary = value; }

	// ---------
	// Operators
	// ---------

	// Access
	float& operator[](int value);

	// Multiplication
	friend Complex operator*(float left, Complex& right);
	friend Complex operator*(Complex& left, float right);
	friend Complex operator*(Complex& left, Complex& right);

	friend Complex& operator*=(Complex& left, const float right);
	friend Complex& operator*=(Complex& left, Complex& right);

	// Division
	friend Complex operator/(float left, Complex& right);
	friend Complex operator/(Complex& left, float right);
	friend Complex operator/(Complex& left, Complex& right);

	friend Complex& operator/=(Complex& left, const float right);
	friend Complex& operator/=(Complex& left, Complex& right);

	// Addition
	friend Complex operator+(Complex& left, Complex& right);
	friend Complex operator+(float left, Complex& right);
	friend Complex operator+(Complex& left, float right);

	friend Complex& operator+=(Complex& left, Complex& right);
	friend Complex& operator+=(Complex& left, float right);

	// Subtraction
	friend Complex operator-(Complex& left, Complex& right);
	friend Complex operator-(float left, Complex& right);
	friend Complex operator-(Complex& left, float right);

	friend Complex& operator-=(Complex& left, Complex& right);
	friend Complex& operator-=(Complex& left, float right);

	// Equality
	friend bool operator==(Complex& left, Complex& right);
	friend bool operator==(Complex& left, float right);
	friend bool operator==(float left, Complex& right);

	// Extra
	friend std::ostream& operator <<(std::ostream& os, Complex& m);
};

}
}
