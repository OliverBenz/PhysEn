#include "gtest/gtest.h"

#include "../src/objects/Object.hpp"

using namespace Physics;

/*
class PhysicsTests: public ::testing::Test {
    PhysicsTests() { }

    void SetUp() { }

    void TearDown() { }
};
*/

//TEST(PhysicsTests, Update) {
TEST(ObjectTests, Update) {
    Objects::Object firstObject(
            Maths::Vector(0.0f, 100.0f, 0.0f),
            Maths::Vector(20.0f, 0.0f, 0.0f),
            Maths::Vector(0.0f, -10.0f, 0.0f)
        );

        Objects::Object secondObject = firstObject;

    int time = 5; // 5 seconds
    while(time-- > 0)
        firstObject.update();
    time = 5;

    secondObject.update((float)time);

    ASSERT_EQ(firstObject.getPosition(), secondObject.getPosition());
    ASSERT_EQ(firstObject.getVelocity(), secondObject.getVelocity());
    ASSERT_EQ(firstObject.getAcceleration(), secondObject.getAcceleration());
}