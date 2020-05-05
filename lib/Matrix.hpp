#pragma once

#include "Size.hpp"
#include <ostream>

enum Constr {Unity, Rand};

class Matrix{
    Size dimensions;
    float** values = nullptr;

public:
    Matrix();
    Matrix(Constr c, Size size);
    Matrix(int rows, int columns);
    ~Matrix();

    Size getDimensions();

    friend std::ostream& operator <<(std::ostream& os, Matrix m);
};