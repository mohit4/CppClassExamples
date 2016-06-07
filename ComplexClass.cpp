#include <iostream>
#include <cmath>
using namespace std;

class Complex
{
    int real,img;
public:
    Complex(int r=0,int i=0):real(r),img(i){}
    friend void polarPrint(Complex obj);

    double modulus()
    {
        return sqrt( pow(real,2) + pow(img,2) );
    }

    double argument()
    {
        double res = atan2(img,real)*180/(3.14159265)  ;
        return res;
    }

    Complex conjugate()
    {
        Complex res(real,-1*img);
        return res;
    }

    //input-output overloading
    friend istream &operator>>(istream &input,Complex &obj)
    {
        input>>obj.real>>obj.img;
        return input;
    }
    friend ostream &operator<<(ostream &output,Complex &obj)
    {
        output<<obj.real;
        if(obj.img<0)
            cout<<"-i";
        else
            cout<<"+i";
        cout<<abs(obj.img);
    }

    Complex operator+(Complex &obj)
    {
        Complex result;
        result.real = real + obj.real;
        result.img = img + obj.img;
        return result;
    }

    Complex operator-(Complex &obj)
    {
        Complex res;
        res.real = real - obj.real;
        res.img = img - obj.img;
        return res;
    }

    Complex operator*(Complex &obj)
    {
        Complex res;
        res.real = (real*obj.real - img*obj.img);
        res.img = (img*obj.real + real*obj.img);
        return res;
    }

    Complex operator/(Complex &obj)
    {
        double a,b,c,d;
        a=real;
        b=img;
        c=obj.real;
        d=obj.img;
        double k = 1/(pow(c,2)+pow(d,2));
        Complex res(k*(a*c+b*d),k*(b*c-a*d));
        return res;
    }
};

void polarPrint(Complex obj)
{
    //print the no in polar form
    double arg = obj.argument();
    cout<<obj.modulus()<<"( cos("<<arg<<") + sin("<<arg<<") )"<<endl;
}

int main()
{
    Complex A(3,4),B(5,12);
    Complex C;
    cout<<"Polar form of "<<A<<" is ";
    polarPrint(A);
    cout<<"Polar form of "<<B<<" is ";
    polarPrint(B);
    cout<<"\nAbout    : "<<A<<endl;
    cout<<"Modulus  : "<<A.modulus()<<endl;
    cout<<"Argument : "<<A.argument()<<endl;
    cout<<"Conjugate: ";
    C=A.conjugate();
    cout<<C<<endl;
    cout<<"\nAbout    : "<<B<<endl;
    cout<<"Modulus  : "<<B.modulus()<<endl;
    cout<<"Argument : "<<B.argument()<<endl;
    cout<<"Conjugate: ";
    C=B.conjugate();
    cout<<C<<endl;
    return 0;
}
