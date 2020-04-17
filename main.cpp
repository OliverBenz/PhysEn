#include <iostream>
#include "lib/Object.hpp"
#include "lib/Vector.hpp"

using namespace std;

int main(){
    Object obj(
        Vector(0.0f, 100.0f, 0.0f),
        Vector(20.0f, 0.0f, 0.0f),
        Vector(0.0f, -10.0f, 0.0f)
    );
    Object obj1 = obj;

    int t = 5;
    while(t --> 0)
        obj.update();
    t=5;
    
    cout << "------------------------------" << endl;
    cout << obj << endl;
    cout << "------------------------------" << endl;
    obj1.update((float)t);
    cout << obj1 << endl;

    return 0;
}