#include <gtest/gtest.h>

#include "../src/maths/Size.hpp"

TEST(Size, Construction){
    {   // Zero Size
        Physics::Size size;

        EXPECT_EQ(size.rows, size.columns);
        EXPECT_EQ(size.rows, 0);
    }

    {   // Custom Size
        Physics::Size size(3, 4);

        EXPECT_EQ(size.rows, 3);
        EXPECT_EQ(size.columns, 4);
    }

    {   // Square Size
        Physics::Size size(5);

        EXPECT_EQ(size.rows, size.columns);
        EXPECT_EQ(size.rows, 5);
    }
}

TEST(Size, Operators) {
    {   // ==
        Physics::Size sizeOne(5);
        Physics::Size sizeTwo(5, 5);

        EXPECT_EQ(sizeOne, sizeTwo);
    }

	{   // +
        Physics::Size sizeOne(4);
        Physics::Size sizeTwo(5, 5);

        Physics::Size sizeThree = sizeOne + sizeTwo + Physics::Size(1, 1);
        EXPECT_EQ(sizeThree, Physics::Size(10, 10));
	}

    {   // -
        Physics::Size sizeOne(4);
        Physics::Size sizeTwo(5, 5);

		Physics::Size result = sizeOne - sizeTwo;
		EXPECT_EQ(result, Physics::Size(0, 0)); // Size set to (0,0) if negative

		result = sizeTwo - sizeOne;
		EXPECT_EQ(result, Physics::Size(1, 1));
    }

    {   // +=
        Physics::Size sizeOne(4);
        Physics::Size sizeTwo(5, 5);

        sizeOne += sizeTwo;
        EXPECT_EQ(sizeOne, Physics::Size(9, 9));
    }

	{   // -=
        Physics::Size sizeOne(4);
        Physics::Size sizeTwo(5, 5);

		sizeOne -= sizeTwo;
		EXPECT_EQ(sizeOne, Physics::Size(0, 0)); // Size set to (0,0) if negative

		sizeOne = Physics::Size(12, 4);
		sizeTwo -= sizeOne;
		EXPECT_EQ(sizeTwo, Physics::Size(0, 1));  // Component set to 0 if negative
	}

	{   // *=
        Physics::Size sizeOne(2, 6);
		sizeOne *= 3;

		EXPECT_EQ(sizeOne, Physics::Size(6, 18));

		sizeOne *= -1;
		EXPECT_EQ(sizeOne, Physics::Size(6, 18));

		sizeOne *= 0;
		EXPECT_EQ(sizeOne, Physics::Size(0, 0));
	}

}