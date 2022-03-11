#pragma once

#include "../maths/vector.hpp"
#include <iostream>

namespace PhysEn::Objects {

using Vector = Maths::Vector<double, 3>;

/**
 * @brief Base class to describe physical objects.
 */
class Object{
protected:
	Vector position;
	Vector velocity;
	Vector acceleration;
	double mass = 0.0f;

public:
	// Constructors
	Object() = default;
	Object(Vector pos);
	Object(Vector pos, Vector vel);
	Object(Vector pos, Vector vel, Vector acc);

	// Member Functions
	/**
	 * @return Returns the current position of the object.
	 */
	inline Vector& getPosition() { return position; };
	/**
	 * @param pos[in] Position where object should be placed.
	 */
	inline void setPosition(Vector& pos) { position = pos; };

	/**
	 * @return Returns the current velocity of the object.
	 */
	inline Vector& getVelocity() { return velocity; };
	/**
	 * @param vel[in] Velocity the object should have.
	 */
	inline void setVelocity(Vector& vel) { velocity = vel; }

	/**
	 * @return Returns the current acceleration of the object.
	 */
	inline Vector& getAcceleration() { return acceleration; };
	/**
	 * @param acc[in] Acceleration the object should have.
	 */
	inline void setAcceleration(Vector& acc) { acceleration = acc; };

	/**
	 * @return Mass of the object.
	 */
	inline double getMass() { return mass; };
	/**
	 * @param value Mass the object should have.
	 */
	inline void setMass(double value) { mass = value; };

	virtual void update();
	virtual void update(double time);

	// Operators
	friend std::ostream& operator <<(std::ostream& os, Object& obj);
};

}