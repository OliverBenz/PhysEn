#include "Size.hpp"

namespace PhysEn{

Size::Size(){
	this->rows = 0;
	this->columns = 0;
}

Size::Size(size_t rowsCols){
	this->rows = rowsCols;
	this->columns = rowsCols;
}

Size::Size(size_t rows, size_t columns){
	this->rows = rows;
	this->columns = columns;
}

Size operator+(Size left, Size right){
	return {left.rows + right.rows, left.columns + right.columns};
}

Size operator-(Size left, Size right){
	if (left.rows < right.rows)
	    throw std::invalid_argument("Resulting row count cannot be negative!");
	else if (left.columns < right.columns)
        throw std::invalid_argument("Resulting column count cannot be negative!");

	return {left.rows - right.rows, left.columns - right.columns};
}

bool operator==(Size left, Size right){
	return left.rows == right.rows && left.columns == right.columns;
}

void operator+=(Size& left, Size& right){
	left.rows += right.rows;
	left.columns += right.columns;
}

void operator-=(Size& left, Size& right){
    if (left.rows < right.rows)
        throw std::invalid_argument("Resulting row count cannot be negative!");
    else if (left.columns < right.columns)
        throw std::invalid_argument("Resulting column count cannot be negative!");

    left.rows -= right.rows;
    left.columns -= right.columns;
}

void operator*=(Size& left, int right){
	if (right >= 0){
		left.rows *= right;
		left.columns *= right;
	}
}


std::ostream& operator << (std::ostream& os, Size size){
	return os << "Size(" << size.rows << ", " << size.columns << ")\n";
}

}