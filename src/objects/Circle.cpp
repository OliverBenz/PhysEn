#include "Circle.hpp"

namespace PhysEn{
namespace Objects{

// Constructors
Circle::Circle(Maths::Vector pos, double radius){
	position = std::move(pos);
	this->radius = radius;
}
Circle::Circle(Maths::Vector pos, Maths::Vector vel, double radius){
	position = std::move(pos);
	velocity = std::move(vel);
	this->radius = radius;
}

}
}