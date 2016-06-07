#include <iostream>
using namespace std;

class Rectangle
{
    int length,width;
public:
    Rectangle(int l=0,int w=0):length(l),width(w){}
    Rectangle(Rectangle &obj){ length=obj.length; width=obj.width; }
    friend void print(Rectangle obj);

    //set functions
    Rectangle &setLength(int);
    Rectangle &setWidth(int);

    //basic functions
    int area(){return length*width;}
    int perimeter(){return 2*(length+width);}

    //overloaded input-output
    friend ostream &operator<<(ostream &output,const Rectangle &obj)
    {
        output<<obj.length<<" x "<<obj.width;
        return output;
    }

    friend istream &operator>>(istream &input,Rectangle &obj)
    {
        input>>obj.length>>obj.width;
        return input;
    }
};

inline Rectangle& Rectangle::setLength(int l)
{
    length=l;
    return *this;
}

inline Rectangle& Rectangle::setWidth(int w)
{
    width=w;
    return *this;
}

//friend function
void print(Rectangle obj)
{
    cout<<obj.length<<" x "<<obj.width<<endl;
}

int main()
{
    Rectangle R(10,100);
    Square S(10);
    S.setLength(11).setWidth(12);
    print(S);
    return 0;
}
