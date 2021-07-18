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
	position = position + velocity + (double)1/2 * acceleration;
	velocity = velocity + acceleration;
}
// Update over time
void Object::update(double time){
	position = position + (velocity * time) + ((double)1/2 * acceleration * (time * time));
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
}