#include "ObjectCircle.hpp"

namespace Physics{
namespace Objects{

// Constructors
ObjectCircle::ObjectCircle(Maths::Vector pos, float radius) : Object(pos){
    this->radius = radius;
}
ObjectCircle::ObjectCircle(Maths::Vector pos, Maths::Vector vel, float radius) : Object(pos, vel){
    this->radius = radius;
}

/*
float ObjectCircle::getCentripedalAcc(float velocity){
    return (velocity*velocity)/radius;
}
float ObjectCircle::getCentripedalAcc(Maths::Vector& velocity){
    return (velocity.getAmount() * velocity.getAmount()) / radius;
}
float ObjectCircle::getPeriod(){
    return velocity.getAmount() * velocity.getAmount() / radius;
}
*/

}
}