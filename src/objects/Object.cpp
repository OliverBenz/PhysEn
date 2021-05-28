#include "Object.hpp"

namespace PhysEn{
namespace Objects{

// Constructors
Object::Object(Maths::Vector pos) : position{pos}
{ }
Object::Object(Maths::Vector pos, Maths::Vector vel) : position{pos}, velocity{vel}
{ }
Object::Object(Maths::Vector pos, Maths::Vector vel, Maths::Vector acc) : position{pos}, velocity{vel}, acceleration{acc}
{ }


// Single Setup Update
void Object::update(){
	this->position = this->position + this->velocity + (float)1/2 * this->acceleration;
	this->velocity = this->velocity + this->acceleration;
}
// Update over time
void Object::update(float time){
	this->position = this->position + (this->velocity * time) + ((float)1/2 * this->acceleration * (time * time));
	this->velocity = this->velocity + (this->acceleration * time);
}

// Getter and Setter
Maths::Vector& Object::getPosition(){
	return position;
}
void Object::setPosition(Maths::Vector& pos){
	this->position = pos;
}

Maths::Vector& Object::getVelocity(){
	return velocity;
}
void Object::setVelocity(Maths::Vector& vel){
	this->velocity = vel;
}

Maths::Vector& Object::getAcceleration(){
	return acceleration;
}
void Object::setAcceleration(Maths::Vector& acc){
	this->acceleration = acc;
}

// Operators
std::ostream& operator <<(std::ostream& os, Object& obj){
	os << "Position:\t" << obj.getPosition() << std::endl;
	os << "Velocity:\t" << obj.getVelocity() << std::endl;
	os << "Acceleration:\t" << obj.getAcceleration(); 

	return os;
}

}
}