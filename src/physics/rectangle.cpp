#include "rectangle.hpp"

namespace phys {

rectangle::rectangle(vectorD pos, double width, double height) : object(pos), m_width(width), m_height(height)
{}

rectangle::rectangle(vectorD pos, vectorD vel, double width, double height) : object(pos, vel), m_width(width), m_height(height)
{}

}