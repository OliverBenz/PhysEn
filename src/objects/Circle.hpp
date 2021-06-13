#pragma once

#include "Object.hpp"

namespace PhysEn{
namespace Objects{

/**
 * @brief Describes a circular physical object. (Based on Object)
 */
class Circle : public Object{
	double radius;

public:
	// Constructors
	Circle(Maths::Vector pos, double radius);
	Circle(Maths::Vector pos, Maths::Vector vel, double radius);
};

}
}