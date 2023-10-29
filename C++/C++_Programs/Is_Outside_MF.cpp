//Outside Member Function

#include<iostream>
using namespace std;

class Outside
{
    public:
        void func()
        {}
};
void Outside::func()
{
    cout<<"Outside member function";
};
int main()
{
    Outside o;
    o.func();
    return 0;
}