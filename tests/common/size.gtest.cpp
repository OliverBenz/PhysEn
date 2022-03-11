#include <gtest/gtest.h>

#include "common/size.hpp"

namespace PhysEn {
namespace GTest {

TEST(Size, Construction){
	{   // Zero Size
		Size size;

		EXPECT_EQ(size.rows, size.columns);
		EXPECT_EQ(size.rows, 0);
	}

	{   // Custom Size
		Size size(3, 4);

		EXPECT_EQ(size.rows, 3);
		EXPECT_EQ(size.columns, 4);
	}

	{   // Square Size
		Size size(5);

		EXPECT_EQ(size.rows, size.columns);
		EXPECT_EQ(size.rows, 5);
	}
}

TEST(Size, Operators) {
	{   // ==
		Size sizeOne(5);
		Size sizeTwo(5, 5);

		EXPECT_EQ(sizeOne, sizeTwo);
	}

	{   // +
		Size sizeOne(4);
		Size sizeTwo(5, 5);

		Size sizeThree = sizeOne + sizeTwo + Size(1, 1);
		EXPECT_EQ(sizeThree, Size(10, 10));
	}

	{   // -
		Size sizeOne(4);
		Size sizeTwo(5, 5);

		// TODO: Test and catch throw if negative result
		// Size result = sizeOne - sizeTwo;
		// EXPECT_EQ(result, Size(0, 0)); // Size set to (0,0) if negative

		Size result = sizeTwo - sizeOne;
		EXPECT_EQ(result, Size(1, 1));
	}

	{   // +=
		Size sizeOne(4);
		Size sizeTwo(5, 5);

		sizeOne += sizeTwo;
		EXPECT_EQ(sizeOne, Size(9, 9));
	}

	{   // -=
		Size sizeOne(4);
		Size sizeTwo(5, 5);

		// TODO: Test and catch throw if negative result
		// sizeOne -= sizeTwo;
		// EXPECT_EQ(sizeOne, Size(0, 0)); // Size set to (0,0) if negative

		sizeOne = Size(1, 4);
		sizeTwo -= sizeOne;
		EXPECT_EQ(sizeTwo, Size(4, 1));  // Component set to 0 if negative
	}

	{   // *=
		Size sizeOne(2, 6);
		sizeOne *= 3;

		EXPECT_EQ(sizeOne, Size(6, 18));

		EXPECT_THROW(sizeOne *= -1, std::invalid_argument);
		EXPECT_EQ(sizeOne, Size(6, 18));

		sizeOne *= 0;
		EXPECT_EQ(sizeOne, Size(0, 0));
	}
}

}
}
