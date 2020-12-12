#include <gtest/gtest.h>

#include <iostream>
#include "maths/Vector.hpp"
#include "maths/Matrix.hpp"

#include "objects/Object.hpp"
#include "objects/CircleObject.hpp"

namespace Physics{
namespace Testing{

// -------------------
// ----- Physics -----
// -------------------
TEST(Physics, UpdateTest){
    // Create two equal objects.
    //   One updates updates five times periodically
    //   One updates 5 seconds at once.
    // Check if the updates moved the objects the same way
    Objects::Object obj(
        Maths::Vector(0.0f, 100.0f, 0.0f),
        Maths::Vector(20.0f, 0.0f, 0.0f),
        Maths::Vector(0.0f, -10.0f, 0.0f)
    );
    Objects::Object obj1 = obj;

    int t = 5; // 5 seconds
    while(t-->0)
        obj.update();
    t = 5;

    obj1.update((float)t);

    EXPECT_EQ(obj.getPosition(), obj1.getPosition());
    EXPECT_EQ(obj.getVelocity(), obj1.getVelocity());
    EXPECT_EQ(obj.getAcceleration(), obj1.getAcceleration());
}

TEST(Physics, SizeInitialize){
    Size sizeOne(1, 1);
    Size sizeSquareOne(1);

    EXPECT_EQ(sizeSquareOne, sizeOne);

    Size zeroOne;
    Size zeroTwo(0);
    Size zeroThree(0, 0);

    EXPECT_EQ(zeroOne, zeroTwo);
    EXPECT_EQ(zeroOne, zeroThree);
}

// -------------------
// ------ Maths ------
// -------------------
TEST(Maths, VectorCrossProduct){
    Maths::Vector a(2, 3, 4);
    Maths::Vector b(5, 6, 7);
    Maths::Vector c = a.getCrossProduct(b);

    ASSERT_EQ(c.x, -3);
    ASSERT_EQ(c.y, 6);
    ASSERT_EQ(c.z, -3);
}

TEST(Maths, VectorOperations){
    Maths::Vector a(1, 1, 2);
    Maths::Vector b(1, 1, 2);

    // ==
    EXPECT_EQ(a, b);
    // !=
    EXPECT_EQ(!(a != b), true);
    // +
    EXPECT_EQ(a+b, Maths::Vector(2, 2, 4));
    // *
    EXPECT_EQ(a*b, Maths::Vector(1, 1, 4));
}

TEST(Maths, MatrixOperations){
    // Test matrix multiplication with number
    Maths::Matrix matrix(Maths::Unity, Size(5, 5));
    Maths::Matrix matrixDouble = (float)2 * matrix;

    std::cout << matrix << "\n";

    matrix *= 4;
    std::cout << matrix << "\n"; 


    // Test Matrix multiplication
    Maths::Matrix multOne(Maths::Random, Size(3,2));
    Maths::Matrix multTwo(Maths::Random, Size(2, 7));
    Maths::Matrix m3 = multOne * multTwo;


    // TODO implement testing functions
    ASSERT_EQ(true, true);
}

}
}

int main(int argc, char **argv){
	testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
