#include<iostream>
using namespace std;

int main()
{
    int num,dig,num2,sum,cube;
    cout<<"\nEnter a number:";
    cin>>num;
    num2=num;

    while(num>=0)
    {
        dig=num%10;
        cube=dig*dig*dig;
        sum+=cube;
        num/=10;
    }
    if(sum==num2)
    cout<<"\nARMSTRONG Number";
    else
    cout<<"\nNOT Armstrong number";
}