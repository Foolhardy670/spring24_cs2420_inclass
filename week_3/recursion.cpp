//
// Created by NilsMurrugarra-Llerena on 1/18/23.
//
#include<iostream>
#include<limits.h>

using namespace std;

int fact(int n)
{
    if(n==0 || n==1)
        return 1;
    else
        return n * fact(n-1);
}

int fact_iter(int n)
{
    int fact = 1;
    while(n>0)
    {
        fact = n * fact;
        n -= 1;
    }
    return fact;
}

void main_fact()
{
    int n = 4;
    int fact_recursive = fact(n);
    int fact_iterative = fact_iter(n);
    cout<<"[factorial] recursive: "<<fact_recursive<<", iterative: "<<fact_iterative<<endl;
}

int fib(int n)
{
    if(n==0 || n==1)
        return n;
    else
        return fib(n-1) + fib(n-2);
}

int fib_iter(int n)
{
    int fib, fib_a, fib_b, i;
    if (n==0 || n==1)
        fib = n;
    else
    {
        fib_a = 0;
        fib_b = 1;
        i = 2;

        while(i<=n)
        {
            fib = fib_a + fib_b;
            fib_a = fib_b;
            fib_b = fib;
            i += 1;
        }
    }
    return fib;
}

void main_fib()
{
    int n = 4;
    int fib_recursive = fib(n);
    int fib_iterative = fib_iter(n);
    cout<<"[Fibonacci] recursive: "<<fib_recursive<<", iterative: "<<fib_iterative<<endl;
}

void print_first(int num)
{
    cout<<num<<", ";
    if(num == 1)
        return;
    else
        print_first(num-1);
}

void print_last(int num)
{
    if(num == 1)
        return;
    else
        print_last(num-1);
    cout<<num<<", ";
}

void main_print()
{
    int n = 5;
    cout<<endl<<"[print_first]"<<endl;
    print_first(n);
    cout<<endl<<"[print_last]"<<endl;
    print_last(n);
}

int PosComp (int num, int f)
{
    int aux1, aux2;
    if (num < f)
        return PosComp (num, f / 10);

    if (num)
    {
        aux1 = num / f;
        num = num % f;
        f = f / 10;
        aux2 = PosComp (num, f);
        return aux2 * 10 + aux1;
    }
    else
        return num;
}

void main_poscomp (void)
{
    cout<<PosComp(12345,10000);
}

int mystery(int x, int y)
{
    if (x % 2 == 1 || y % 2 == 1)
    {
        return 1;
    }
    else
    {
        return 2 * mystery(x / 2, y / 2);
    }
}

void main_mystery()
{
    int r1, r2;
    r1 = mystery(4, 19);
    cout<<"r1: "<<r1<<endl;
    r2 = mystery(12, 20);
    cout<<"r2: "<<r2<<endl;
}

int get_max(int A[], int size, int max)
{
    if(size == 0)
        return max;
    else
        if (A[size-1] > max)
            return get_max(A, size-1, A[size-1]);
        else
            return get_max(A, size-1, max);
}

void main_get_max()
{
//    int A[] = {2, 4, 7, 1, 6};
    int A[] = {2, 10, 7, 15, -6};
    int max = get_max(A, 5, INT_MIN);
    cout<<"max: "<<max<<endl;
}

int main(void)
{
//    main_fact();
//    main_fib();
//    main_print();
//    main_poscomp();
//    main_mystery();
    main_get_max();
    return 0;
}
