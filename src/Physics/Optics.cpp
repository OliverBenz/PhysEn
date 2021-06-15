#include "Optics.hpp"

namespace PhysEn {
namespace Optics {

Maths::Matrix GetLens(Lens& l, double n1, double n2) {
	return Maths::Matrix{
			{ 1 + l.w * (n1 - l.n)/(l.r1*l.n),                                     l.w*n1/l.n },
			{ 1 + l.w * (n1 - l.n)/(l.r1*l.n) + (l.n*(n1-l.n))/(l.r1*l.n*n2),    l.w*n1*(l.n-n2) / (l.r2*l.n*n2) + n1/n2 }
	};
}
Maths::Matrix GetPath(double length) {
	return Maths::Matrix{
			{1, length},
			{0, 1}
	};
}

} // namespace Optics
} // namespace PhysEn
