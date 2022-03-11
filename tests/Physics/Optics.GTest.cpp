#include "gtest/gtest.h"

#include "Physics/Optics.hpp"
#include "Maths/Vector.hpp"

namespace PhysEn {
namespace GTest {

using Vector = Maths::Vector<double, 2>;

TEST(Optics, Path) {
    Vector light{2, 0.2};

    Optics::Lens lens;
    lens.n = 1.5;
    lens.r1 = 0.02;
    lens.r2 = -0.04;
    lens.w = 0.03;

    Maths::Matrix lensMatrix = Optics::GetLens(lens, 1, 1);
}

}
}
