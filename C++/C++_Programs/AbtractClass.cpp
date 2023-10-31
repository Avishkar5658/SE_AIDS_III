#include<iostream>
using namespace std;

class Vehicle
{
    public:
        void show();        //Abstract class in it we can only declare a function
};
class LMV: public Vehicle
{
    public:
        void show()
        {
            cout<<"It`s a LMV class \n";
        }
};
class HMV: public Vehicle
{
    public:
        void show()
        {
            cout<<"It`s a HMV class \n";
        }
};
class TW: public Vehicle
{
    public:
        void show()
        {
            cout<<"It`s a TW class";
        }
};
int main()
{
    Vehicle *v;
    
    LMV l;
    HMV h;
    TW t;

    v=&l;
    v=&h;
    v=&t;

    v->show();
    v->show();
    v->show();
    
    return 0;
}