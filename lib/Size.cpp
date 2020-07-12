#include "Size.hpp"

Size::Size(){
    this->rows = 0;
    this->columns = 0;
}

Size::Size(int rows, int columns){
    this->rows = rows;
    this->columns = columns;
}

bool operator==(Size &left, Size &right){
    return left.rows == right.rows && left.columns == right.columns;
}