//
// Created by NilsMurrugarra-Llerena on 1/2/23.
//
#include<iostream>
#include "task.h"
#include "message.h"

using namespace std;

void smart_pointer()
{
    // Init type 1
    cout<<"[Init type 1]"<<endl;
    unique_ptr<Task> p = make_unique<Task>();
//    auto p = make_unique<Task>();
    p->act();
    (*p).act();

//    // Init type 2
//    cout<<"[Init type 2]"<<endl;
//    unique_ptr<Task> tPtr(new Task());
////    auto tPtr(new Task());
//    tPtr->act();
//    (*tPtr).act();

    // Call destructor automatically for both cases
}


void array_pointer()
{
    auto pointerArray = make_unique<Task[]>(3);
    for(int i = 0; i < 3; i++)
    {
        pointerArray[i].act();
    }

    //Destructors
}

void move_fun()
{
    unique_ptr <int>n1 (new int(15));
    unique_ptr <int>n2 = move(n1); // Invalidate first pointer
    cout << "*n2: " << *n2 << endl ;
    cout << "*n1: " << *n1 << endl; // Throw Signal error
}

void copy_pointer(shared_ptr<int>second)
{
    cout << "Function: " << second.use_count() << endl;
    auto third = second;
    cout << "Another: " << second.use_count() << endl;
}

void copy_example()
{
    auto first = make_shared<int>(5);
    cout << "Main: " << first.use_count() << endl;
    copy_pointer(first);
    cout << "Main: " << first.use_count() << endl;
}

void copy_example_2()
{
    auto first = make_shared<Message>("One");
    auto second = first;
    auto third = first->deep_copy();
    second->set_message("Second");
    first->show(); // Second
    second->show(); // Second
    third->show(); // One
}

int main()
{
//    smart_pointer();
//    array_pointer();
//    move_fun();
//    copy_example();
    copy_example_2();
    return 0;
}