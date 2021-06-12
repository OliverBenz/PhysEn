#pragma once

#include <vector>
#include <iostream>

namespace PhysEn{
namespace Maths{

/**
 * @brief Mathematical Vector implementation.
 */
class Vector{
	std::vector<double> values;

public:
	/**
	 * @brief Zero initialize vector of size 'size'.
	 * @param size Size of the vector.
	 */
	Vector(size_t size);

	/**
	 * @brief Initialize a vector with size of list and elements in list.
	 * @param list List of all elements in the vector.
	 */
	Vector(std::initializer_list<double> list);

	/**
	 * @return Dimension of the Vector.
	 */
	inline size_t getSize() const
	{ return values.size(); };

	/**
	 * @return 2-Norm of the vector.
	 */
	double getLength();

	/**
	 * @param right The vector right of the cross product.
	 * @return Cross product result vector.
	 */
	Vector getCrossProduct(Vector& right);

	/**
	 * @return Iterator to the first element in the vector.
	 */
	inline std::vector<double>::iterator begin()
	{ return values.begin(); };

	/**
	 * @return Iterator to the last element in the vector.
	 */
	inline std::vector<double>::iterator end()
	{ return values.end(); };

	// Operators
	double& operator[](size_t row);
	double operator[](size_t row) const;

	friend Vector operator +(const Vector& left, const Vector& right);
	friend Vector operator -(const Vector& left, const Vector& right);

	friend double operator *(const Vector& left, const Vector& right);
	friend Vector operator *(const double left, const Vector& right);
	friend Vector operator *(const Vector& left, const double right);

	friend void operator *=(Vector& left, const double right);

	friend bool operator ==(const Vector& left, const Vector& right);
	friend bool operator !=(const Vector& left, const Vector& right);

	friend std::ostream& operator << (std::ostream& os, const Vector& vec);
};

double normTwo(Vector& value);
double normSupremum(Vector& value);

}
}