#pragma once

#include "object.hpp"

namespace phys::objects {

using Vector = maths::Vector<double, 3>;

/**
 * @brief Describes a circular physical object. (Based on Object)
 */
class Circle : public Object{
	double radius;

public:
	// Constructors
	Circle(Vector pos, double rad);
	Circle(Vector pos, Vector vel, double rad);
};

}