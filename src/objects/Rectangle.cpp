#include "Rectangle.hpp"

namespace PhysEn{
namespace Objects{

Rectangle::Rectangle(Maths::Vector pos, Size size){
	position = std::move(pos);
	this->size = size;
}
Rectangle::Rectangle(Maths::Vector pos, Maths::Vector vel, Size size){
	position = std::move(pos);
	velocity = std::move(vel);
	this->size = size;
}

}
}