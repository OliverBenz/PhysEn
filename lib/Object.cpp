#include "Object.hpp"

// Constructors
Object::Object(){
    this->position = Vector();
    this->velocity = Vector();
    this->acceleration = Vector();
}
Object::Object(Vector pos){
    this->position = pos;
    this->velocity = Vector();
    this->acceleration = Vector();
}
Object::Object(Vector pos, Vector vel){
    this->position = pos;
    this->velocity = vel;
    this->acceleration = Vector();
}
Object::Object(Vector pos, Vector vel, Vector acc){
    this->position = pos;
    this->velocity = vel;
    this->acceleration = acc;
}


// Single Setup Update
void Object::update(){
    this->position = this->position + this->velocity + (float)1/2 * this->acceleration;
    this->velocity = this->velocity + this->acceleration;
}
// Update over time
void Object::update(float time){
    this->position = this->position + (this->velocity * time) + ((float)1/2 * this->acceleration * (time * time));
    this->velocity = this->velocity + (this->acceleration * time);
}

// Getter and Setter
Vector Object::getPosition(){
    return position;
}
void Object::setPosition(Vector pos){
    this->position = pos;
}

Vector Object::getVelocity(){
    return velocity;
}
void Object::setVelocity(Vector vel){
    this->velocity = vel;
}

Vector Object::getAcceleration(){
    return acceleration;
}
void Object::setAcceleration(Vector acc){
    this->acceleration = acc;
}

// Operators
std::ostream& operator <<(std::ostream& os, Object& obj){
    os << "Position:\t" << obj.getPosition() << std::endl;
    os << "Velocity:\t" << obj.getVelocity() << std::endl;
    os << "Acceleration:\t" << obj.getAcceleration(); 
}