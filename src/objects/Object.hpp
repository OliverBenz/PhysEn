#pragma once

#include "../maths/Vector.hpp"
#include <iostream>

namespace PhysEn{
namespace Objects{

/**
 * @brief Base class to describe physical objects.
 */
class Object{
protected:
	Maths::Vector position = Maths::Vector(3);
	Maths::Vector velocity = Maths::Vector(3);
	Maths::Vector acceleration = Maths::Vector(3);
	double mass = 0.0f;

public:
	Object() = default;
	Object(Maths::Vector pos);
	Object(Maths::Vector pos, Maths::Vector vel);
	Object(Maths::Vector pos, Maths::Vector vel, Maths::Vector acc);

	/**
	 * @return Returns the current position of the object.
	 */
	inline Maths::Vector& getPosition() { return position; };
	/**
	 * @param pos[in] Position where object should be placed.
	 */
	inline void setPosition(Maths::Vector& pos) { position = pos; };

	/**
	 * @return Returns the current velocity of the object.
	 */
	inline Maths::Vector& getVelocity() { return velocity; };
	/**
	 * @param vel[in] Velocity the object should have.
	 */
	inline void setVelocity(Maths::Vector& vel) { velocity = vel; }

	/**
	 * @return Returns the current acceleration of the object.
	 */
	inline Maths::Vector& getAcceleration() { return acceleration; };
	/**
	 * @param acc[in] Acceleration the object should have.
	 */
	inline void setAcceleration(Maths::Vector& acc) { acceleration = acc; };

	/**
	 * @return Mass of the object.
	 */
	inline double getMass() { return mass; };
	/**
	 * @param value Mass the object should have.
	 */
	inline void setMass(double value) { mass = value; };

	virtual void update();
	virtual void update(float time);

	friend std::ostream& operator <<(std::ostream& os, Object& obj);
};

}
}
