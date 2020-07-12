#pragma once

#include "Size.hpp"
#include <ostream>

enum Constr {Unity, Rand};

class Matrix{
    Size dimensions;

public:
    float** values = nullptr;

    Matrix();
    Matrix(Constr c, Size size);
    Matrix(Size size);
    ~Matrix();

    Size getDimensions();
    float getDeterminant();


    //TODO: +, -
    friend Matrix operator*(float left, Matrix& right);
    friend Matrix operator*(Matrix& left, float right);
    friend Matrix operator*(Matrix& left, Matrix& right);

    friend Matrix& operator*=(Matrix& left, float right);

    friend bool operator==(Matrix& left, Matrix& right);
    
    friend std::ostream& operator <<(std::ostream& os, Matrix& m);
};