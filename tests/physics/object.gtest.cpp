#include "gtest/gtest.h"

#include "object.hpp"

namespace phys::gtest {

using Vector = vector<double, 3>;

TEST(PhysicsObjects, Update) {
	object firstObject(
		Vector({0.0, 100.0, 0.0}),
		Vector({20.0, 0.0, 0.0}),
		Vector({0.0, -10.0, 0.0})
	);

	object secondObject = firstObject;

	int time = 5; // 5 seconds
	while(time-- > 0)
		firstObject.update();
	time = 5;

	secondObject.update(static_cast<float>(time));

	// TODO: Not just compare if same result, also compare against real result
	//   Calculate result by hand and compare
	ASSERT_EQ(firstObject.getPosition(), secondObject.getPosition());
	ASSERT_EQ(firstObject.getVelocity(), secondObject.getVelocity());
	ASSERT_EQ(firstObject.getAcceleration(), secondObject.getAcceleration());
}

}
