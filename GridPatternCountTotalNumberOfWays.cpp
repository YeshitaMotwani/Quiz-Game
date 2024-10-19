#include<iostream>
using namespace std;
int ways(int r,int c,int n,int m)
{
    if(r==n-1 && c==m-1)
        return 1;
    if(r>=n || c>=m)
        return 0;
    int val1=ways(r,c+1,n,m);
    int val2=ways(r+1,c,n,m);
    return val1+val2;
}
int main()
{
    int n=3,m=3;
    cout<<"\nWays:"<<ways(0,0,3,3);
    return 0;
}