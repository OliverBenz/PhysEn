#include "object.hpp"

namespace phys {

// Constructors
object::object(vectorD pos) : position(pos)
{}

object::object(vectorD pos, vectorD vel) : position(pos), velocity(vel)
{}

object::object(vectorD pos, vectorD vel, vectorD acc) : position(pos), velocity(vel), acceleration(acc)
{}

// Single Setup Update
void object::update(){
	position = position + velocity + 0.5 * acceleration;
	velocity = velocity + acceleration;
}
// Update over time
void object::update(double time){
	position = position + (velocity * time) + (0.5 * acceleration * (time * time));
	velocity = velocity + (acceleration * time);
}

// Operators
std::ostream& operator <<(std::ostream& os, object& obj){
	os << "Position:\t" << obj.getPosition() << std::endl;
	os << "Velocity:\t" << obj.getVelocity() << std::endl;
	os << "Acceleration:\t" << obj.getAcceleration();

	return os;
}

}