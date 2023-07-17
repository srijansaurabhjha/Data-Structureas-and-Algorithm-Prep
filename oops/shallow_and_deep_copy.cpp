#include<iostream>
#include<string.h>
using namespace std;

class Student{
    int age;
    char* name;
    public:
    Student(int age,char* name){
        //shallow copy
        // this->age=age;
        // this->name=name; 

        //Deep copy
        this->age=age;
        this->name=new char[strlen(name)+1];
        strcpy(this->name,name);
    }

    //Making our own copy constructor
    Student(Student const &s){
        //Making a deep copy
        this->age=s.age;
        this->name=new char[strlen(s.name)+1];
        strcpy(this->name,s.name);
    }

    void display(){
        cout<<name<<" "<<age<<endl;
    }
};

int main(){

    char name[]="srijan saurabh jha";
    Student s1(20,name);
    s1.display();
    name[4]='e';
    s1.display();

    Student s2(s1);

    s2.display();
    name[5]='h';
    s2.display();

return 0;
}