#pragma once

#include "Size.hpp"
#include <ostream>

namespace Physics{
namespace Maths{

enum class MatrixType {Unity, Random, Zero};

class Matrix{
    Size dimensions;
    float** values = nullptr;

public:
	//! Returns a rows x rows matrix for UNITY matrix
    Matrix();
    Matrix(MatrixType type, Size size);
    Matrix(Size size);
    ~Matrix();

    Size& getDimensions();
    float getDeterminant();
    inline bool isInversible();
    inline Size& getSize();


    //TODO: +, -
    friend Matrix operator*(float left, Matrix& right);
    friend Matrix operator*(Matrix& left, float right);
    friend Matrix operator*(Matrix& left, Matrix& right);

    friend Matrix& operator*=(Matrix& left, float right);

    friend bool operator==(Matrix& left, Matrix& right);
    
    friend std::ostream& operator <<(std::ostream& os, Matrix& m);
};

}
}