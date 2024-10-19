#include<iostream>
using namespace std;
bool ways(int r,int c,int n,int m)
{
    if(r==n-1 && c==m-1) //reached destination
    {
        return true;
    }
        
    if(r>=n || c>=m)
        return false;
    bool val1 = ways(r,c+1,n,m); //right
    bool val2 = ways(r+1,c,n,m);//down
    return (val1 || val2);
}
int main()
{
    int n=3,m=3;
    cout<<ways(0,0,3,3)<<"\n";
    return 0;
}