#pragma once

#include <iostream>

namespace phys {

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
	 * @param rc Amount of rows and columns.
	 */
    explicit constexpr Size(size_t rc) : rows(rc), columns(rc)
    {}

	/**
	 * @brief Create a custom size object with specific rows/columns.
	 * @param r Number of rows.
	 * @param c Number of columns.
	 */
    constexpr Size(size_t r, size_t c) : rows(r), columns(c)
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

    constexpr friend void operator*=(Size& left, std::size_t right) {
        left.rows *= right;
        left.columns *= right;
    }

	friend std::ostream& operator << (std::ostream& os, const Size& size);
};

}