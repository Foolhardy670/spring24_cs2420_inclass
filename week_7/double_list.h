#include <iostream>
#include <memory>
#include "double_node.h"
using namespace std;

template <class Type>
class MyDoubleList
{
    private:
        DoubleNode<Type>* head;
        DoubleNode<Type>* tail;
        int cnt;

    public:
        //Constructor
        MyDoubleList()
        {
            head = nullptr;
            tail = nullptr;
            cnt = 0;
        }

        //Destructor if using raw pointers
        ~MyDoubleList()
        {
            clear();
        }

        //Adds an item
        void insert_start(Type item)
        {
            auto q = new DoubleNode<Type>(item);
            if(this->is_empty())
            {
                this->head = q;
                this->tail = q;
            }
            else
            {
                auto p = this->head;
                q->next =p;
                p->prev = q;
                this->head = q;
            }
            cnt++;
        }

        void insert_end(Type item)
        {
            auto q = new DoubleNode<Type>(item);// O(1)

            if(this->is_empty()) // O(1)
            {
                this->head = q; // O(1)
                this->tail = q; // O(1)
            }
            else
            {
                this->tail->next = q; // O(1)
                q->prev = this->tail; // O(1)
                this->tail = q; // O(1)
            }
            cnt++; // O(1)
        }

        //Removes an item
        void remove_start()
        {
            if( this->is_empty() )
            {
                //throw runtime_error("Empty List. Can not remove elements.\n");
                printf("Empty List. Can not remove elements.\n");
            }
            else
            {
                auto q = this->head;
                if(q->next == nullptr) // only has 1 element
                {
                    this->head= nullptr;
                    this->tail = nullptr;
                }
                else
                {
                    this->head = q->next;
                    this->head->prev = nullptr;
                }
                delete q;
                cnt--;
            }
        }

        void remove_end()
        {
            if( this->is_empty() )
            {
                //throw runtime_error("Empty List. Can not remove elements.\n");
                printf("Empty List. Can not remove elements.\n");
            }
            else
            {
                auto q = this->tail;
                if(q->prev == nullptr)// has only 1 element
                {
                    this->head = nullptr;
                    this->tail = nullptr;
                }
                else
                {
                    this->tail = q->prev;
                    this->tail->next = nullptr;
                }
                delete q;
                cnt--;
            }
        }

        void remove(Type data)
        {
            auto q = this->head;
            while(q->next != nullptr && q->value!=data)
                q = q->next;

            if(q->value != data)
            {
                //throw runtime_error("Element was not found.\n");
                printf("Element was not found.\n");
            }
            else
            {
                if(q==this->head && q==this->tail) // has only 1 element
                {
                    this->head = nullptr;
                    this->tail = nullptr;
                }
                else
                {
                    if(q == this->head)// q is the first element
                    {
                        this->head = q->next;
                        this->head->prev = nullptr;
                    }
                    else if(q == this->tail)// q is the last element
                    {
                        this->tail = q->prev;
                        this->tail->next = nullptr;
                    }
                    else
                    {
                        auto t = q->prev;
                        auto r = q->next;
                        t->next = r;
                        r->prev = t;
                    }
                }
                delete q;
                cnt--;
            }
        }

        void search(Type data)
        {
//            cout<<"Head Start: "<<this->head<<endl;
            auto q = this->head;
            while(q != nullptr && q->value!= data)
                q = q->next;
//            cout<<"Head End: "<<this->head<<endl;

            if(q== nullptr)
            {
                //throw runtime_error("Element was not found.\n");
                printf("Element was not found.\n");
            }
            else
            {
                //throw runtime_error("Element was found.\n");
                printf("Element was found.\n");
            }
        }

        //Returns the size
        int size(){
            return cnt;
        }

        //Returns true if empty
        bool is_empty(){
            return (this->head == nullptr && this->tail == nullptr);
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
        friend ostream &operator<<(ostream &out, const MyDoubleList<Type> &q)
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
