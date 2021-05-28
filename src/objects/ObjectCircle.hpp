#pragma once

#include "Object.hpp"

namespace PhysEn{
namespace Objects{

class ObjectCircle : public Object{
	float radius;

public:
	ObjectCircle(Maths::Vector pos, float radius);
	ObjectCircle(Maths::Vector pos, Maths::Vector vel, float radius);

};

}
}