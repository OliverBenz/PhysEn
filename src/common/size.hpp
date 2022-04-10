#pragma once

#include <iostream>

namespace PhysEn {

struct Size{
	std::size_t rows;
	std::size_t columns;

	// Constructors
	/**
	 * @brief Create a zero-sized size object.
	 */
	constexpr Size();
	/**
	 * @brief Create a square size object.
	 * @param rowsCols Amount of rows and columns.
	 */
	explicit constexpr Size(size_t rowsCols);
	/**
	 * @brief Create a custom size object with specific rows/columns.
	 * @param rows Number of rows.
	 * @param columns Number of columns.
	 */
	constexpr Size(size_t rows, size_t columns);

	// Member functions
	/**
	 * @brief Check if the rowcount is equal to the column-count.
	 */
	[[nodiscard]]
    constexpr inline bool isSquare() const { return rows == columns; };

	// Operators
	friend constexpr Size operator+(const Size& left, const Size& right);
	friend constexpr Size operator-(const Size& left, const Size& right);
	friend constexpr bool operator==(const Size& left, const Size& right);
	friend constexpr bool operator!=(const Size& left, const Size& right);
	friend constexpr void operator+=(Size& left, const Size& right);
	friend constexpr void operator-=(Size& left, const Size& right);
	friend constexpr void operator*=(Size& left, int right);

	friend std::ostream& operator << (std::ostream& os, const Size& size);
};

}