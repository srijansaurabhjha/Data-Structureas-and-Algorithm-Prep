//Solving Diamond Problem
//   A
//B     C
//   D
#include<iostream>
using namespace std;

class Person{
    int id;
    public:
    string name;
    protected:
    int age;

    public:
    Person(int id,string name,int age){
       this->id=id;
       this->name=name;
       this->age=age;
       cout<<"Person"<<endl;
    }

    void print(){
        cout<<"id:"<<id<<" name:"<<name<<" age:"<<age<<endl;
    }

};

class Student:virtual public Person{
    public:
    Student(int id,string name,int age):Person(id,name,age){
        cout<<"Student"<<endl;
    }
};

class Teacher:virtual public Person{
    public:
    Teacher(int id,string name,int age):Person(id,name,age){
        cout<<"Teacher"<<endl;
    }
};

class TA:public Student,public Teacher{
    public:
    TA(int id,string name,int age):Person(id,name,age),Student(id,name,age),Teacher(id,name,age){
        cout<<"TA"<<endl;
    }
};

int main(){

 TA first(1001,"Srijan",19);

 first.Person::print();

return 0;
}