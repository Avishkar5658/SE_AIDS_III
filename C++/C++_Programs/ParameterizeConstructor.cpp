//Parameterize Constructor Example

#include<iostream>
using namespace std;

class A
{
    public:
    int a;
    A(int b)                        //Used Parameter in ()                    
    {
        a=b;
        cout<<"Value of a= "<<a;
    }
};
int main()
{
    A a(10);
    return 0;
}