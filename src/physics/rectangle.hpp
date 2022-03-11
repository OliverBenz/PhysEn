#pragma once

#include "object.hpp"
#include "../common/size.hpp"

namespace PhysEn::Objects {

using Vector = Maths::Vector<double, 3>;

/**
 * @brief Describes a rectangular physical object. (Based on Object)
 */
class Rectangle : public Object{
protected:
	double width;
	double height;

public:
	// Constructors
	Rectangle(Vector pos, double width, double height);
	Rectangle(Vector pos, Vector vel, double width, double height);
};

}