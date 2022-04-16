#include <iostream>

#include "object.hpp"

using Vector = phys::maths::Vector<double, 3>;

struct Fuel{
	double mass;          ///< @brief Fuel mass left in tank.
	double speed;         ///< @brief Speed at which m_fuel is ejected.
	double massLossRate;  ///< @brief Rate at which m_fuel mass is ejected.
};

// Initialize Rocket based on PhysEn::Object with speed and position at (0, 0, 0).
// Movement will only be in x-Direction
class Rocket : public phys::objects::Object{
public:
	//! @brief Initialize Rocket by passing a zero position and zero starting velocity to the object class.
	explicit Rocket(Fuel& fuel) :
            phys::objects::Object(Vector({0, 0, 0}), Vector({0, 0, 0})),
            m_fuel{fuel}
	{};

	//! @brief Movement function of the rocket (Only in x-Direction)
	void update(double delta_t) {
		if(m_fuel.mass > 0){
			// Rocket formula for velocity increase
			velocity[0] += m_fuel.speed * m_fuel.massLossRate * delta_t / (mass + m_fuel.mass);
			// Fuel decrease
			m_fuel.mass -= m_fuel.massLossRate * delta_t;

			// Update time passed since start
			time += delta_t;
			// Update current rocket position
			position[0] += velocity[0] * delta_t;
		}
	}

	//! @brief Return amount of m_fuel left
	inline double getFuel() const { return m_fuel.mass; };

	//! @brief Print rocket position/time passed
	friend std::ostream& operator<<(std::ostream& os, Rocket& rocket) {
		os << "Time passed: " << rocket.time << "\nDistance passed: " << rocket.position[0] << "\n";
		return os;
	}

private:
	//! @brief Struct to manage m_fuel information.
	Fuel m_fuel;

	//! @brief Amount of time passed. Updated in move function.
	double time = 0;
};

// Construct a rocket and see how far it can get with
// a specified amount of m_fuel.
int main(){
	Fuel fuel{100, 20, 5};
	Rocket rocket(fuel);

	// Accelerate while still m_fuel left.
	while(rocket.getFuel() > 0)
		rocket.update(1e-5);

	// Print how far the rocket got in which time
	std::cout << rocket;

	return 0;
}