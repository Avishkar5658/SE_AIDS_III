#include <iostream>  
using namespace std;  

enum Direction                  //Enum are used to defined list of symbolic constant.
{
    East, West, North, South
};  

int main()  
{  
    Direction d=East;
    cout<<d<<endl;
    cout<<South;
    return 0;  
}   