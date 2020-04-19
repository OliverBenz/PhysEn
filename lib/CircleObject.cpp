#include "CircleObject.hpp"

// Constructors
CircleObject::CircleObject(Vector pos, float radius) : Object(pos){
    this->radius = radius;
}
CircleObject::CircleObject(Vector pos, Vector vel, float radius) : Object(pos, vel){
    this->radius = radius;
}


float CircleObject::getCentripedalAcc(float velocity){
    return (velocity*velocity)/radius;
}
float CircleObject::getCentripedalAcc(Vector velocity){
    return (velocity.getAmount() * velocity.getAmount()) / radius;
}
float CircleObject::getPeriod(){
    return velocity.getAmount() * velocity.getAmount() / radius;
}