#include <iostream>
#include <memory>
using namespace std;

template <class Type>
class StaticQueue
{
    private:
        int head;
        int tail;
        int max;
        Type* array;

    public:
        //Constructor
        StaticQueue(int m)
        {
            head = -1;
            tail = -1;
            max = m;
            array = new Type[this->max];
        }

        bool is_empty()
        {
            if(this->head == -1)
                return true;
            else
                return false;
        }

        bool is_full()
        {
            if((this->tail+1) == this->max)
                return true;
            else
                return false;
        }

        //Adds an item
        void enqueue(Type item)
        {
            if(this->is_full())
            {
                //throw runtime_error("Full Queue. Can not add more elements.\n");
                printf("Full Queue. Can not add more elements.\n");
            }
            else
            {
                this->tail = this->tail + 1;
                this->array[this->tail] = item;
                if(this->tail == 0)
                    this->head = 0;
            }
        }

        //Removes an item
        Type dequeue()
        {
            if(this->is_empty())
            {
                //throw runtime_error("Empty Queue. Can not remove elements.\n");
                printf("Empty Queue. Can not remove elements.\n");
                return -1;
            }
            else
            {
                Type data = this->array[this->head];
                if(this->head == this->tail)// Queue only has one element
                {
                    this->head = -1;
                    this->tail = -1;
                }
                else
                    this->head = this->head + 1;
                return data;
            }
        }

        //Returns the size
        int size(){
            return (this->tail - this->head + 1);
        }

        //Displays all the items
        friend ostream &operator<<(ostream &out, StaticQueue<Type> &q)
        {
            if(q.is_empty())
                out<<" ";
            else
                for(int i=q.head; i<= q.tail; i++)
                    out << q.array[i] << " ";
            return out;
        }
};
