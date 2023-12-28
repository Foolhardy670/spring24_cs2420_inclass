//
// Created by NilsMurrugarra-Llerena on 12/28/22.
//
#pragma once
#include <iostream>

using namespace std;

class Time;
ostream& operator<<(ostream& os, const Time& t); // because it is a friend function

class Time
{
    private:
        int hours;
        int minutes;
        int seconds;

    public:
        Time();
        Time(int h, int m, int s);
        Time operator+(const Time t);
        friend ostream& operator<<(ostream& os, const Time& t);
};

Time::Time()
{
    this->hours = 0;
    this->minutes = 0;
    this->seconds = 0;
}

Time::Time(int h, int m, int s)
{
    this->hours = h;
    this->minutes = m;
    this->seconds = s;
}

Time Time::operator+(Time const t)
{
    int s = this->seconds + t.seconds;
    int m = this->minutes + t.minutes;
    int h = this->hours + t.hours;
    Time out_time = Time(h, m, s);
    return out_time;
}

ostream& operator<<(ostream& out, const Time& t)
{
    out  << t.hours << ":" << t.minutes << ":"
         << t.seconds << endl;
    return out;
}

int main(void)
{
    // Init: pointers
    Time t1(0, 30, 45);
    cout << "t1: " << t1 << endl;

    Time t2(0, 55, 25);
    Time t3 = t1 + t2;
    cout << "t3: " <<t3 << endl;

    return 0;
}

