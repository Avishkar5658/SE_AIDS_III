//Basic to User Defined Datatypes
//To cenvert F to C Degree

#include<iostream>
using namespace std;

class Cel   //Error
{
    float temp;
    public:
    void cel()
    {
        temp=0;
    }
    void cel(float ftemp)
    {
        temp=(ftemp-32)*5/9;
    }
    void show()
    {
        cout<<"Temp in C= "<<temp;
    }
};
int main()
{
    Cel c;
    float ftemp;
    cout<<"Enter temp in F= ";
    cin>>ftemp;
    c=ftemp;
    c.show();
    return 0;
}