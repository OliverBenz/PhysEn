#include "Rectangle.hpp"

namespace PhysEn::Objects {

Rectangle::Rectangle(Vector pos, double width, double height) : Object(pos), width(width), height(height)
{}

Rectangle::Rectangle(Vector pos, Vector vel, double width, double height) : Object(pos, vel), width(width), height(height)
{}

}