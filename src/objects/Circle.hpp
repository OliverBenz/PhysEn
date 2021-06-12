#pragma once

#include "Object.hpp"

namespace PhysEn{
namespace Objects{

/**
 * @brief Describes a circular physical object. (Based on Object)
 */
class Circle : public Object{
	float radius;

public:
	Circle(Maths::Vector pos, float radius);
	Circle(Maths::Vector pos, Maths::Vector vel, float radius);

};

}
}