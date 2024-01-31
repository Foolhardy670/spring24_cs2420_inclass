//
// Created by NilsMurrugarra-Llerena on 1/28/23.
//
#include "static_stack.h"
#include "static_queue.h"
#include "stack.h"
#include "queue.h"
#include "node.h"

void main_static_stack()
{
    StaticStack<int> s(5);
    cout<<"Empty: "<<s.is_empty()<<endl;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6); // Stack is full. Can not insert element.

    cout<<"Full: "<<s.is_full()<<endl;
    cout<<"Stack: "<<s<<endl;

    s.pop();
    s.pop();

    cout<<"Stack: "<<s<<endl;
    s.pop();
    s.pop();
    s.pop();
    s.pop(); // Empty Stack. Can not remove element.
    s.pop(); // Empty Stack. Can not remove element.
    cout<<"Stack: "<<s<<endl;
}

void main_static_queue()
{
    StaticQueue<int> q(5);
    cout<<"Empty: "<<q.is_empty()<<endl;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6); // Queue is full. Can not insert element.

    cout<<"Full: "<<q.is_full()<<endl;
    cout<<"Queue: "<<q<<endl;

    q.dequeue();
    q.dequeue();

    cout<<"Queue: "<<q<<endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue(); // Empty Queue. Can not remove element.
    q.dequeue(); // Empty Queue. Can not remove element.
    cout<<"Queue: "<<q<<endl;
}

void print_recur(Node<int>* S)
{
    if(S == nullptr)
        cout<<" "<<endl;
    else
    {
        cout<<S->value<<" ";
        print_recur( S->next );
    }
}

void main_stack()
{
    MyStack<int> s;
    cout<<"Empty: "<<s.is_empty()<<endl;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    cout<<"Stack: "<<s<<endl;
    cout<<"Recursive Stack: "<<endl;
    print_recur( s.get_top() );

    s.pop();
    s.pop();

    cout<<"Stack: "<<s<<endl;
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop(); // Empty Stack. Can not remove element.
    cout<<"Stack: "<<s<<endl;
}

void main_queue()
{
    MyQueue<int> q;
    cout<<"Empty: "<<q.is_empty()<<endl;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);

    cout<<"Queue: "<<q<<endl;

    q.dequeue();
    q.dequeue();

    cout<<"Queue: "<<q<<endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue(); // Empty Queue. Can not remove element.

    cout<<"Queue: "<<q<<endl;
}

int main(void)
{
    main_static_stack();
//    main_static_queue();
//    main_stack();
//    main_queue();

    return 0;
}