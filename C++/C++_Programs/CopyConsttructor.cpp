//Copy Constructor Example

#include<iostream>
using namespace std;

class A
{
    public:
    int a;
    A(int b)                                            
    {
        a=b;
    }
    A(const A &x)                   //Class_name(const class_name &old_object)
    {
        a = x.a;
        cout<<"Copy Constructor value= "<<a;
    }
};
int main()
{
    A a(10);
    A b(a);                         //Copy Constructor
    return 0;
}