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
	Size size;

public:
	// Constructors
	Rectangle(Maths::Vector pos, Size size);
	Rectangle(Maths::Vector pos, Maths::Vector vel, Size size);
};

}
}