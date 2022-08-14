#pragma once

#include "object.hpp"
#include "common/dimension.hpp"

namespace phys {

using vectorD = vector<double, 3>;

/**
 * @brief Describes a rectangular physical object. (Based on object)
 */
class rectangle : public object{
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
	rectangle(vectorD pos, double width, double height);

    /*!
     * @brief Construct a rectangle object.
     * @param pos Position where rectangle in in space.
     * @param vel Velocity with which the rectangle is moving in space
     * @param width Width of the rectangle.
     * @param height Height of the rectangle.
     */
	rectangle(vectorD pos, vectorD vel, double width, double height);
};

}