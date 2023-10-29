//Union examle

#include<iostream>
using namespace std;

union stud                              //user defied data types uses same block of memory for each of list member.
{
    int rollno;
    int mob_no;
};
int main()
{
    union stud s;
    s.rollno = 10;
    s.mob_no = 1234567890;

    cout<<"Roll_no= "<<s.rollno<<endl;
    cout<<"Mob_no= "<<s.mob_no;
    return 0;
}
