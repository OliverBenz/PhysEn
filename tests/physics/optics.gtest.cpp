#include "gtest/gtest.h"

#include "physics/optics.hpp"
#include "maths/vector.hpp"

namespace PhysEn::GTest {

using Vector = Maths::Vector<double, 2>;

TEST(Optics, Path) {
    Vector light({2, 0.2});

    Optics::Lens lens;
    lens.n = 1.5;
    lens.r1 = 0.02;
    lens.r2 = -0.04;
    lens.w = 0.03;

    // TODO: Properly test function and remove warning disable.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
    Maths::Matrix lensMatrix = Optics::GetLens(lens, 1, 1);
#pragma GCC diagnostic pop
}

}
