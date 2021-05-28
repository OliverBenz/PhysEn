#pragma once
#include "Matrix.hpp"
#include "Vector.hpp"

namespace PhysEn {
namespace Maths {

bool makeUpperTriangle(Maths::Matrix& matrix);
bool solveEquation(Matrix& components, Vector& result);
}
}