#include <iostream>

#include "Object.hpp"

using Vector = PhysEn::Maths::Vector<double, 3>;

struct Fuel{
	double mass;
	double speed;
	double massLossRate;
};

// Initialize Rocket based on PhysEn::Object with speed and position at (0, 0, 0).
// Movement will only be in x-Direction
class Rocket : public PhysEn::Objects::Object{
public:
	// Initialize Rocket by passing a zero position
	// and zero starting velocity to the object class.
	explicit Rocket(Fuel& fuel) :
			PhysEn::Objects::Object(Vector({0, 0, 0}), Vector({0, 0, 0})),
			fuel{fuel}
	{};

	// Movement function of the rocket
	// Only in x-Direction
	void update(double delta_t) override {
		if(fuel.mass > 0){
			// Rocket formula for velocity increase
			velocity[0] += fuel.speed * fuel.massLossRate * delta_t / (mass + fuel.mass);
			// Fuel decrease
			fuel.mass -= fuel.massLossRate * delta_t;

			// Update time passed since start
			time += delta_t;
			// Update current rocket position
			position[0] += velocity[0] * delta_t;
		}
	}

	// Return amount of fuel left
	inline double getFuel() const { return fuel.mass; };

	// Print rocket position/time passed
	friend std::ostream& operator<<(std::ostream& os, Rocket& rocket) {
		os << "Time passed: " << rocket.time << "\nDistance passed: " << rocket.position[0] << "\n";
		return os;
	}

private:
	// Struct to manage fuel information.
	Fuel fuel;

	// Amount of time passed. Updated in move function.
	double time = 0;
};

// Construct a rocket and see how far it can get with
// a specified amount of fuel.
int main(){
	Fuel fuel{100, 20, 5};
	Rocket rocket(fuel);

	// Accelerate while still fuel left.
	while(rocket.getFuel() > 0)
		rocket.update(1e-5);

	// Print how far the rocket got in which time
	std::cout << rocket;

	return 0;
}