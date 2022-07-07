#include<bits/stdc++.h>
using namespace std;

class Student
{
    public:
    int rollno;
    char* name;

    void display(){
        cout<<rollno<<" "<<name<<endl;
    }
};

int main()
{
    Student A;
    Student B;
    
    // setting values for A object
    A.rollno=1;
    // cout<<"Enter name of A: ";
    // getline(cin,A.name);
    char temp[]="Srijan";
    A.name=temp;
    
    cout<<A.name<<endl;


     
    // setting values for B object
    B.name=temp;

    cout<<B.name<<endl;

    temp[0]='x';

    cout<<A.name<<endl;
    cout<<B.name<<endl;


    // cout<<"Enter name of A: ";
    // getline(cin,B.name);
}
