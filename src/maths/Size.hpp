#pragma once

#include <cstddef>
#include <iostream>

namespace PhysEn{

struct Size{
	size_t rows, columns;

	Size();                            // Zero
	Size(size_t rowsCols);             // Square
	Size(size_t rows, size_t columns); // Rows-Columns 

	friend Size operator+(Size left, Size right);
	/**
	 * @brief Sets the component to 0 if the subtraction would have been negative. 
	 */
	friend Size operator-(Size left, Size right);
	friend bool operator==(Size left, Size right);
	friend void operator+=(Size& left, Size& right);

	/**
	 * @brief Sets the component to 0 if the subtraction would have been negaitve.
	 */
	friend void operator-=(Size& left, Size& right);
	/**
	 * @brief Only changes the Size object if multiplicant >= 0.
	 */
	friend void operator*=(Size& left, int right);

	friend std::ostream& operator << (std::ostream& os, Size size);
};

}