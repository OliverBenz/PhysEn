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

	// Simple getters
	/**
	 * @brief Returns the real part. (Note: [0] operator can be used.)
	 * @return Real part of complex number.
	 */
	inline float& getReal()
	{ return real; };

	/**
	 * @brief Returns the imaginary part. (Note [1] operator can be used.)
	 * @return Imaginary part of complex number.
	 */
	inline float& getImaginary()
	{ return imaginary; };

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

	// Extra
	friend std::ostream& operator <<(std::ostream& os, Complex& m);
};

}
}
