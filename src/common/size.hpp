#pragma once

#include <iostream>

namespace PhysEn {

struct Size{
	size_t rows;
	size_t columns;

	// Constructors
	/**
	 * @brief Create a zero-sized size object.
	 */
	Size();                            // Zero
	/**
	 * @brief Create a square size object.
	 * @param rowsCols Amount of rows and columns.
	 */
	explicit Size(size_t rowsCols);    // Square
	/**
	 * @brief Create a custom size object with specific rows/columns.
	 * @param rows Number of rows.
	 * @param columns Number of columns.
	 */
	Size(size_t rows, size_t columns); // Rows-Columns

	// Member functions
	/**
	 * @brief Check if the rowcount is equal to the column-count.
	 */
	inline bool isSquare(){ return rows == columns; };

	// Operators
	friend Size operator+(const Size& left, const Size& right);
	friend Size operator-(const Size& left, const Size& right);
	friend bool operator==(const Size& left, const Size& right);
	friend bool operator!=(const Size& left, const Size& right);
	friend void operator+=(Size& left, const Size& right);
	friend void operator-=(Size& left, const Size& right);
	friend void operator*=(Size& left, const int right);

	friend std::ostream& operator << (std::ostream& os, const Size& size);
};

}