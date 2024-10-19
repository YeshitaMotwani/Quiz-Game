#include<iostream>
#include<vector>
using namespace std;
//Memoization
/*int fib(int n,vector<int> &f){
    if(n==0 || n==1)
        return n;
    if(f[n]!=-1)
        return f[n];
    f[n]=fib(n-1,f)+fib(n-2,f);
    return f[n];
} */
//Tabulation
int fibTab(int n){
    vector<int> fib(n+1,0); //fib[i]=> ith fib
    fib[0]=0;
    fib[1]=1;
    for(int i=2;i<=n;i++){
        fib[i]=fib[i-1]+fib[i-2];
    }
    return fib[n];
}
int main(){
    int n=6;
    vector<int> f(n+1,-1);
   // cout<<fib(n,f)<<endl;
    cout<<fibTab(n)<<endl;
    return 0;
}