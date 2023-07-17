#include<iostream>
using namespace std;

class Printer{
    public:
    virtual void print()=0;
    virtual void scan()=0;
    virtual void fax()=0;
};

class InkJetPrinter:public Printer{
    public:
    void print(){
        cout<<"InkJet Printer Printing"<<endl;
    }

    void scan(){
        cout<<"InkJet Printer Scanning"<<endl;
    }

    void fax(){
        cout<<"InkJet Printer Faxing"<<endl;
    }
};


class LaserPrinter:public Printer{
    public:
    void print(){
        cout<<"Laser Printer Printing"<<endl;
    }

    void scan() override {
        cout<<"Laser Printer Scanning"<<endl;
    }

    void fax(){
        throw runtime_error("InkJet Printer Can't Fax");
    }
};


int main(){
//    Printer* p=new InkJetPrinter();
//    p->scan();

   Printer* p=new LaserPrinter();
   p->print();
   p->scan();
return 0;
}