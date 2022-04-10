#include "size.hpp"

namespace PhysEn{

constexpr Size::Size() : rows(0), columns(0)
{}

constexpr Size::Size(size_t rowsCols) : rows(rowsCols), columns(rowsCols)
{}

constexpr Size::Size(size_t rows, size_t columns) : rows(rows), columns(columns)
{}

constexpr Size operator+(const Size& left, const Size& right){
	return {left.rows + right.rows, left.columns + right.columns};
}

constexpr Size operator-(const Size& left, const Size& right){
	if (left.rows < right.rows)
		throw std::invalid_argument("Resulting row count cannot be negative!");
	else if (left.columns < right.columns)
		throw std::invalid_argument("Resulting column count cannot be negative!");

	return {left.rows - right.rows, left.columns - right.columns};
}

constexpr bool operator==(const Size& left, const Size& right){
	return left.rows == right.rows && left.columns == right.columns;
}

constexpr bool operator!=(const Size& left, const Size& right){
	return !(left == right);
}

constexpr void operator+=(Size& left, const Size& right){
	left.rows += right.rows;
	left.columns += right.columns;
}

constexpr void operator-=(Size& left, const Size& right){
	if (left.rows < right.rows)
		throw std::invalid_argument("Resulting row count cannot be negative!");
	else if (left.columns < right.columns)
		throw std::invalid_argument("Resulting column count cannot be negative!");

	left.rows -= right.rows;
	left.columns -= right.columns;
}

constexpr void operator*=(Size& left, const int right){
	if(right < 0)
		throw std::invalid_argument("Cannot have negative scalar. Size has to be positive!");

	left.rows *= right;
	left.columns *= right;
}


std::ostream& operator << (std::ostream& os, const Size& size){
	return os << "Size(" << size.rows << ", " << size.columns << ")\n";
}

}