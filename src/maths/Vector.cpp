#include "Vector.hpp"
#include <math.h>

namespace Physics{
namespace Maths{

Vector::Vector(){
    this->x = 0.0f;
    this->y = 0.0f;
    this->z = 0.0f;    
}
Vector::Vector(float x, float y, float z){
    this->x = x;
    this->y = y;
    this->z = z; 
}
float Vector::getAmount(){
    return sqrt(x*x + y*y + z*z);
}

Vector Vector::getCrossProduct(Vector& right){
    Vector res(
        this->y*right.z - this->z*right.y,
        this->z*right.x - this->x*right.z,
        this->x*right.y - this->y*right.x
    );
    return res;
}

Vector operator +(Vector left, Vector right){
    left.x += right.x;
    left.y += right.y;
    left.z += right.z;

    return left;
}
Vector operator -(Vector left, Vector right){
    left.x -= right.x;
    left.y -= right.y;
    left.z -= right.z;
    return left;
}

// Vector Product
float operator *(Vector left, Vector right){
    return left.x * right.x + left.y * right.y + left.z * right.z;
}

// Scalar Product
Vector operator *(float left, Vector right){
    right.x *= left;
    right.y *= left;
    right.z *= left;
    return right;
}
Vector operator *(Vector left, float right){
    return right * left;
}

std::ostream& operator << (std::ostream& os, Vector vec){
    return os << "x, y, z = " << vec.x << " | " << vec.y << " | " << vec.z;
}
bool operator ==(Vector left, Vector right){
    return left.x == right.x && left.y == right.y && left.z == right.z;
}
bool operator !=(Vector left, Vector right){
    return !(left == right);
}

}
}