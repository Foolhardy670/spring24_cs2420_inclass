//
// Created by NilsMurrugarra-Llerena on 1/29/23.
//

#ifndef CS2420_INCLASS_NODE_H
#define CS2420_INCLASS_NODE_H

// our node
template <class Type>
struct Node{
    Node(Type v):value(v),next(nullptr){} //constructor
    Type value;
    Node<Type>* next;
};

#endif //CS2420_INCLASS_NODE_H
