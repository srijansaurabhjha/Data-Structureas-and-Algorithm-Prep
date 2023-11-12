#include<iostream>
using namespace std;

class A{
    public:
    void t(double x){
        cout<<"A"<<endl;
    }
};
class B: public A{
    public:
    void tt(){
        cout<<"B"<<endl;
    }
};

class C:public A{
    public:
    void t2(int x){
        cout<<"C"<<endl;
    }
};

class D:public B,public C{
    public:
};



int main(){
    D d;
    d.t2(2.3);
return 0;
}


// d->  [
//    B-> [
//          tt()
//         A->[ t()]
//    ]

//    C-> [
//        t()
//        A->[
//          t()
//        ]
//    ]
// ]

//      A
//  B      C
//     D 