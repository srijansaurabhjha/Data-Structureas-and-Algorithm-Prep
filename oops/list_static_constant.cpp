#include<iostream>
#include<string.h>
using namespace std;

class Student{
   int age;
   char* name;
   const int rollNumber; //so that rollNumber cannot be changed later on
   public:
   static int totalStudents;

   Student(int age,int rollNumber,char* name):rollNumber(rollNumber),age(age){
       this->name=new char[strlen(name)+1];
       strcpy(this->name,name);
       totalStudents++;
   }

   void display() const{
      cout<<age<<" "<<rollNumber<<" "<<name<<endl;
   }

   //static functions can only use static data members
   static int getTotalStudents(){
      return totalStudents;
   }

};

//Initialising a static member
int Student::totalStudents=0;

int main(){

   char name[]="srijan saurabh jha";
   Student const s1(20,1002,name);
   s1.display();

   char name2[]="Aayush Jha";
   Student s2(19,1004,name);//Constant functions can also be accessed by simple objects
   s2.display();
   cout<<Student::getTotalStudents()<<endl;

return 0;
}