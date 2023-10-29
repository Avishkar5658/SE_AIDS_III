//Inside Member Function

#include<iostream>
using namespace std;

class Inside
{
    public:
        void func()
        {
            cout<<"Inside member function";
        }
};
int main()
{
    Inside i;
    i.func();
    return 0;
}