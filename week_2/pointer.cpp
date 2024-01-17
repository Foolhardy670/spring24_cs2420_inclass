//
// Created by NilsMurrugarra-Llerena on 1/2/23.
//

// comment
#include <iostream>
using namespace std;

void pointer_address()
{
    int var1 = 11;
    int var2 = 22;
    int var3 = 33;
    cout << &var1 << endl
         << &var2 << endl
         << &var3 << endl;
}

void deref_pointers()
{
    int var1 = 11;
    int var2 = 22;
    int* iptr;
    iptr = &var1;
    cout << "var1: "<< var1 << ", *iptr: " << *iptr <<", iptr.address: " << iptr << endl;
//    iptr = &var2; // copy address location [Update Address]
    *iptr = var2; // copy address location [Update Value]
    cout << "var1: " << var1 << ", var2: " << var2 << ", *iptr: " << *iptr <<", iptr.address: " << iptr<< endl;
}

void pointer_change_value()
{
    int num = 11;
    int* ptr = &num;
    num = 2;
    cout << "num: " << num << ", *ptr: " << *ptr << ", ptr: " << ptr << endl;
//    *ptr = 53;
//    cout << "num: " << num << ", *ptr: " << *ptr << ", ptr: " << ptr <<  endl;
}

void   passByVal(int num){ num = 2; }
void   passByRef(int & num){ num = 3; }
void   passByPtr(int* num){ *num = 4;}

void passing_variables()
{
    int n = 1;
    passByVal(n);
    cout << "[passByVal] n: " << n << endl;
    passByRef(n);
    cout << "[passByRef] n: " <<  n << endl;
    passByPtr(&n);
    cout << "[passByPtr] n: " <<  n << endl;
}

// Pointers to objects
struct Point {
    int x;int y;
};

void pointers2objects()
{
    Point* structPtr = new Point();

    delete structPtr;	//must delete

    // Dot operator with point
    Point* t = new Point;
    (*t).x = 11;
    (*t).y = 45;
    cout<<"[Point .] x:"<<(*t).x<<", y:"<<(*t).y<<endl;
    delete t;

    // Arrow operator
    Point* t2 = new Point;
    t2->x = 11;
    t2->y = 45;
    cout<<"[Point ->] x:"<<t2->x<<", y:"<<t2->y<<endl;
    delete t;
}


int main()
{
//    pointer_address();
//    deref_pointers();
//    pointer_change_value();
//    passing_variables();
    pointers2objects();
    return 0;
}
