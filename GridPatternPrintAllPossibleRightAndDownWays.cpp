#include<iostream>
using namespace std;
int ways(int r,int c,int n,int m,string ans)
{
    if(r==n-1 && c==m-1) //reached destination
    {
        cout<<ans<<"\n";
        return 1;
    }
        
    if(r>=n || c>=m)
        return 0;
    int val1=ways(r,c+1,n,m,ans+"R"); //right
    int val2=ways(r+1,c,n,m,ans+"D");//down
    return val1+val2; //total number of ways(right + down)
}
int main()
{
    int n=3,m=3;
    string ans="";
    cout<<"\nWays:"<<ways(0,0,3,3,ans);
    return 0;
}