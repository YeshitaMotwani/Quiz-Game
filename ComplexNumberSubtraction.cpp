#include<iostream>
using namespace std;

class Complex{
    public:
    int real,img;
    Complex(int r,int i)
    {
        real=r;
        img=i;
    }
    void showNum()
    {
        cout<<real<<"+"<<img<<"i"<<endl;
    }
    Complex operator -(Complex &c2)
    {
        int resReal=this->real - c2.real;
        int resImg=this->img - c2.img;
        return Complex(resReal,resImg);
    }
};
int main()
{
    Complex c1(1,2);
    Complex c2(3,4);
    c1.showNum();
    c2.showNum();
    Complex result=c1-c2;
    result.showNum();
    return 0;
}