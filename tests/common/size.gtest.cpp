#include <gtest/gtest.h>

#include "common/size.hpp"

namespace PhysEn::GTest {

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

        EXPECT_THROW(sizeOne - sizeTwo, std::domain_error);

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

        auto func = [&](){
            sizeOne -= sizeTwo;
        };
        EXPECT_THROW(func(), std::domain_error);

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
