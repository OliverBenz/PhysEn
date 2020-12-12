#pragma once

#include <cstddef>

namespace Physics{

struct Size{
    size_t rows, columns;

    Size();                             // Zero
    Size(size_t rowsCols);              // Square
    Size(size_t rows, size_t columns);  // Rows-Columns 

    friend bool operator==(Size left, Size right);
};

}