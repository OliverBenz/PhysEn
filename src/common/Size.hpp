#pragma once

#include <cstddef>
#include <iostream>

namespace PhysEn{

struct Size{
	size_t rows, columns;

	Size();                            // Zero
	Size(size_t rowsCols);             // Square
	Size(size_t rows, size_t columns); // Rows-Columns 

	/**
	 * @brief Returns if the row count equals the column count.
	 */
	bool isSquare();

	friend Size operator+(Size left, Size right);
	friend Size operator-(Size left, Size right);
	friend bool operator==(Size left, Size right);
	friend void operator+=(Size& left, Size& right);
	friend void operator-=(Size& left, Size& right);
	/**
	 * @brief Only changes the Size object if multiplicant >= 0.
	 */
	friend void operator*=(Size& left, int right);

	friend std::ostream& operator << (std::ostream& os, Size size);
};

}