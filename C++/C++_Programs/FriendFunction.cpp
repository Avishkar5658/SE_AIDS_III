//Friend Function 

#include<iostream>
using namespace std;

class Frd
{
    int a;

    public:
    Frd()
    {
        a=10;
    }
    friend int display(Frd);
};
int display(Frd f)
{
    return f;
}