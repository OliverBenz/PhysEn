#include "ObjectRectangle.hpp"

namespace Physics{
namespace Objects{

ObjectRectangle::ObjectRectangle(Maths::Vector pos, Size size) : Object(pos){
    this->size = size;
}
ObjectRectangle::ObjectRectangle(Maths::Vector pos, Maths::Vector vel, Size size) : Object(pos, vel){
    this->size = size;
}

}
}