#include<iostream>
#include "circle.h"

using namespace std;

int main(void)
{
//    // Init: simple
//    Circle c1;
//    Circle c2( 21 );
//    cout << "c1.Area: " << c1.getArea() <<endl;
//    cout << "c2.Area: " << c2.getArea() <<endl;

    // Init: pointers
    Circle *c1 = new Circle();
    Circle *c2 = new Circle( 21 );
    cout << "c1.Area: " << c1->getArea() << endl;
    cout << "c2.Area: " << c2->getArea() << endl;

    return 0;
}


