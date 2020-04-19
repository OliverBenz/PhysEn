#pragma once

#include "Object.hpp"

class CircleObject : public Object{
    float radius;

public:
    CircleObject(Vector pos, float radius);
    CircleObject(Vector pos, Vector vel, float radius);

    float getCentripedalAcc(float velocity);
    float getCentripedalAcc(Vector velocity);
    float getPeriod();
};