#pragma once

#include <iostream>

namespace Physics{
namespace Maths{

struct Vector{
    float x;
    float y;
    float z;

    Vector();
    Vector(float x, float y, float z);

    // Betrag
    float getAmount();
    Vector getCrossProduct(Vector& right);

    friend Vector operator +(Vector left, Vector right);
    friend Vector operator -(Vector left, Vector right);

    friend float operator *(Vector left, Vector right);
    friend Vector operator *(float left, Vector right);
    friend Vector operator *(Vector left, float right);

    friend bool operator ==(Vector left, Vector right);
    friend bool operator !=(Vector left, Vector right);
    friend std::ostream& operator << (std::ostream& os, Vector vec);
};

}
}