#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int num;
    cout<<"\nEnter a number:";
    cin>>num;

    for(int i=2;i<=num;i++)
    {
        int isPrime=1;
        for(int j=2;j<=sqrt(i);j++)
        {
            if(i%j==0)
            {
                isPrime=0;
            }
        }
        if(isPrime)
        cout<<i<<endl;
    }
    return 0;
}