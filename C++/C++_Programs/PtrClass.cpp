//Pointer to derived clas

#include<iostream>
class Base
{
    public:
        int x;
        void show()
        {
            cout<<"X= "<<x;
        }
};
class Derive: public Base
{
    public:
        int y;
        void display()
        {
            cout<<"X= "<<x;
            cout<<"Y= "<<y;
        }
};
int main()
{
    Base b;
    Base *ptr;
    ptr=&b;
    ptr->x=10;
    ptr->show();

    Derive d;
    Derive *ptr1;
    ptr1=&d;
    ptr->x=10;
    ptr->y=20;
    ptr->display();

}