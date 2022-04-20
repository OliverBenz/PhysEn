#pragma once

#include "../maths/vector.hpp"
#include <iostream>

namespace phys {

using vectorD = vector<double, 3>;

/**
 * @brief Base class to describe physical objects.
 */
class object{
protected:
	vectorD position;
	vectorD velocity;
	vectorD acceleration;
	double mass = 0.0;

public:
	// Constructors
	object() = default;
	explicit object(vectorD pos);
	object(vectorD pos, vectorD vel);
	object(vectorD pos, vectorD vel, vectorD acc);

	// Member Functions
	/**
	 * @return Returns the current position of the object.
	 */
	inline vectorD& getPosition() { return position; };
	/**
	 * @param pos[in] Position where object should be placed.
	 */
	inline void setPosition(vectorD& pos) { position = pos; };

	/**
	 * @return Returns the current velocity of the object.
	 */
	inline vectorD& getVelocity() { return velocity; };
	/**
	 * @param vel[in] Velocity the object should have.
	 */
	inline void setVelocity(vectorD& vel) { velocity = vel; }

	/**
	 * @return Returns the current acceleration of the object.
	 */
	inline vectorD& getAcceleration() { return acceleration; };
	/**
	 * @param acc[in] Acceleration the object should have.
	 */
	inline void setAcceleration(vectorD& acc) { acceleration = acc; };

	/**
	 * @return Mass of the object.
	 */
	inline double getMass() { return mass; };
	/**
	 * @param value Mass the object should have.
	 */
	inline void setMass(double value) { mass = value; };

	void update();
	void update(double time);

	// Operators
	friend std::ostream& operator <<(std::ostream& os, object& obj);
};

}