#include "gtest/gtest.h"

#include "physics/optics.hpp"
#include "maths/vector.hpp"

namespace phys::gtest {

using Vector = maths::Vector<double, 2>;

TEST(Optics, Path) {
    Vector light({2, 0.2});

    optics::Lens lens;
    lens.n = 1.5;
    lens.r1 = 0.02;
    lens.r2 = -0.04;
    lens.w = 0.03;

    // TODO: Properly test function and remove warning disable.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
    maths::Matrix lensMatrix = optics::GetLens(lens, 1, 1);
#pragma GCC diagnostic pop
}

}
