#include<bits/stdc++.h>
using namespace std;

class person{
    public:
       int id;
       int age;
       int name;

    person(){
      cout<<"Default Constructor"<<endl;
    }   

    person(int id){
        this->id=id;
        cout<<id<<endl;
    }
};

class student:public person{
    
    public:
    int rollNumber;
    
    student(int rollNumber,int x):person(x){
       this->rollNumber=rollNumber;
       cout<<rollNumber<<endl;
    }

};

class officer:private person{

};

int main(){

   student s(10,1001);

return 0;
}