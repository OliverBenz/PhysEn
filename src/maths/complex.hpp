#pragma once

#include <iostream>

namespace phys {

//! @brief complex number implementation.
class complex {
	double m_real = 0.0;
	double m_imaginary = 0.0;

public:
	// Constructors
	/*!
	 * @brief Construct a complex number: 0 + 0i
	 */
	complex() = default;

	/*!
	 * @brief Construct a complex number with specified values.
	 * @param real Real part of the number.
	 * @param imaginary Imaginary part of the number.
	 */
	complex(double real, double imaginary);

	/*!
	 * @brief Construct a complex number from the list.
	 * @note The dimension of the list has to be 2!
	 * @param list First number: Real part, Second number: Imaginary part.
	 */
	complex(std::initializer_list<double> list);

	/*!
	 * @brief Returns the real part.
	 * @return Real part of complex number.
	 */
	inline double& real() { return m_real; };

	/*!
	 * @brief Returns the imaginary part.
	 * @return Imaginary part of complex number.
	 */
	inline double& imag() { return m_imaginary; };

	friend complex operator*(double left, complex& right);
	friend complex operator*(complex& left, double right);
	friend complex operator*(complex& left, complex& right);
	friend complex& operator*=(complex& left, const double right);
	friend complex& operator*=(complex& left, complex& right);

	friend complex operator/(double left, complex& right);
	friend complex operator/(complex& left, double right);
	friend complex operator/(complex& left, complex& right);
	friend complex& operator/=(complex& left, const double right);
	friend complex& operator/=(complex& left, complex& right);

	friend complex operator+(complex& left, complex& right);
	friend complex operator+(double left, complex& right);
	friend complex operator+(complex& left, double right);
	friend complex& operator+=(complex& left, complex& right);
	friend complex& operator+=(complex& left, double right);

	friend complex operator-(complex& left, complex& right);
	friend complex operator-(double left, complex& right);
	friend complex operator-(complex& left, double right);
	friend complex& operator-=(complex& left, complex& right);
	friend complex& operator-=(complex& left, double right);

	friend bool operator==(complex& left, complex& right);
	friend bool operator==(complex& left, double right);
	friend bool operator==(double left, complex& right);

	friend std::ostream& operator <<(std::ostream& os, complex& m);
};

/*!
 * @brief Get the 2-Norm of a complex number.
 * @param value Number.
 * @return 2-Norm of the number.
 */
double normTwo(complex& value);

/*!
 * @brief Get the supremum norm of a complex number. (infinity-norm)
 * @param value Number.
 * @return Supremum norm of the number.
 */
double normSupremum(complex& value);

}
