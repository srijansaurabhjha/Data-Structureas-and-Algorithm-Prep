//Function Overriding
#include<iostream>
using namespace std;

class Vehicle{
    public:
    virtual void print(){
        cout<<"NA"<<endl;
    }

    virtual void show(){
        cout<<"This is a vehicle"<<endl;
    }
};

class Car:public Vehicle{
    public:
    //method overriding
    void print(){
       cout<<"Car"<<endl;
    }  

    void show(){
        cout<<"This is a Car"<<endl;
    }
};

int main(){
    Car c;
    // c.print();
    // c.Vehicle::print();

    // cout<<endl;

    //Base Class Pointer can point to derived class object
    // Vehicle *v;
    // Car c2;
    // v=&c2;
    Vehicle* v=new Car;


    //Non-virtual function , binded at compile time
    v->print();   // calls Vehicle class print

    
    //Virtual function, binded at runtime (Runtime Polymorphism)
    v->show();  //calls Car class show

    // v->Car::print ->gives error


return 0;
}

//vehicle
//  |
// Car