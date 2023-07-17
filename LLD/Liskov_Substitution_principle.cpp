#include<iostream>
using namespace std;

class Bird{
    public:
    void fly(){
        cout<<"It can Fly"<<endl;
    };
};

class Duck:public Bird{};

class Ostrich:public Bird{
    public:
    void fly(){
        throw runtime_error("It cannot fly");
    }
};

int main(){
    // Bird* bird=new Bird();
    // bird->fly();  //It can fly

    // Duck* d=new Duck();
    // d->fly();// It can fly  //Follows LSP

    Ostrich* o=new Ostrich();
    o->fly();   //It cannot fly // breaks LSP
return 0;
}