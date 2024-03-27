//
// Created by NilsMurrugarra-Llerena on 1/28/23.
//
#include "list.h"
#include "double_list.h"

void main_list_1()
{
    MyList<int> L;
    cout<<"Empty: "<<L.is_empty()<<endl;

    L.insert_end(1);
    L.insert_end(2);
    L.insert_end(3);
    L.insert_end(4);
    L.insert_end(5);
    L.insert_end(6);

    cout<<"List: "<<L<<endl;
    cout<<"Search for 3: "<<endl;
    L.search(3);
    cout<<"Search for 7: "<<endl;
    L.search(7);
    cout<<"Remove element 2: "<<endl;
    L.remove(2);
    cout<<"List: "<<L<<endl;

    L.remove_end();
    L.remove_end();

    cout<<"List [after 2 remove_end]: "<<L<<endl;
    L.remove_end();
    L.remove_end();
    L.remove_end();
    L.remove_end();
    L.remove_end(); // Empty Stack. Can not remove element.
    cout<<"List: "<<L<<endl;
}

void main_list_2()
{
    MyList<int> L;
    cout<<"Empty: "<<L.is_empty()<<endl;

    L.insert_start(1);
    L.insert_start(2);
    L.insert_start(3);
    L.insert_start(4);
    L.insert_start(5);
    L.insert_start(6);

    cout<<"List: "<<L<<endl;
    cout<<"Search for 3: "<<endl;
    L.search(3);
    cout<<"Search for 7: "<<endl;
    L.search(7);
    cout<<"Remove element 2: "<<endl;
    L.remove(2);
    cout<<"List: "<<L<<endl;

    L.remove_start();
    L.remove_start();

    cout<<"List [after 2 remove_start]: "<<L<<endl;
    L.remove_start();
    L.remove_start();
    L.remove_start();
    L.remove_start();
    L.remove_start(); // Empty Stack. Can not remove element.
    cout<<"List: "<<L<<endl;
}

void main_double_list_1()
{
    MyDoubleList<int> L;
    cout<<"Empty: "<<L.is_empty()<<endl;

    L.insert_end(1);
    L.insert_end(2);
    L.insert_end(3);
    L.insert_end(4);
    L.insert_end(5);
    L.insert_end(6);

    cout<<"List: "<<L<<endl;
    cout<<"Search for 3: "<<endl;
    L.search(3);
    cout<<"Search for 7: "<<endl;
    L.search(7);
    cout<<"Remove element 2: "<<endl;
    L.remove(2);
    cout<<"List: "<<L<<endl;

    L.remove_end();
    L.remove_end();

    cout<<"List [after 2 remove_end]: "<<L<<endl;
    L.remove_end();
    L.remove_end();
    L.remove_end();
    L.remove_end();
    L.remove_end(); // Empty Stack. Can not remove element.
    cout<<"List: "<<L<<endl;
}

void main_double_list_2()
{
    MyDoubleList<int> L;
    cout<<"Empty: "<<L.is_empty()<<endl;

    L.insert_start(1);
    L.insert_start(2);
    L.insert_start(3);
    L.insert_start(4);
    L.insert_start(5);
    L.insert_start(6);

    cout<<"List: "<<L<<endl;
    cout<<"Search for 3: "<<endl;
    L.search(3);
    cout<<"Search for 7: "<<endl;
    L.search(7);
    cout<<"Remove element 2: "<<endl;
    L.remove(2);
    cout<<"List: "<<L<<endl;

    L.remove_start();
    L.remove_start();

    cout<<"List [after 2 remove_start]: "<<L<<endl;
    L.remove_start();
    L.remove_start();
    L.remove_start();
    L.remove_start();
    L.remove_start(); // Empty Stack. Can not remove element.
    cout<<"List: "<<L<<endl;
}

int main(void)
{
//<<<<<<< HEAD:week_7/main.cpp
   // main_list_1();
//    main_list_2();

   main_double_list_1();
//=======
//    main_list_1();
//    main_list_2();

    main_double_list_1();
//>>>>>>> cd74f993aef4e8429c239c357c7bfcb939e4e276:week_6/main.cpp
//    main_double_list_2();

    return 0;
}