#include <iostream>

#include "../src/objects/Object.hpp"

struct Fuel{
	double mass;
	double speed;
	double massLossRate;
};

// Initialize Rocket based on Rectangle Object with speed and position at (0, 0, 0).
// Movement will only be in x-Direction
class Rocket : public PhysEn::Objects::Object{
public:
	explicit Rocket(Fuel& fuel) :
		PhysEn::Objects::Object(PhysEn::Maths::Vector{0, 0, 0},
								   PhysEn::Maths::Vector{0, 0, 0}),
		fuel{fuel}
		{};

	// Movement function of the rocket
	void update(double delta_t) override {
		if(fuel.mass > 0){
			// Movement only in x-Direction
			velocity[0] += fuel.speed * fuel.massLossRate * delta_t / (mass + fuel.mass);
			fuel.mass -= fuel.massLossRate * delta_t;

			time += delta_t;
			position[0] += velocity[0] * delta_t;
		}
	}

	inline double getFuel() const { return fuel.mass; };

	friend std::ostream& operator<<(std::ostream& os, Rocket& rocket) {
		os << "Time passed: " << rocket.time << "\nDistance passed: " << rocket.position[0] << "\n";
		return os;
	}

private:
	Fuel fuel;

	// Amount of time passed
	double time = 0;
};

// Construct a rocket and see how far it can get with
// a specified amount of fuel.
int main(){
	Fuel fuel{100, 20, 5};
	Rocket rocket(fuel);

	while(rocket.getFuel() > 0)
		rocket.update(1e-5);

	std::cout << rocket;

	return 0;
}