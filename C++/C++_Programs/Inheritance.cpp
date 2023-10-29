//Inheritance Example

#include<iostream>
using namespace std;

class A                                 //create class a 
{
    public:                             //always used access specifier
    void print()                        //member function
    {
        cout<<"Its Class A \n";
    }
};
class B: public A
{
    public:
    void display()
    {
        cout<<"Its Class B";
    }
};
int main()
{
    B b;
    b.print();
    b.display();
    return 0;
}