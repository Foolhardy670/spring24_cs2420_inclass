//
// Created by NilsMurrugarra-Llerena on 1/29/23.
//

#ifndef CS2420_INCLASS_TREE_NODE_H
#define CS2420_INCLASS_TREE_NODE_H

// our node
template <class Type>
struct TreeNode{
    TreeNode(Type v):value(v),left(nullptr),right(nullptr){} //constructor
    Type value;
    TreeNode<Type>* left;
    TreeNode<Type>* right;
};

#endif //CS2420_INCLASS_TREE_NODE_H
