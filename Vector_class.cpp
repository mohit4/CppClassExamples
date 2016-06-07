#include <iostream>
#include <cmath>
using namespace std;

class Point
{
    int X,Y,Z;
public:
    Point(int x=0,int y=0,int z=0):X(x),Y(y),Z(z){}
    friend void print(Point);

    //set functions modified for function chaining
    Point &setX(int);
    Point &setY(int);
    Point &setZ(int);

    //get functions
    int getX(){return X;}
    int getY(){return Y;}
    int getZ(){return Z;}

    //input and output operator overloading
    friend istream &operator>>(istream &input,Point &obj)
    {
        input>>obj.X>>obj.Y>>obj.Z;
        return input;
    }
    friend ostream &operator<<(ostream &output,Point &obj)
    {
        output<<obj.X<<","<<obj.Y<<","<<obj.Z;
        return output;
    }
};

//---------------

inline Point& Point::setX(int x){ X=x; return *this; }
inline Point& Point::setY(int y){ Y=y; return *this; }
inline Point& Point::setZ(int z){ Z=z; return *this; }

//---------------

void print(Point obj)
{
    cout<<"( "<<obj.X<<" , "<<obj.Y<<" , "<<obj.Z<<" )"<<endl;
}

class Vector
{
    Point P1,P2;
public:

    //constructors overloaded
    Vector(){Point t(0,0,0); P1=P2=t;}
    Vector(Point a):P1(a){Point t(0,0,0);P2=t;}
    Vector(Point a,Point b):P1(a),P2(b){}

    //friend function to print a vector
    friend void print(Vector);

    //output operator overloading
    friend ostream &operator<<(ostream &output,Vector &obj)
    {
        int a,b,c;

        a=obj.P2.getX() - obj.P1.getX();
        b=obj.P2.getY() - obj.P1.getY();
        c=obj.P2.getZ() - obj.P1.getZ();

        output<<a<<"i + "<<b<<"j + "<<c<<"k";
        return output;
    }

    double magnitude()
    {
        int a,b,c;

        a=P2.getX() - P1.getX();
        b=P2.getY() - P1.getY();
        c=P2.getZ() - P1.getZ();

        return sqrt( pow(a,2) + pow(b,2) + pow(c,2) );
    }
};

void print(Vector obj)
{
    int x1,y1,z1;
    int x2,y2,z2;

    x1 = obj.P1.getX();
    y1 = obj.P1.getY();
    z1 = obj.P1.getZ();

    x2 = obj.P2.getX();
    y2 = obj.P2.getY();
    z2 = obj.P2.getZ();

    cout<<"("<<x2<<"-"<<x1<<")i+("<<y2<<"-"<<y1<<")j+("<<z2<<"-"<<z1<<")k";
}

int main()
{
    Point a(2,3,4),b(5,6,7);
    Vector v(a,b);
    cout<<"The vector is : "<<v<<endl;
    cout<<"And Magnitude is : "<<v.magnitude()<<endl;
    return 0;
}
