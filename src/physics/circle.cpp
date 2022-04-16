#include "circle.hpp"

namespace phys::objects {

// Constructors
Circle::Circle(Vector pos, double rad) : Object(pos), radius(rad)
{}

Circle::Circle(Vector pos, Vector vel, double rad) : Object(pos, vel), radius(rad)
{}

}