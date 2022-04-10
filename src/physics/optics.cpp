#include "optics.hpp"

namespace PhysEn {
namespace Optics {

Maths::Matrix<2,2> GetLens(Lens& l, double n1, double n2) {
	return Maths::Matrix<2,2>{
        { 1 + l.w * (n1 - l.n)/(l.r1*l.n),                                     l.w*n1/l.n },
        { 1 + l.w * (n1 - l.n)/(l.r1*l.n) + (l.n*(n1-l.n))/(l.r1*l.n*n2),    l.w*n1*(l.n-n2) / (l.r2*l.n*n2) + n1/n2 }
	};
}
Maths::Matrix<2,2> GetPath(double length) {
	return Maths::Matrix<2,2>{
        {1, length},
        {0, 1}
	};
}

} // namespace Optics
} // namespace PhysEn
