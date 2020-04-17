#pragma once

#include "Vector.hpp"
#include <iostream>

class Object{
    Vector position;
    Vector velocity;
    Vector acceleration;

public:
    Object();
    Object(Vector pos);
    Object(Vector pos, Vector vel);
    Object(Vector pos, Vector vel, Vector acc);

    Vector getPosition();
    void setPosition(Vector pos);

    Vector getVelocity();
    void setVelocity(Vector vel);
    
    Vector getAcceleration();
    void setAcceleration(Vector acc);

    void update();
    void update(float time);

    friend std::ostream& operator <<(std::ostream& os, Object& obj);
};
