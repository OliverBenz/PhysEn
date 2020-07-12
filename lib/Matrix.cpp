#include "Matrix.hpp"
#include <iomanip>

Matrix::Matrix(){
    this->dimensions = Size();
}

Matrix::Matrix(Constr c, Size size){
    switch(c){
        case Unity:
            // Init unity matrix square: rows x rows
            this->dimensions = Size(size.rows, size.rows);

            // Init Array
            this->values = new float*[size.rows];
            for(int i = 0; i < size.rows; i++)
                this->values[i] = new float[size.rows];

            // Fill Array
            for(int i = 0; i < size.rows; i++)
                for(int j = 0; j < size.rows; j++)
                    this->values[i][j] = (i == j ? 1.0f : 0.0f);
        break;

        case Rand:
            // Create size
            this->dimensions = size;
    
            // Init Array
            this->values = new float*[size.rows];
            for(int i = 0; i < size.rows; i++)
                this->values[i] = new float[size.columns];

            // Fill Array
            for(int i = 0; i < size.rows; i++)
                for(int j = 0; j < size.columns; j++)
                    this->values[i][j] = rand() % 20 + 1;     
        break;
    }
}


Matrix::Matrix(Size size){
    this->dimensions = size;

    // Init Array
    this->values = new float*[size.rows];
    for(int i = 0; i < size.rows; i++)
        this->values[i] = new float[size.columns];
}

Matrix::~Matrix(){
    for(int i = 0; i < this->dimensions.rows; i++)
        delete[] values[i];
    delete[] values;
}

Size Matrix::getDimensions(){
    return this->dimensions;
}

Matrix operator*(float left, Matrix& right){
    Matrix res(right.getDimensions());

    for(int i = 0; i < right.getDimensions().rows; i++){
        for(int j = 0; j < right.getDimensions().columns; j++){
            res.values[i][j] = right.values[i][j] * left;
        }
    }
    return res;
}

Matrix operator*(Matrix& left, float right){
    return (right * left);
}

Matrix operator*(Matrix& left, Matrix& right){
    Matrix result(Size(left.dimensions.rows, right.dimensions.columns));

    if(left.dimensions.columns != right.dimensions.rows)
        return result;
    
    for(size_t res_i = 0; res_i < result.dimensions.rows; res_i++){
        for(size_t res_j = 0; res_j < result.dimensions.columns; res_j++){
            result.values[res_i][res_j] = 0;

            for(size_t r = 0; r < left.dimensions.columns; r++)
                result.values[res_i][res_j] += left.values[res_i][r] * right.values[r][res_j];
        }
    }

    return result;
}

std::ostream& operator <<(std::ostream& os, Matrix& m){
    for(int i = 0; i < m.getDimensions().rows; i++){
        for(int j = 0; j < m.getDimensions().columns; j++)
            os << std::setw(4) << m.values[i][j];
        os << "\n";
    }
    return os;
}