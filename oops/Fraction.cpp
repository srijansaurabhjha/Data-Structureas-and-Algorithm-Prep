#include <bits/stdc++.h>
using namespace std;

class Fraction
{
    int n;
    int d;

public:
    Fraction(int n, int d)
    {
        this->n = n;
        this->d = d;
    }

    void simplify()
    {
        int gcd = 1;

        int small = min(n, d);

        for (int i=1;i<=small;i++){
            if(n%i==0&&d%i==0){
                gcd=i;
            }
        }

        n = n / gcd;
        d = d / gcd;
    }

    //Overloading + operator
    Fraction operator+(Fraction const &F2) const{
       
       int lcm=(d)*(F2.d);

       int num=(n*(F2.d))+((F2.n)*d); 

       int den=lcm;

       Fraction fNew(num,den);

       fNew.simplify();

       return fNew;
    }

    // Overloading * operator
    Fraction operator*(Fraction const &F2) const{
        int num=n*(F2.n);
        int den=d*(F2.d);

        Fraction fNew(num,den);
        fNew.simplify();
        return fNew;
    }

    //Overloading == operator
    bool operator==(Fraction const &F2) const{
        return (n==(F2.n))&&(d==(F2.d));
    }

    
    //pre increment operator
    Fraction& operator++(){
        n=n+d;

        simplify();

        return *this;
    }

    //Post increment operator
    Fraction operator++(int){
        Fraction fold(n,d);
        n=n+d;
        simplify();
        fold.simplify();

        return fold;
    }

    //overloading +=operator
    Fraction& operator+=(Fraction const &F2){
          
        int lcm=d*(F2.d);

        n=(n*(F2.d))+((F2.n)*d);
        d=lcm;
        simplify();

        return *this;
    }

    void display(){
        cout<<n<<"/"<<d<<endl;
    }
};

int main()
{
    Fraction F1(10,2),F2(15,4);

    Fraction F4=F1+F2;  //F1 is received in this pointer and F2 as a argument

    F4.display();

    Fraction F5=F1 * F2;

    F5.display();

    Fraction F6(10,2);

    cout<<(F1==F6)<<endl;

    Fraction F7=++(++F1);

    F1.display();
    F7.display();

    Fraction F8=F1++;

    F1.display();
    F8.display();

    Fraction F9(10,3),F10(5,2);

    (F9+=F10)+=F10;

    F9.display();
    F10.display();

    return 0;
}