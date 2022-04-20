#include <gtest/gtest.h>

#include "common/dimension.hpp"

namespace phys::gtest {

TEST(Dimension, Construction){
	{   // zero dimension
		dimension size;

		EXPECT_EQ(size.rows, size.columns);
		EXPECT_EQ(size.rows, 0);
	}

	{   // Custom dimension
		dimension size(3, 4);

		EXPECT_EQ(size.rows, 3);
		EXPECT_EQ(size.columns, 4);
	}

	{   // Square dimension
		dimension size(5);

		EXPECT_EQ(size.rows, size.columns);
		EXPECT_EQ(size.rows, 5);
	}
}

TEST(Dimension, Operators) {
	{   // ==
		dimension sizeOne(5);
		dimension sizeTwo(5, 5);

		EXPECT_EQ(sizeOne, sizeTwo);
	}

	{   // +
		dimension sizeOne(4);
		dimension sizeTwo(5, 5);

		dimension sizeThree = sizeOne + sizeTwo + dimension(1, 1);
		EXPECT_EQ(sizeThree, dimension(10, 10));
	}

	{   // -
		dimension sizeOne(4);
		dimension sizeTwo(5, 5);

        EXPECT_THROW(sizeOne - sizeTwo, std::domain_error);

		dimension result = sizeTwo - sizeOne;
		EXPECT_EQ(result, dimension(1, 1));
	}

	{   // +=
		dimension sizeOne(4);
		dimension sizeTwo(5, 5);

		sizeOne += sizeTwo;
		EXPECT_EQ(sizeOne, dimension(9, 9));
	}

	{   // -=
		dimension sizeOne(4);
		dimension sizeTwo(5, 5);

        auto func = [&](){
            sizeOne -= sizeTwo;
        };
        EXPECT_THROW(func(), std::domain_error);

		sizeOne = dimension(1, 4);
		sizeTwo -= sizeOne;
		EXPECT_EQ(sizeTwo, dimension(4, 1));  // Component set to 0 if negative
	}

	{   // *=
		dimension sizeOne(2, 6);

        sizeOne *= 3;
		EXPECT_EQ(sizeOne, dimension(6, 18));

		sizeOne *= 0;
		EXPECT_EQ(sizeOne, dimension(0, 0));
	}
}

}
