#include "Size.hpp"

Size::Size(){
    this->rows = 0;
    this->columns = 0;
}

Size::Size(size_t rows, size_t columns){
    this->rows = rows;
    this->columns = columns;
}

bool operator==(Size &left, Size &right){
    return left.rows == right.rows && left.columns == right.columns;
}