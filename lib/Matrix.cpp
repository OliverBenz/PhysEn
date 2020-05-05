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


Matrix::Matrix(int rows, int columns){
    this->dimensions = Size(rows, columns);

    for(int i = 0; i < rows; i++)
        this->values[i] = new float[columns];
}

Matrix::~Matrix(){
    for(int i = 0; i < this->dimensions.rows; i++)
        delete this->values[i];
    delete[] values;
}

Size Matrix::getDimensions(){
    return this->dimensions;
}

std::ostream& operator <<(std::ostream& os, Matrix m){
    for(int i = 0; i < m.getDimensions().rows; i++){
        for(int j = 0; j < m.getDimensions().columns; j++)
            os << std::setw(4) << m.values[i][j];
        os << "\n";
    }
    return os;
}