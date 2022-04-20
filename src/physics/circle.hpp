#pragma once

#include "object.hpp"

namespace phys {

using vectorD = vector<double, 3>;

/**
 * @brief Describes a circular physical object. (Based on object)
 */
class circle : public object {
	double radius;

public:
	// Constructors
	circle(vectorD pos, double rad);
	circle(vectorD pos, vectorD vel, double rad);
};

}