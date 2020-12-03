#include "Size.hpp"

namespace Physics{

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

bool operator==(Size &left, Size &right){
    return left.rows == right.rows && left.columns == right.columns;
}

}