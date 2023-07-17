#include<iostream>
using namespace std;

class Vehicle{
    public:
    virtual void print()=0;
};

class Car:public Vehicle{
    public:
    void print(){
        cout<<"This is a 4 wheeler"<<endl;
    }
};
class Bike:public Vehicle{
    public:
    void print(){
        cout<<"This is a 2 wheeler"<<endl;
    }
};

int main(){
    Vehicle* car=new Car();

    car->print(); 

    Vehicle* bike=new Bike();
    bike->print();
    
return 0;
}