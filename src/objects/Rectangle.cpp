#include "Rectangle.hpp"

namespace PhysEn{
namespace Objects{

Rectangle::Rectangle(Maths::Vector pos, double width, double height){
	position = std::move(pos);
	this->width = width;
	this->height = height;
}

Rectangle::Rectangle(Maths::Vector pos, Maths::Vector vel, double width, double height){
	position = std::move(pos);
	velocity = std::move(vel);
	this->width = width;
	this->height = height;
}

}
}