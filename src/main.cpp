#include <gtest/gtest.h>

#include <iostream>
#include "maths/Vector.hpp"
#include "maths/Matrix.hpp"

#include "objects/Object.hpp"
#include "objects/CircleObject.hpp"

using namespace Physics;

// -------------------
// ----- Physics -----
// -------------------
TEST(Physics, UpdateTest){
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

TEST(Physics, Size){
    Size sizeOne(1, 1);
    Size sizeSquareOne(1);
    Size zero();

    EXPECT_EQ(sizeSquareOne, sizeOne);
    EXPECT_EQ(zero, Size(0, 0));
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

/*
bool test_matrix(){
    // TODO: Fix operators, research
    Maths::Matrix m1(Maths::Unity, Size(5, 5));
    Maths::Matrix m2 = (float)2*m1;

    Maths::Matrix multOne(Maths::Random, Size(3,2));
    Maths::Matrix multTwo(Maths::Random, Size(2, 7));
    Maths::Matrix m3 = multOne * multTwo;

    std::cout << m1 << "\n";
    //cout << m2 << "\n";

    m1 *= 4;
    std::cout << m1 << "\n"; 

    //cout << multOne << "\n";
    //cout << multTwo << "\n";
    //cout << m3 << "\n";

    return false;
}
*/

int main(int argc, char **argv){
	testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
