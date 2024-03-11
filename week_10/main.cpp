//
// Created by NilsMurrugarra-Llerena on 1/28/23.
//
#include "tree.h"

void main_tree()
{
    MyTree<int> T;
    cout<<"Empty: "<<T.is_empty()<<endl;

    // Example 1
    T.insert(120);
    T.insert(87);
    T.insert(43);
    T.insert(65);
    T.insert(140);
    T.insert(99);
    T.insert(130);
    T.insert(22);
    T.insert(56);

//    // Example 2
//    T.insert(20);
//    T.insert(10);
//    T.insert(30);
//    T.insert(5);
//    T.insert(15);
//    T.insert(25);
//    T.insert(40);
//    T.insert(2);
//    T.insert(8);
//    T.insert(23);
//    T.insert(27);
//    T.insert(45);

//    // Example 3: for remove
//    T.insert(120);
//    T.insert(87);
//    T.insert(140);
//    T.insert(43);
//    T.insert(99);
//    T.insert(130);
//    T.insert(22);
//    T.insert(65);
//    T.insert(93);
//    T.insert(135);
//    T.insert(56);

    cout<<"Tree: "<<endl;
    T.print();
    cout<<endl<<endl;
    cout<<endl<<"Pre_order: "<<endl;
    T.pre_order();
    cout<<endl<<"In_order: "<<endl;
    T.in_order();
    cout<<endl<<"Post_order: "<<endl;
    T.post_order();
    cout<<endl<<endl;

    // Search
    cout<<"Search for 3: "<<T.search(3)<<endl;
    cout<<"Search for 22: "<<T.search(22)<<endl;

//    cout<<"Remove element 22: "<<endl;
//    T.remove(22);
//    cout<<"Tree: "<<endl;
//    T.print();
//
//    cout<<"Remove element 99: "<<endl;
//    T.remove(99);
//    cout<<"Tree: "<<endl;
//    T.print();
//
//    cout<<"Remove element 87: "<<endl;
//    T.remove(87);
//    cout<<"Tree: "<<endl;
//    T.print();
//
//    cout<<"Remove element 120: "<<endl;
//    T.remove(120);
//    cout<<"Tree: "<<endl;
//    T.print();
//
//    cout<<"Remove element 140: "<<endl;
//    T.remove(140);
//    cout<<"Tree: "<<endl;
//    T.print();
//
//    cout<<"Remove element 135 and 56: "<<endl;
//    T.remove(135);
//    T.remove(56);
//    cout<<"Tree: "<<endl;
//    T.print();
}

void main_swap()
{
    MyTree<int> T;
    cout<<"Empty: "<<T.is_empty()<<endl;

    // Example 3: for remove
    T.insert(15);
    T.insert(20);
    T.insert(17);
    T.insert(8);
    T.insert(5);
    T.insert(13);
    T.insert(11);
    T.insert(14);

    cout<<"Tree: "<<endl;
    T.print();
    cout<<endl<<endl;

    T.swap();

    cout<<"New Tree: "<<endl;
    T.print();
    cout<<endl<<endl;

}


int main(void)
{
    main_tree();
//    main_swap();

//    int x = (-9)/2;
//    cout<<x<<endl;
//    return 0;
}