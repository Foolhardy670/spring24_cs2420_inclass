#include<iostream>

using namespace std;

class Task
{
    public:
        Task(){
            cout << "Create Object \n";
        }
        void act(){
            cout << "Doing Something \n";
        }
        ~Task(){
            cout << "Delete Object \n";
        }
};

