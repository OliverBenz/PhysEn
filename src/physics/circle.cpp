#include "circle.hpp"

namespace phys {

// Constructors
circle::circle(vectorD pos, double rad) : object(pos), radius(rad)
{}

circle::circle(vectorD pos, vectorD vel, double rad) : object(pos, vel), radius(rad)
{}

}