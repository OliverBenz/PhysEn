#include <iostream>
#include "lib/Object.hpp"
#include "lib/Vector.hpp"
#include "lib/CircleObject.hpp"
#include "lib/Matrix.hpp"

using namespace std;
using namespace Physics;

bool test_update(){
    Object obj(
        Maths::Vector(0.0f, 100.0f, 0.0f),
        Maths::Vector(20.0f, 0.0f, 0.0f),
        Maths::Vector(0.0f, -10.0f, 0.0f)
    );
    Object obj1 = obj;

    int t = 5; // 5 seconds
    while(t-->0)
        obj.update();
    t = 5;

    obj1.update((float)t);

    return obj.getPosition() == obj1.getPosition() && obj.getVelocity() == obj1.getVelocity() && obj.getAcceleration() == obj1.getAcceleration();
}

bool test_cross_product(){
    Maths::Vector a(2, 3, 4);
    Maths::Vector b(5, 6, 7);
    Maths::Vector c = a.getCrossProduct(b);

    return c.x == -3 && c.y == 6 && c.z == -3;
}

bool test_vec_operators(){
    Maths::Vector a(1, 1, 2);
    Maths::Vector b(1, 1, 2);

    // +, -, *, /, ==, !=

    return a == b && !(a != b) && ((a + b) == Maths::Vector(2, 2, 4)) && (a*b == Maths::Vector(1, 1, 4));
}

bool test_matrix(){
    // TODO: Fix operators, research
    Maths::Matrix m1(Maths::Unity, Size(5, 5));
    Maths::Matrix m2 = (float)2*m1;

    Maths::Matrix multOne(Maths::Random, Size(3,2));
    Maths::Matrix multTwo(Maths::Random, Size(2, 7));
    Maths::Matrix m3 = multOne * multTwo;

    cout << m1 << "\n";
    //cout << m2 << "\n";

    m1 *= 4;
    cout << m1 << "\n"; 

    //cout << multOne << "\n";
    //cout << multTwo << "\n";
    //cout << m3 << "\n";

    return false;
}

int main(){
	cout << "Library version: " << VERSION_MAJOR << "." << VERSION_MINOR << "." << VERSION_PATCH << "\n";
    // Vector tests
    cout << "Vector Test results:" << "\n";
    cout << "Operators:\t" << (test_vec_operators() ? "True" : "False") << "\n";
    cout << "Cross-Product:\t" << (test_cross_product() ? "True" : "False") << "\n";

    cout << "\n";
    cout << "Object Update:\t" << (test_update() ? "True" : "False") << "\n";

    CircleObject circ(
        Maths::Vector(1, 2, 0),
        5800
    );

    cout << circ.getCentripedalAcc(694) << "\n";

    if(test_matrix()){}

    return 0;
}
