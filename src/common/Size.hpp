#pragma once

#include <iostream>

namespace PhysEn{

struct Size{
	size_t rows, columns;

	Size();                            // Zero
	explicit Size(size_t rowsCols);    // Square
	Size(size_t rows, size_t columns); // Rows-Columns

	/**
	 * @brief Returns if the row count equals the column count.
	 */
	inline bool isSquare(){ return rows == columns; };

	friend Size operator+(const Size& left, const Size& right);
	friend Size operator-(const Size& left, const Size& right);
	friend bool operator==(const Size& left, const Size& right);
	friend void operator+=(Size& left, const Size& right);
	friend void operator-=(Size& left, const Size& right);
	/**
	 * @brief Only changes the Size object if multiplicand >= 0.
	 */
	friend void operator*=(Size& left, const int right);

	friend std::ostream& operator << (std::ostream& os, const Size& size);
};

}