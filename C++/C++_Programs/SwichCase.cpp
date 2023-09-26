//To check a percentage.

#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number to check Percentage: ";
    cin>>n;

    switch(n)   //used switch case statement
    {
        case 1: cout<<"It`s 10";
            break;

        case 2: cout<<"It`s 20";
            break;

        case 3: cout<<"It`s 30";
            break;

        case 4: cout<<"It`s 40";
            break;

        case 5: cout<<"It`s 50";
            break;

        case 6: cout<<"It`s 60";
            break;

        case 7: cout<<"It`s 70";
            break;

        case 8: cout<<"It`s 80";
            break;

        case 9: cout<<"It`s 90";
            break;

        case 10: cout<<"It`s 100";
            break;

        default: cout<<"Invalid input !";   
            break;
    }
}