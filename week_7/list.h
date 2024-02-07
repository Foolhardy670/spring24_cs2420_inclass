#include <iostream>
#include <memory>
#include "node.h"
using namespace std;

template <class Type>
class MyList
{
    private:
        Node<Type>* head;
        int cnt;

    public:
        //Constructor
        MyList()
        {
            head = nullptr;
            cnt = 0;
        }

        //Destructor if using raw pointers
        ~MyList()
        {
            clear();
        }

        //Adds an item
        void insert_start(Type item)
        {
            auto q = new Node<Type>(item);
            q->next =this->head;
            this->head = q;
            cnt++;
        }

        void insert_end(Type item)
        {
            auto t  = this->head;
            auto q = new Node<Type>(item);
            if(this->is_empty())
                this->head = q;
            else
            {
                while(t->next != nullptr) // O(n)
                    t = t->next;
                t->next = q;
            }
            cnt++;
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
                if(q->next == nullptr) // only one node
                    this->head = nullptr;
                else
                    this->head = q->next;
                delete q;
            }
            cnt--;
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
                auto p = this->head;
                if(p->next == nullptr) // only one node
                {
                    delete p;
                    this->head = nullptr;
                }
                else
                {
                    auto q = p, t = q;
                    while( q->next != nullptr )
                    {
                        t = q; // store previous to last node
                        q = q->next; // store last node
                    }
                    t->next = nullptr;
                    delete q;
                }
                cnt--;
            }
        }

        void remove(Type data)
        {
            auto q = this->head, t = q;
            bool flag = true;

            while(q->value != data && flag== true)
            {
                if( q->next != nullptr )
                {
                    t = q;
                    q = q->next;
                }
                else
                    flag= false;
            }

            if(flag == false)
            {
                //throw runtime_error("Element was not found.\n");
                printf("Element was not found.\n");
            }
            else
            {
                if(this->head == q) // removing first element?
                    this->head = q->next;
                else
                    t->next = q->next;
                delete q;
                cnt--;
            }
        }

        void search(Type data)
        {
            auto q = this->head;
            while(q != nullptr && q->value!= data)
                q = q->next;

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
            return (head == nullptr);
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
        friend ostream &operator<<(ostream &out, const MyList<Type> &q)
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
