#include<iostream>
using namespace std;

int main()
{
    int num1=0,num2=1,sum=0;
    int count=0,N;
    cout<<"\nEnter value of N:";
    cin>>N;
    cout<<"\n"<<num1<<","<<num2<<",";
    while(count<=N)
    {
        sum=num1+num2;
        cout<<sum<<",";
        num1=num2;
        num2=sum;
        count++;
    }
    return 0;
}