#pragma once

#include "Object.hpp"
#include "../common/Size.hpp"

namespace PhysEn{
namespace Objects{

/**
 * @brief Describes a rectangular physical object. (Based on Object)
 */
class Rectangle : public Object{
protected:
	double width;
	double height;

public:
	// Constructors
	Rectangle(Maths::Vector pos, double width, double height);
	Rectangle(Maths::Vector pos, Maths::Vector vel, double width, double height);
};

}
}