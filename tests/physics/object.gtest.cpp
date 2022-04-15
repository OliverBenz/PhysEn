#include "gtest/gtest.h"

#include "physics/object.hpp"

namespace phys::gtest {

using Vector = maths::Vector<double, 3>;

TEST(PhysicsObjects, Update) {
	objects::Object firstObject(
		Vector({0.0, 100.0, 0.0}),
		Vector({20.0, 0.0, 0.0}),
		Vector({0.0, -10.0, 0.0})
	);

	objects::Object secondObject = firstObject;

	int time = 5; // 5 seconds
	while(time-- > 0)
		firstObject.update();
	time = 5;

	secondObject.update((float)time);

	// TODO: Not just compare if same result, also compare against real result
	//   Calculate result by hand and compare
	ASSERT_EQ(firstObject.getPosition(), secondObject.getPosition());
	ASSERT_EQ(firstObject.getVelocity(), secondObject.getVelocity());
	ASSERT_EQ(firstObject.getAcceleration(), secondObject.getAcceleration());
}

}
