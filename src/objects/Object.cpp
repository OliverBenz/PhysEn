#include "Object.hpp"

namespace PhysEn{
namespace Objects{

// Constructors
Object::Object(Maths::Vector pos)
{
	position = std::move(pos);
}
Object::Object(Maths::Vector pos, Maths::Vector vel)
{
	position = std::move(pos);
	velocity = std::move(vel);
}
Object::Object(Maths::Vector pos, Maths::Vector vel, Maths::Vector acc)
{
	position = std::move(pos);
	velocity = std::move(vel);
	acceleration = std::move(acc);
}

// Single Setup Update
void Object::update(){
	position = position + velocity + (float)1/2 * acceleration;
	velocity = velocity + acceleration;
}
// Update over time
void Object::update(float time){
	position = position + (velocity * time) + ((float)1/2 * acceleration * (time * time));
	velocity = velocity + (acceleration * time);
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