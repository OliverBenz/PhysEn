#include "CircleObject.hpp"

namespace Physics{
namespace Objects{

// Constructors
CircleObject::CircleObject(Maths::Vector pos, float radius) : Object(pos){
    this->radius = radius;
}
CircleObject::CircleObject(Maths::Vector pos, Maths::Vector vel, float radius) : Object(pos, vel){
    this->radius = radius;
}

float CircleObject::getCentripedalAcc(float velocity){
    return (velocity*velocity)/radius;
}
float CircleObject::getCentripedalAcc(Maths::Vector velocity){
    return (velocity.getAmount() * velocity.getAmount()) / radius;
}
float CircleObject::getPeriod(){
    return velocity.getAmount() * velocity.getAmount() / radius;
}

}
}