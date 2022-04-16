#include "object.hpp"

namespace phys::objects {

// Constructors
Object::Object(Vector pos) : position(pos)
{}

Object::Object(Vector pos, Vector vel) : position(pos), velocity(vel)
{}

Object::Object(Vector pos, Vector vel, Vector acc) : position(pos), velocity(vel), acceleration(acc)
{}

// Single Setup Update
void Object::update(){
	position = position + velocity + 0.5 * acceleration;
	velocity = velocity + acceleration;
}
// Update over time
void Object::update(double time){
	position = position + (velocity * time) + (0.5 * acceleration * (time * time));
	velocity = velocity + (acceleration * time);
}

// Operators
std::ostream& operator <<(std::ostream& os, Object& obj){
	os << "Position:\t" << obj.getPosition() << std::endl;
	os << "Velocity:\t" << obj.getVelocity() << std::endl;
	os << "Acceleration:\t" << obj.getAcceleration();

	return os;
}

}