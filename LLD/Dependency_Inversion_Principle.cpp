#include<bits/stdc++.h>
using namespace std;

class Player{
    public:
    
    void InteractWith(InterfaceWrapper* obj){
        if(obj){
            obj->func();
        }
    }
};

class InterfaceWrapper{
    public:
    virtual ~InterfaceWrapper()=default;  //Destructor
    virtual void func()=0;
};


class Door:public InterfaceWrapper{
    bool doorOpen=false;
    public:
    void func() override {
        doorOpen=!doorOpen;
        if(doorOpen){
            cout<<"Door is Open"<<endl;
        }else{
            cout<<"Door is closed"<<endl;
        }
    }
};


int main(){
   Player *p=new Player();

   p->InteractWith();
return 0;
}