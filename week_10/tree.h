#include <iostream>
#include <memory>
#include "tree_node.h"
using namespace std;
#define COUNT 5

template <class Type>
class MyTree
{
    private:
        TreeNode<Type>* root;

    public:
        //Constructor
        MyTree()
        {
            root = nullptr;
        }

        //Adds an item
        void insert(Type item)
        {
            // Option 2
//            this->root = insert_2(item, this->root);

            // Option 1
            if (this->root == nullptr)
                this->root = new TreeNode<Type>(item);
            else
            {
                return insert(this->root, item);
            }
        }

        void insert(TreeNode<Type>* node, Type item)
        {
            if(item < node->value)
            {
                if(node->left == nullptr)
                {
                    auto new_node = new TreeNode<Type>(item);
                    node->left = new_node;
                }
                else
                    return this->insert(node->left, item);
            }
            else if(item > node->value)
            {
                if(node->right == nullptr)
                {
                    auto new_node = new TreeNode<Type>(item);
                    node->right = new_node;
                }
                else
                    return this->insert(node->right, item);
            }
            else
                throw runtime_error("Node is already in tree");
        }

        TreeNode<Type>* insert_2(Type item, TreeNode<Type> *ptr)
        {
            if(ptr == nullptr)
            {
                auto new_node = new TreeNode<Type>(item);
                return new_node;
            }
            else
            {
                if(item < ptr->value)
                {
                    ptr->left = insert_2(item, ptr->left);
                    return ptr;
                }
                else if(item > ptr->value)
                {
                    ptr->right = insert_2(item, ptr->right);
                    return ptr;
                }
                else
                    throw runtime_error("Node is already present in tree");
            }
        }

        void remove(Type item)
        {
            this->root = remove(this->root, item);
        }

        TreeNode<Type>* remove(TreeNode<Type>* node, Type item)
        {
            bool flag;

            if(node != nullptr)
            {
                if(item < node->value)
                {
                    node->left = this->remove(node->left, item);
                    return node;
                }
                else if(item > node->value)
                {
                    node->right = this->remove(node->right, item);
                    return node;
                }
                else
                {
                    auto temp = node;
                    if (temp->right == nullptr)
                        node = temp->left;
                    else
                    {
                        if(temp->left == nullptr)
                        {
                            node = temp->right;
                        }
                        else
                        {
                            auto rmn = temp->left;// Right most node
                            auto parent_rmn = new TreeNode<Type>(1);//temp
                            flag = false;
                            // Get most right node from left child
                            while(rmn->right != nullptr)
                            {
                                parent_rmn = rmn;
                                rmn = rmn->right;
                                flag = true;
                            }
                            node->value = rmn->value; // update node to eliminate
                            temp = rmn;
                            if(flag == true)
                                parent_rmn->right =  rmn->left; // rmn has no right
                            else
                                node->left = rmn->left;
                        }
                    }
                    delete(temp);
                    return node;
                }
            }
            else
            {
                throw runtime_error("Node is not present in tree.");
            }
        }

        // Other
        bool search(Type item)
        {
            return this->search(root, item);
        }

        bool search(TreeNode<Type>* node, Type item)
        {
            if(node == nullptr)
                return false;
            else
            {
                if(item < node->value )
                    return search(node->left, item);
                else if(item > node->value)
                    return search(node->right, item);
                else
                    return true;
            }
        }

        void pre_order()
        {
            this->pre_order(this->root);
        }

        void in_order()
        {
            this->in_order(this->root);
        }

        void post_order()
        {
            this->post_order(this->root);
        }

        void pre_order(TreeNode<Type>* node)
        {
            if(node != nullptr)
            {
                cout<<node->value<<" ";
                pre_order(node->left);
                pre_order(node->right);
            }
        }

        void in_order(TreeNode<Type>* node)
        {
            if(node != nullptr)
            {
                in_order(node->left);
                cout<<node->value<<" ";
                in_order(node->right);
            }
        }

        void post_order(TreeNode<Type>* node) {
            if (node != nullptr) {
                post_order(node->left);
                post_order(node->right);
                cout << node->value << " ";
            }
        }

        void print2DUtil(TreeNode<Type>* root, int space)
        {
            // https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
            // Base case
            if (root == nullptr)
                return;

            // Increase distance between levels
            space += COUNT;

            // Process right child first
            print2DUtil(root->right, space);

            // Print current node after space
            // count
            cout << endl;
            for (int i = COUNT; i < space; i++)
                cout << " ";
            cout << root->value << "\n";

            // Process left child
            print2DUtil(root->left, space);
        }

        void print()
        {
            print2DUtil(root, 0);
        }

        bool is_empty()
        {
            return( this->root == nullptr);
        }

        void swap()
        {
            swap(this->root);
        }

        void swap(TreeNode<Type>* node)
        {
            if(node != nullptr)
            {
                auto temp = node->right;
                node->right = node->left;
                node->left = temp;
                swap(node->left);
                swap(node->right);
            }
        }
};
