//TO Display a Even and Odd number

#include<iostream>
using namespace std;

int main()
{
    int num;
    cout<<"Enter the number: ";
    cin>>num;

    if(num%2==0)
    {
        cout<<num<<" is even number ";
    }
    else
    {
        cout<<num<<" is Odd number ";
    }
    return 0;
}