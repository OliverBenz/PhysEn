#pragma once

#include "object.hpp"
#include "../common/size.hpp"

namespace phys::objects {

using Vector = maths::Vector<double, 3>;

/**
 * @brief Describes a rectangular physical object. (Based on Object)
 */
class Rectangle : public Object{
protected:
	double m_width;
	double m_height;

public:
    /*!
     * @brief Construct a rectangle object.
     * @param pos Position where rectangle is in space.
     * @param width Width of the rectangle.
     * @param height Height of the rectangle.
     */
	Rectangle(Vector pos, double width, double height);

    /*!
     * @brief Construct a rectangle object.
     * @param pos Position where rectangle in in space.
     * @param vel Velocity with which the rectangle is moving in space
     * @param width Width of the rectangle.
     * @param height Height of the rectangle.
     */
	Rectangle(Vector pos, Vector vel, double width, double height);
};

}