#pragma once

#include <vector>
#include <iostream>

namespace PhysEn{
namespace Maths{

class Vector{
	std::vector<float> values;

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
	Vector(std::initializer_list<float> list);

	/**
	 * @return Dimension of the Vector.
	 */
	inline size_t getSize() const
	{ return values.size(); };

	/**
	 * @return 2-Norm of the vector.
	 */
	float getLength();

	/**
	 * @param right The vector right of the cross product.
	 * @return Cross product result vector.
	 */
	Vector getCrossProduct(Vector& right);

	/**
	 * @return Iterator to the first element in the vector.
	 */
	inline std::vector<float>::iterator begin()
	{ return values.begin(); };

	/**
	 * @return Iterator to the last element in the vector.
	 */
	inline std::vector<float>::iterator end()
	{ return values.end(); };

	// Operators
	float& operator[](size_t row);
	float operator[](size_t row) const;

	friend Vector operator +(const Vector& left, const Vector& right);
	friend Vector operator -(const Vector& left, const Vector& right);

	friend float operator *(const Vector& left, const Vector& right);
	friend Vector operator *(const float left, const Vector& right);
	friend Vector operator *(const Vector& left, const float right);

	friend void operator *=(Vector& left, const float right);

	friend bool operator ==(const Vector& left, const Vector& right);
	friend bool operator !=(const Vector& left, const Vector& right);

	friend std::ostream& operator << (std::ostream& os, const Vector& vec);
};

float normTwo(Vector& value);
float normSupremum(Vector& value);

}
}