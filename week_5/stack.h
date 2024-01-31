#include <iostream>
#include <memory>
#include "node.h"
using namespace std;

template <class Type>
class MyStack
{
    private:
        Node<Type>* top;
        int cnt;

    public:
        //Constructor
        MyStack(){
            top = nullptr;
            cnt = 0;
        }

        Node<Type>* get_top()
        {
            return this->top;
        }

        //Destructor if using raw pointers
        ~MyStack(){
            clear();
        }

        //Adds an item
        void push(Type item)
        {
            auto q = new Node<Type>(item);
            if(this->is_empty()) // Empty Stack
                top = q;
            else
            {
                q->next =top;
                top =q;
            }
            cnt++;
        }

        //Removes an item
        void pop()
        {
            if(this->is_empty())
            {
                //throw runtime_error("Empty Stack. Can not remove elements.\n");
                printf("Empty Stack. Can not remove elements.\n");
            }
            else
            {
                auto q = top;
                top = top->next;
                delete q;
                cnt--;
            }
        }

        //Returns the size
        int size(){
            return cnt;
        }

        //Returns true if empty
        bool is_empty()
        {
            return (top == nullptr);
        }

        //Erases all the items
        void clear()
        {
            cnt =0;
            auto temp=top;
            while(top)
            {
                top = top->next;
                delete temp;
                temp = top;
            }
        }

        //Displays all the items
        friend ostream& operator<< (ostream &out, MyStack<Type>& q)
        {
            auto temp = q.top;
            while (temp) {
                out << temp->value;
                if (temp->next)
                    out << " ";
                temp = temp->next;
            }
            return out;
        }
};
