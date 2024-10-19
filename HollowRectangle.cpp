#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"\nEnter value of n:";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cout<<"*"; //First star
        for(int j=1;j<=n-1;j++)
        {
            if(i==1 || i==n)
            cout<<"*";
            else
            cout<<" ";
        }
        cout<<"*"<<endl; //Last star
    }
}