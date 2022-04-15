#include "optics.hpp"

namespace phys::optics {

maths::Matrix<2,2> GetLens(Lens& l, double n1, double n2) {
	return maths::Matrix<2,2>{
        { 1 + l.w * (n1 - l.n)/(l.r1*l.n),                                     l.w*n1/l.n },
        { 1 + l.w * (n1 - l.n)/(l.r1*l.n) + (l.n*(n1-l.n))/(l.r1*l.n*n2),    l.w*n1*(l.n-n2) / (l.r2*l.n*n2) + n1/n2 }
	};
}
maths::Matrix<2,2> GetPath(double length) {
	return maths::Matrix<2,2>{
        {1, length},
        {0, 1}
	};
}

}
