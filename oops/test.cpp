#include<bits/stdc++.h>
using namespace std;

class Teacher;

class Student{
    private:
        int id;
        string name;
        string DOB;
    public:

    Student(){

    }
        Student(int id,string name,string DOB){
            this->id=id;
            this->name=name;
        }
};


int main(){
    Student s1(468,"VVSD","1234");   //parameterised constructor

    Student s2(s1);   // copy contructor  s1 is copied into s2  at time of creation

    Student s3;

    s3=s1;     // copy assignment operator

return 0;
}

//deafult

//parameterised

//copy const.      //shallow copy

// different -> copy assignment operator   //shallow copy

const int rollNumber=10;
// rollNumber=10;


    // emp -> salary ();  //pure virtual function  virtual int salary()=0;
//   hr   tech manage  QA
//   hr   tech manage  QA
// hr-> void salary()  tech manage QA

//    Vehicle
//    Vehicle
   
// Car bike cycle
// Car bike cycle
// Car bike cycle
// Car bike cycle
// Car bike cycle
// Car bike cycle


