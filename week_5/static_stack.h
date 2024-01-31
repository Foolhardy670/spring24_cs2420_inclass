#include <iostream>
#include <memory>
using namespace std;

template <class Type>
class StaticStack
{
    private:
        int top;
        int max;
        Type* array;

    public:
        //Constructor
        StaticStack(int m){
            max = m;//size
            top = -1;
            array = new Type[this->max];
        }

        bool is_empty(){
            if(this->top == -1)
                return true;
            else
                return false;
        }

        bool is_full() {
            if((this->top + 1)== this->max)
                return true;
            else
                return false;
        }

        //Adds an item
        void push(Type item)
        {
            bool f = this->is_full();
            if(f)
            {
                // throw runtime_error("Stack is full. Can not insert element.\n");
                printf("Stack is full. Can not insert element.\n");
            }
            else
            {
                this->top = this->top + 1;
                this->array[this->top] = item;
            }
        }

        //Removes an item
        Type pop()
        {
            Type data;
            bool f = this->is_empty();
            if(f)
            {
                //throw runtime_error("Empty Stack. Can not remove element.\n");
                printf("Empty Stack. Can not remove element.\n");
            }
            else
            {
                data = this->array[this->top];
                this->top = this->top - 1;
            }
            return data;
        }

        //Returns the size
        int size(){
            return (this->top + 1);
        }

        //Displays all the items
        friend ostream& operator<< (ostream &out, StaticStack<Type>& q)
        {
            for(int i=0; i<= q.top; i++)
                out << q.array[i] << " ";
            return out;
        }
};
