//
// Created by NilsMurrugarra-Llerena on 1/2/23.
//

#include<iostream>
#include<string>
#include<memory>
using namespace std;

class Message
{
    private:
        string msg;

    public:
        Message(string msg): msg(msg) {}
        void show(){ cout<<msg<<endl; }
        void set_message(string msg){this->msg = msg;}
        unique_ptr<Message> deep_copy()
        {
            auto dc = make_unique<Message>(msg);
            return dc;
        }
};