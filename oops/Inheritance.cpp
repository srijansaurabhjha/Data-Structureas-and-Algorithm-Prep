#include<iostream>
#include<string.h>
using namespace std;

class Person{
    private:
    const int uid;
    protected:
       int age;
    public:
       char*name;

    Person(int uid,int age,char* name):uid(uid){
        this->age=age;
        this->name=new char[strlen(name)+1];
        strcpy(this->name,name);
    }

    void display();
};

void Person::display(){
   cout<<"Person Display is Called"<<endl;
   cout<<uid<<" "<<age<<" "<<name<<endl;
}

class Student:public Person{
    private:
      const int rollNumber;
    public:
      Student(int rollNumber,int uid,int age,char* name):rollNumber(rollNumber),Person(uid,age,name){
          
      }
    
    void display();
};

void Student::display(){
   cout<<"Student Display is Called"<<endl;
    cout<<rollNumber<<" "<<name<<endl;
}

int main(){
    char name[]="Srijan Saurabh Jha";
    Student s1(31,1001,20,name);
    s1.display();
    s1.Person::display();
return 0;
}