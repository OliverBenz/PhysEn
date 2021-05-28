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

	/**
	 * @return Returns the current position of the object.
	 */
	Maths::Vector& getPosition();

	/**
	 * @param pos[in] Position where object should be placed.
	 */
	void setPosition(Maths::Vector& pos);

	/**
	 * @return Returns the current velocity of the object.
	 */
	Maths::Vector& getVelocity();

	/**
	 * @param vel[in] Velocity the object should have.
	 */
	void setVelocity(Maths::Vector& vel);

	/**
	 * @return Returns the current acceleration of the object.
	 */
	Maths::Vector& getAcceleration();

	/**
	 * @param acc[in] Acceleration the object should have.
	 */
	void setAcceleration(Maths::Vector& acc);

	void update();
	void update(float time);

	friend std::ostream& operator <<(std::ostream& os, Object& obj);
};

}
}
