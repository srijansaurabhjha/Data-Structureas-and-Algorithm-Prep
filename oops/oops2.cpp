#include<iostream>
#include<string.h>
using namespace std;

class Student{

   static int totalStudent;

   public:
   int age;
   const int rollNum;
   char* name;

   Student(int age,int rollNum,char* name):rollNum(rollNum){
      this->age=age;
      this->name=new char[strlen(name)+1];
      strcpy(this->name,name);
      totalStudent++;
   }

   void display(){
      cout<<rollNum<<" "<<age<<" "<<name<<endl;
   }
   
   static int getTotalStudents(){
      return totalStudent;
   }

};

int Student::totalStudent=0;

int main(){
   char name[]="Srijan";
   Student s1(20,1001,name);
   s1.display();

   name[0]='M';
   Student s2(20,1002,name);
   s2.display();
   // s1.display();
   // s1.rollNum=1003; this will throw error

   cout<<Student::getTotalStudents()<<endl;

   return 0;
}