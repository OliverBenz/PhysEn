#include "rectangle.hpp"

namespace phys::objects {

Rectangle::Rectangle(Vector pos, double width, double height) : Object(pos), width(width), height(height)
{}

Rectangle::Rectangle(Vector pos, Vector vel, double width, double height) : Object(pos, vel), width(width), height(height)
{}

}