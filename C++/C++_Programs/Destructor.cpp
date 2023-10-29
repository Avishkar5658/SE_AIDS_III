//Distructor Example

#include<iostream>
using namespace std;

class A
{
    public:

    A()                                 
    {
        cout<<"Its a constructor "<<endl;
    }
    ~A()                                    //Distructor are used to destroy the object.
    {
        cout<<"Its a distructor ";
    }
};
int main()
{
    A a;
    return 0;
}