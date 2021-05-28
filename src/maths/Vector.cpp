#include "Vector.hpp"
#include <math.h>

namespace PhysEn{
namespace Maths{

Vector::Vector(size_t size){
    for(size_t i = 0; i < size; i++)
        this->values.push_back(0);
}
Vector::Vector(std::initializer_list<float> list) : values{list}{ }

float Vector::getLength(){
    float result = 0;
    for(size_t i = 0; i < getSize(); i++)
        result += values[i] * values[i];

	return sqrt(result);
}

Vector Vector::getCrossProduct(Vector& right){
	if(this->getSize() != right.getSize() && this->getSize() != 3)
	    throw std::out_of_range("Vectors not equal size or dimension not 3!");

	Vector res({
	    values[1] * right[2] - values[2] * right[1],
	    values[2] * right[0] - values[0] * right[2],
	    values[0] * right[1] - values[1] * right[0]
	});
	return res;
}

Vector operator +(Vector left, Vector right){
    if (left.getSize() != right.getSize())
        throw std::out_of_range("Vectors not equal size!");

    for (size_t i = 0; i < left.getSize(); i++)
        left[i] += right[i];

	return left;
}
Vector operator -(Vector left, Vector right){
    if (left.getSize() != right.getSize())
        throw std::out_of_range("Vectors not equal size!");

    for (size_t i = 0; i < left.getSize(); i++)
        left[i] -= right[i];
	return left;
}

// Vector Product
float operator *(Vector left, Vector right){
    if (left.getSize() != right.getSize())
        throw std::out_of_range("Vectors not equal size!");

    float result = 0;
    for(size_t i = 0; i < left.getSize(); i++)
        result += left[i] * right[i];

    return result;
}

// Scalar Product
Vector operator *(float left, Vector right){
	for(size_t i = 0; i < right.getSize(); i++)
	    right[i] *= left;

	return right;
}
Vector operator *(Vector left, float right){
	return right * left;
}

std::ostream& operator << (std::ostream& os, Vector vec){
    os << "(";
    for(size_t i = 0; i < vec.getSize() - 1; i++)
        os << vec[i] << " ,";
    return (os << vec[vec.getSize()-1] << ")\n");
}

bool operator ==(Vector left, Vector right){
    // TODO: Throw correct error.
    if (left.getSize() != right.getSize())
        throw std::out_of_range("Vectors not equal size!");

    for(size_t i = 0; i < left.getSize(); i++)
        if(left[i] != right[i])
            return false;
    return true;
}

bool operator !=(Vector left, Vector right){
	return !(left == right);
}

float& Vector::operator[](size_t row){
    if(row > this->values.size())
        throw std::out_of_range("row number out of range!");
    else
        return this->values[row];
}

}
}