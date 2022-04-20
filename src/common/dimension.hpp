#pragma once

#include <iostream>

namespace phys {

struct dimension {
	std::size_t rows;
	std::size_t columns;

    //! @brief Create a zero-sized dimension object.
    constexpr dimension() : rows(0), columns(0)
    {}

	/*!
	 * @brief Create a square dimension object.
	 * @param rc Amount of rows and columns.
	 */
    explicit constexpr dimension(size_t rc) : rows(rc), columns(rc)
    {}

	/*!
	 * @brief Create a custom dimension object with specific rows/columns.
	 * @param r Number of rows.
	 * @param c Number of columns.
	 */
    constexpr dimension(size_t r, size_t c) : rows(r), columns(c)
    {}

    constexpr friend dimension operator+(const dimension& left, const dimension& right) {
        return {left.rows + right.rows, left.columns + right.columns};
    }

    constexpr friend dimension operator-(const dimension& left, const dimension& right) {
        if (left.rows < right.rows)
            throw std::domain_error("Resulting row count cannot be negative!");
        else if (left.columns < right.columns)
            throw std::domain_error("Resulting column count cannot be negative!");

        return {left.rows - right.rows, left.columns - right.columns};
    }

    constexpr friend bool operator==(const dimension& left, const dimension& right) {
        return left.rows == right.rows && left.columns == right.columns;
    }

    constexpr friend bool operator!=(const dimension& left, const dimension& right) {
        return !(left == right);
    }

    constexpr friend void operator+=(dimension& left, const dimension& right) {
        left.rows += right.rows;
        left.columns += right.columns;
    }

    constexpr friend void operator-=(dimension& left, const dimension& right) {
        if (left.rows < right.rows)
            throw std::domain_error("Resulting row count cannot be negative!");
        else if (left.columns < right.columns)
            throw std::domain_error("Resulting column count cannot be negative!");

        left.rows -= right.rows;
        left.columns -= right.columns;
    }

    constexpr friend void operator*=(dimension& left, std::size_t right) {
        left.rows *= right;
        left.columns *= right;
    }

	friend std::ostream& operator << (std::ostream& os, const dimension& size);
};

}