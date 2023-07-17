#include <iostream>
using namespace std;

class Point
{

    int x, y, z;
    static int totalPoints;

public:
    Point() : x(0), y(0), z(0)
    {
        totalPoints++;
    };

    Point(int x, int y, int z) : x(x), y(y), z(z)
    {
        totalPoints++;
    };

    void display()
    {
        cout << "[" << x << "," << y << "," << z << "]" << endl;
    }

    static int getTotalPoints()
    {
        return totalPoints;
    }

    //Overloading binary Operator
    // p1+p2->  p1->this and p2->argument
    Point operator+(Point const & p2){  
        int newx=x+p2.x;
        int newy=y+p2.y;
        int newz=z+p2.z;
        Point Pnew(newx,newy,newz);
        return Pnew;
    }


    //Overloading Unary Operator

    //1.Pre Increment Operator->nesting is allowed
    Point& operator++(){
        x=x+1;
        y=y+1;
        z=z+1;
        return *this;
    }


    //2.Post Increment Operator->nesting is not allowed
    Point operator++(int){
        x=x+1;
        y=y+1;
        z=z+1;
        Point p(x,y,z);
        
        return p;
    } 
};

int Point::totalPoints = 0;

int main()
{
    Point p1;
    Point p2(4, 5, 8);
    Point p3(9, 5, 3);
    Point p4(4, 8, 4);
    // cout << Point::getTotalPoints() << endl;

    Point p5=p2+p3;

    p5.display();

    // p1.display();
    // p2.display();
    // p3.display();
    // p4.display();

    // p1++;
    // p1.display();
    // Point p5=p1++;
    // p5.display();

    // Point p6=++(++(++p1));
    // p1.display();
    // p6.display();

    // Point p7=p2+p4;
    // p7.display();

    return 0;
}