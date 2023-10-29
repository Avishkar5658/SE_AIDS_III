//Inline function Example

#include<iostream>
using namespace std;

inline int add(int a, int b)                            //inline return_type function_name(parameters) {}
{                                                   
    return(a+b);
};
int main()
{
    cout<<"Addition of two number is= "<<add(2,3);
    return 0;
}
