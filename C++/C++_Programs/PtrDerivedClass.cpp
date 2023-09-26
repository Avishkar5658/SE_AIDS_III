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
    Derive d;
    Base *ptr;
    ptr=&d;
    ptr->x=10;
    ptr->show();

    static_cast<Derive*>(ptr)->y=20;
    static_cast<Derive*>(ptr)->display();

}