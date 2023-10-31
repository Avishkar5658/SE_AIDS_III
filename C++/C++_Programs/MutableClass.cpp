#include<iostream>
using namespace std;

class Mut   //Mutable
{
    public:
        mutable int a;
        explicit Mut(int i)
        {
            a=i;
        }
        void add()
        {
            a=a+10;
        }
        int display() const
        {
            return a;
        }
};
int main()
{
    const Mut m(100);
    m.add();
    int c = m.display();
    cout<<"Modifield value of a= "<<c;
    return 0; 
}
