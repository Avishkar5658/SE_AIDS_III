//Constructor Example

#include<iostream>
using namespace std;

class A
{
    public:

    A()                                 //Constructor have same class name as well as function name.
    {
        cout<<"Its a constructor ";
    }
};
int main()
{
    A a;
    return 0;
}