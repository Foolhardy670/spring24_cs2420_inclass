//
// Created by NilsMurrugarra-Llerena on 1/29/23.
//

#ifndef CS2420_INCLASS_DOUBLE_NODE_H
#define CS2420_INCLASS_DOUBLE_NODE_H

// our node
template <class Type>
struct DoubleNode{
    DoubleNode(Type v):value(v),next(nullptr),prev(nullptr){} //constructor
    Type value;
    DoubleNode<Type>* next;
    DoubleNode<Type>* prev;
};

#endif //CS2420_INCLASS_DOUBLE_NODE_H
