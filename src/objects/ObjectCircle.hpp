#pragma once

#include "Object.hpp"

namespace PhysEn{
namespace Objects{

class ObjectCircle : public Object{
	float radius;

public:
	ObjectCircle(Maths::Vector pos, float radius);
	ObjectCircle(Maths::Vector pos, Maths::Vector vel, float radius);

	bool Colliding(ObjectCircle& right);

	/*  Circle Object is not a circle path -> It's an object!
		For a period or centripetal force, we need the circle object on a specific path
	float getCentripedalAcc(float velocity);
	float getCentripedalAcc(Maths::Vector& velocity);
	float getPeriod();
	*/
};

}
}