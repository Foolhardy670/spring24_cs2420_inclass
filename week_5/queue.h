#include <iostream>
#include <memory>
#include "node.h"
using namespace std;

template <class Type>
class MyQueue
{
    private:
        Node<Type>* tail;
        Node<Type>* head;
        int cnt;

    public:
        //Constructor
        MyQueue()
        {
            tail = nullptr;
            head = nullptr;
            cnt = 0;
        }


        //Destructor if using raw pointers
        ~MyQueue()
        {
            clear();
        }

        //Adds an item
        void enqueue(Type item)
        {
            auto p = new Node<Type>(item);
            if( this->is_empty() )
            {
                tail = p;
                head = p;
            }
            else
            {
                tail->next =p;
                tail =p;
            }
            cnt++;
        }

        //Removes an item
        void dequeue()
        {
            if( this->is_empty() )
            {
                //throw runtime_error("Empty Queue. Can not remove elements.\n");
                printf("Empty Queue. Can not remove elements.\n");
            }
            else
            {
                auto temp = head;
                head = head->next;
                delete temp;
                cnt--;
                if(head == nullptr)
                    tail = nullptr;
            }
        }

        //Returns the size
        int size(){
            return cnt;
        }

        //Returns true if empty
        bool is_empty(){
            return (head == nullptr and tail == nullptr);
        }

        //Erases all the items
        void clear()
        {
            cnt =0;
            auto temp=head;
            while(head)
            {
                head = head->next;
                delete temp;
                temp = head;
            }
        }

        //Displays all the items
        friend ostream &operator<<(ostream &out, const MyQueue<Type> &q)
        {
            auto temp = q.head;
            while (temp) {
                out << temp->value;
                if (temp->next)
                    out << " ";
                temp = temp->next;
            }
            return out;
        }
};
