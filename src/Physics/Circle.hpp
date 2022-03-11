#pragma once

#include "Object.hpp"

namespace PhysEn::Objects {

using Vector = Maths::Vector<double, 3>;

/**
 * @brief Describes a circular physical object. (Based on Object)
 */
class Circle : public Object{
	double radius;

public:
	// Constructors
	Circle(Vector pos, double radius);
	Circle(Vector pos, Vector vel, double radius);
};

}