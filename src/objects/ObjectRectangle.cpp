#include "ObjectRectangle.hpp"

namespace PhysEn{
namespace Objects{

ObjectRectangle::ObjectRectangle(Maths::Vector pos, Size size){
	position = std::move(pos);
	this->size = size;
}
ObjectRectangle::ObjectRectangle(Maths::Vector pos, Maths::Vector vel, Size size){
	position = std::move(pos);
	velocity = std::move(vel);
	this->size = size;
}

}
}