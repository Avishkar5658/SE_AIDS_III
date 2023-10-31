#include<iostream>
using namespace std;

class Poly
{
    public:
        int w, h;

    void setval(int a, int b)
    {
        w=a;
        h=b;
    }
    virtual int area(void);
};
class Triangle: public Poly
{
    public:
        int area()
        {
            return(0.5*w*h);
        }
};
class Rectangle: public Poly
{
    public:
        int area()
        {
            return(w*h);
        }
};
int main()
{
    Poly *p1, *p2;
    
    Triangle t;
    Rectangle r;

    p1=&t;
    p2=&r;

    p1->setval(4,5);
    p2->setval(4,5);

    cout<<p1->area();
    cout<<p2->area();

    return 0;
}
