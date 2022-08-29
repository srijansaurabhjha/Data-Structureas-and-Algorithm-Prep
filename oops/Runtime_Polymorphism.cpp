#include<iostream>
using namespace std;

class Employee{
    public:
    virtual void designation(){
        cout<<"NOT Defined"<<endl;
    }
};

class HR:public Employee{
    public:
    void designation(){
        cout<<"HR"<<endl;
    }
};

int main(){
//   Employee e1;
//   HR h;
//   e1=h;
//   e1.designation();
    
    // Employee *e2=new HR;
    // e2->designation();

return 0;
}