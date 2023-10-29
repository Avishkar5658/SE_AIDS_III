//Structure example

#include<iostream>
using namespace std;

struct as                   //Initilization of structure it also used to create group of multiple data types.
{
    int a=10;
    float b=10.20;
};
int main()
{
    struct as c;            //Create struct obj
    cout<<c.a<<endl;
    cout<<c.b;
}


