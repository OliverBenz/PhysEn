#include "ObjectCircle.hpp"

namespace PhysEn{
namespace Objects{

// Constructors
ObjectCircle::ObjectCircle(Maths::Vector pos, float radius) : Object(pos){
	this->radius = radius;
}
ObjectCircle::ObjectCircle(Maths::Vector pos, Maths::Vector vel, float radius) : Object(pos, vel){
	this->radius = radius;
}

}
}