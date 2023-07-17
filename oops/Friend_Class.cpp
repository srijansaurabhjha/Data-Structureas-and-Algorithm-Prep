#include<iostream>
using namespace std;

class A{
    private:
       int x;
    public:
     A(){
       x=100;
     }
    friend class B;
};

class B{
   private:
     int y;
   public:
     B(){
        y=200;
     }
    int add(A &a){
       int sum=a.x+y;
       return sum;
    }
};

int main(){
    B b;
    A a;
    cout<<b.add(a);
return 0;
}