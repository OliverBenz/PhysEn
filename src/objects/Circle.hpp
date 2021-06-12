#pragma once

#include "Object.hpp"

namespace PhysEn{
namespace Objects{

class Circle : public Object{
	float radius;

public:
	Circle(Maths::Vector pos, float radius);
	Circle(Maths::Vector pos, Maths::Vector vel, float radius);

};

}
}