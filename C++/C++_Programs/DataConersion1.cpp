//User Defined to Basic Datatypes

#include<iostream>
using namespace std;

class Cel   
{
    float temp;
    public:
    float ftemp, fget;
    void cel()
    {
        temp=0;
    }
    operator float()
    {
        fget=ftemp;
        ftemp=temp*9/5+32;
        return(ftemp);
    }   
    void gettemp()
    {
        cout<<"Enter temp in C= ";
        cin>>temp;
    }
};
int main()
{
    Cel c;
    c.gettemp();
    float f;
    f=c;
    cout<<"Temp in F= "<<f;
    return 0;
}