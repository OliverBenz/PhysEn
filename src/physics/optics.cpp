#include "optics.hpp"

namespace phys {

matrix<double, 2, 2> getLensMatrix(Lens& l, double n1, double n2) {
	return matrix<double, 2, 2> {
        { 1 + l.w * (n1 - l.n)/(l.r1*l.n),                                   l.w*n1/l.n },
        { 1 + l.w * (n1 - l.n)/(l.r1*l.n) + (l.n*(n1-l.n))/(l.r1*l.n*n2),    l.w*n1*(l.n-n2) / (l.r2*l.n*n2) + n1/n2 }
	};
}
matrix<double, 2, 2> getPathMatrix(double length) {
	return matrix<double, 2, 2> {
        {1, length},
        {0, 1}
	};
}

}
