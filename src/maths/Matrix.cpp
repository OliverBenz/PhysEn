#include "Matrix.hpp"
#include <iomanip>

namespace Physics{
namespace Maths{

//
// Constructors
//
Matrix::Matrix(){
    this->dimensions = Size();
}

Matrix::Matrix(MatrixType type, Size size){
    switch(type){
        case MatrixType::Unity:
            // Init unity matrix square: rows x rows
            this->dimensions = Size(size.rows);

            // Init Array
            this->values = new float*[size.rows];
            for(size_t i = 0; i < size.rows; i++)
                this->values[i] = new float[size.rows];

            // Fill Array
            for(size_t i = 0; i < size.rows; i++)
                for(size_t j = 0; j < size.rows; j++)
                    this->values[i][j] = (i == j ? 1.0f : 0.0f);

        	break;

        case MatrixType::Random:
            // Create size
            this->dimensions = size;
    
            // Init Array
            this->values = new float*[size.rows];
            for(size_t i = 0; i < size.rows; i++)
                this->values[i] = new float[size.columns];

            // Fill Array
            for(size_t i = 0; i < size.rows; i++)
                for(size_t j = 0; j < size.columns; j++)
                    this->values[i][j] = rand() % 20 + 1;     

  	    	break;

		case MatrixType::Zero:
            // Create size
            this->dimensions = size;
    
            // Init Array
            this->values = new float*[size.rows];
            for(size_t i = 0; i < size.rows; i++)
                this->values[i] = new float[size.columns];

            // Fill Array
            for(size_t i = 0; i < size.rows; i++)
                for(size_t j = 0; j < size.columns; j++)
                    this->values[i][j] = 0;
		
			break;
    }
}


Matrix::Matrix(Size size){
    this->dimensions = size;

    // Init Array
    this->values = new float*[size.rows];
    for(size_t i = 0; i < size.rows; i++)
        this->values[i] = new float[size.columns];
}

Matrix::~Matrix(){
    for(size_t i = 0; i < this->dimensions.rows; i++)
        delete[] values[i];
    delete[] values;
}


//
// Class functions
//
Size& Matrix::getDimensions(){
    return this->dimensions;
}

float Matrix::getDeterminant(){
    // TODO: Implement
    // Save determinant in variable?
    // To avoid duplicate calculations
    // Would need var: DetAccurate (False if matrix has been changed)
    return 0.0f;
}

bool Matrix::isInversible(){
    return getDeterminant() != 0;
}

Size& Matrix::getSize(){
    return this->dimensions;
}

//
// Operators
//
Matrix operator*(float left, Matrix& right){
    Matrix res(right.getDimensions());

    for(size_t i = 0; i < right.getDimensions().rows; i++){
        for(size_t j = 0; j < right.getDimensions().columns; j++){
            res.values[i][j] = right.values[i][j] * left;
        }
    }
    return res;
}

Matrix& operator*=(Matrix& left, float right){
    for(size_t i = 0; i < left.getDimensions().rows; i++)
        for(size_t j = 0; j < left.getDimensions().columns; j++)
            left.values[i][j] *= right;

    return left;
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

bool operator==(Matrix& left, Matrix& right){
    if(! (left.dimensions == right.dimensions))
        return false;
    
    for(size_t row = 0; row < left.dimensions.rows; row++)
        for(size_t col = 0; col < left.dimensions.columns; col++)
            if(! (left.values[row][col] == right.values[row][col]))
                return false;
    
    return true;
}

std::ostream& operator <<(std::ostream& os, Matrix& m){
    for(size_t i = 0; i < m.getDimensions().rows; i++){
        for(size_t j = 0; j < m.getDimensions().columns; j++)
            os << std::setw(4) << m.values[i][j];
        os << "\n";
    }
    return os;
}

}
}