#pragma once

#include "Object.hpp"

namespace Physics{
namespace Objects{

class CircleObject : public Object{
    float radius;

public:
    CircleObject(Maths::Vector pos, float radius);
    CircleObject(Maths::Vector pos, Maths::Vector vel, float radius);

    float getCentripedalAcc(float velocity);
    float getCentripedalAcc(Maths::Vector velocity);
    float getPeriod();
};

}
}