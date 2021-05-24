#include <gtest/gtest.h>

#include "../../src/maths/Matrix.hpp"

using namespace PhysEn;

TEST(Matrix, Calculations) {
	// TODO: Write tests

	Maths::Matrix m1(Maths::MatrixType::Unity, Size(5, 5));
	Maths::Matrix m2 = (float)2*m1;

	Maths::Matrix multOne(Maths::MatrixType::Random, Size(3,2));
	Maths::Matrix multTwo(Maths::MatrixType::Random, Size(2, 7));
	Maths::Matrix m3 = multOne * multTwo;

	EXPECT_EQ(true, true);
}