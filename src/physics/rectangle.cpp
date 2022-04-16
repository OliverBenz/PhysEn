#include "rectangle.hpp"

namespace phys::objects {

Rectangle::Rectangle(Vector pos, double width, double height) : Object(pos), m_width(width), m_height(height)
{}

Rectangle::Rectangle(Vector pos, Vector vel, double width, double height) : Object(pos, vel), m_width(width), m_height(height)
{}

}