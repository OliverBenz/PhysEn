#pragma once

#include "../maths/Vector.hpp"
#include <iostream>

namespace PhysEn{
namespace Objects{

class Object{
protected:
	Maths::Vector position = Maths::Vector(3);
	Maths::Vector velocity = Maths::Vector(3);
	Maths::Vector acceleration = Maths::Vector(3);

public:
	Object() = default;
	Object(Maths::Vector pos);
	Object(Maths::Vector pos, Maths::Vector vel);
	Object(Maths::Vector pos, Maths::Vector vel, Maths::Vector acc);

	Maths::Vector& getPosition();
	void setPosition(Maths::Vector& pos);

	Maths::Vector& getVelocity();
	void setVelocity(Maths::Vector& vel);
	
	Maths::Vector& getAcceleration();
	void setAcceleration(Maths::Vector& acc);

	void update();
	void update(float time);

	friend std::ostream& operator <<(std::ostream& os, Object& obj);
};

}
}
