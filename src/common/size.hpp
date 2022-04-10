#pragma once

#include <iostream>

namespace PhysEn {

struct Size{
	std::size_t rows;
	std::size_t columns;

    /**
     * @brief Create a zero-sized size object.
     */
    constexpr Size() : rows(0), columns(0)
    {}

	/**
	 * @brief Create a square size object.
	 * @param rowsCols Amount of rows and columns.
	 */
    explicit constexpr Size(size_t rowsCols) : rows(rowsCols), columns(rowsCols)
    {}

	/**
	 * @brief Create a custom size object with specific rows/columns.
	 * @param rows Number of rows.
	 * @param columns Number of columns.
	 */
    constexpr Size(size_t rows, size_t columns) : rows(rows), columns(columns)
    {}

    constexpr friend Size operator+(const Size& left, const Size& right) {
        return {left.rows + right.rows, left.columns + right.columns};
    }

    constexpr friend Size operator-(const Size& left, const Size& right) {
        if (left.rows < right.rows)
            throw std::domain_error("Resulting row count cannot be negative!");
        else if (left.columns < right.columns)
            throw std::domain_error("Resulting column count cannot be negative!");

        return {left.rows - right.rows, left.columns - right.columns};
    }

    constexpr friend bool operator==(const Size& left, const Size& right) {
        return left.rows == right.rows && left.columns == right.columns;
    }

    constexpr friend bool operator!=(const Size& left, const Size& right) {
        return !(left == right);
    }

    constexpr friend void operator+=(Size& left, const Size& right) {
        left.rows += right.rows;
        left.columns += right.columns;
    }

    constexpr friend void operator-=(Size& left, const Size& right) {
        if (left.rows < right.rows)
            throw std::domain_error("Resulting row count cannot be negative!");
        else if (left.columns < right.columns)
            throw std::domain_error("Resulting column count cannot be negative!");

        left.rows -= right.rows;
        left.columns -= right.columns;
    }

    constexpr friend void operator*=(Size& left, int right) {
        if(right < 0)
            throw std::invalid_argument("Cannot have negative scalar. Size has to be positive!");

        left.rows *= right;
        left.columns *= right;
    }

	friend std::ostream& operator << (std::ostream& os, const Size& size);
};

}