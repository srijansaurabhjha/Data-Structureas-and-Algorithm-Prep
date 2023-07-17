#include<iostream>
#include<string.h>
using namespace std;

class Person{
    private:
     const int uid;
    protected:
     int age;
    public:
     char* name;
     Person(int uid,int age,char* name):uid(uid){
        this->age=age;
        this->name=new char[strlen(name)+1];
        strcpy(this->name,name);
     }
     
};

class Student:public Person{
    private:
     const int rollNumber;
    public:
    char section;
    Student(int rollNumber,char section,int uid,int age,char* name):rollNumber(rollNumber),Person(uid,age,name){
         this->section=section;
    }
};

class Science:public Student{
    private:
      int marks;
    public:
      Science(int marks,int rollNumber,char section,int uid,int age,char* name):Student(rollNumber,section,uid,age,name){
         (*this).marks=marks;
      }    
};

int main(){

return 0;
}