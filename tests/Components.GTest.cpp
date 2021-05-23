#include <gtest/gtest.h>

#include "../src/maths/Size.hpp"

TEST(Size, Construction){
	{   // Zero Size
		PhysEn::Size size;

		EXPECT_EQ(size.rows, size.columns);
		EXPECT_EQ(size.rows, 0);
	}

	{   // Custom Size
		PhysEn::Size size(3, 4);

		EXPECT_EQ(size.rows, 3);
		EXPECT_EQ(size.columns, 4);
	}

	{   // Square Size
		PhysEn::Size size(5);

		EXPECT_EQ(size.rows, size.columns);
		EXPECT_EQ(size.rows, 5);
	}
}

TEST(Size, Operators) {
	{   // ==
		PhysEn::Size sizeOne(5);
		PhysEn::Size sizeTwo(5, 5);

		EXPECT_EQ(sizeOne, sizeTwo);
	}

	{   // +
		PhysEn::Size sizeOne(4);
		PhysEn::Size sizeTwo(5, 5);

		PhysEn::Size sizeThree = sizeOne + sizeTwo + PhysEn::Size(1, 1);
		EXPECT_EQ(sizeThree, PhysEn::Size(10, 10));
	}

	{   // -
		PhysEn::Size sizeOne(4);
		PhysEn::Size sizeTwo(5, 5);

		PhysEn::Size result = sizeOne - sizeTwo;
		EXPECT_EQ(result, PhysEn::Size(0, 0)); // Size set to (0,0) if negative

		result = sizeTwo - sizeOne;
		EXPECT_EQ(result, PhysEn::Size(1, 1));
	}

	{   // +=
		PhysEn::Size sizeOne(4);
		PhysEn::Size sizeTwo(5, 5);

		sizeOne += sizeTwo;
		EXPECT_EQ(sizeOne, PhysEn::Size(9, 9));
	}

	{   // -=
		PhysEn::Size sizeOne(4);
		PhysEn::Size sizeTwo(5, 5);

		sizeOne -= sizeTwo;
		EXPECT_EQ(sizeOne, PhysEn::Size(0, 0)); // Size set to (0,0) if negative

		sizeOne = PhysEn::Size(12, 4);
		sizeTwo -= sizeOne;
		EXPECT_EQ(sizeTwo, PhysEn::Size(0, 1));  // Component set to 0 if negative
	}

	{   // *=
		PhysEn::Size sizeOne(2, 6);
		sizeOne *= 3;

		EXPECT_EQ(sizeOne, PhysEn::Size(6, 18));

		sizeOne *= -1;
		EXPECT_EQ(sizeOne, PhysEn::Size(6, 18));

		sizeOne *= 0;
		EXPECT_EQ(sizeOne, PhysEn::Size(0, 0));
	}

}