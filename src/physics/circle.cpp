#include "circle.hpp"

namespace PhysEn::Objects {

// Constructors
Circle::Circle(Vector pos, double radius) : Object(pos), radius(radius)
{}

Circle::Circle(Vector pos, Vector vel, double radius) : Object(pos, vel), radius(radius)
{}

}