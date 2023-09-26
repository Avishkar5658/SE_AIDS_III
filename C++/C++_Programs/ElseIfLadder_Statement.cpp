//To get percentage and display a grade

#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number between 0 to 100= ";
    cin>>n;

    if(n<0 || n>100)
    {
        cout<<"Wrong number entered !";
    }
    else if(n<50 && n>0)
    {
        cout<<"Fail !";
    }
    else if(n<60 && n>=50)
    {
        cout<<"Got C Grade";
    }
    else if(n<75 && n>=60)
    {
        cout<<"Got B Grade";
    }
    else if(n<=100 && n>=75)
    {
        cout<<"Got A Grade";
    }
    return 0;
}