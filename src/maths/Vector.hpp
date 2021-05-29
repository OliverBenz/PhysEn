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
	inline size_t getSize() { return values.size(); };

	/**
	 * @return 2-Norm of the vector.
	 */
	float getLength();

	/**
	 * @param right The vector right of the cross product.
	 * @return Cross product result vector.
	 */
	Vector getCrossProduct(Vector& right);

	// Operators
    float& operator[](size_t row);

	friend Vector operator +(Vector left, Vector right);
	friend Vector operator -(Vector left, Vector right);

	friend float operator *(Vector left, Vector right);
	friend Vector operator *(float left, Vector right);
	friend Vector operator *(Vector left, float right);

	friend void operator *=(Vector& left, float right);

	friend bool operator ==(Vector left, Vector right);
	friend bool operator !=(Vector left, Vector right);

	friend std::ostream& operator << (std::ostream& os, Vector vec);
};

}
}