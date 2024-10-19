#include<iostream>
#include<limits.h>
using namespace std;

void maxProfit(int prices[],int n)
{
    int bestBuy[100000];
    bestBuy[0]=INT_MAX; //min value for buying - min C.P.
    for(int i=1;i<n;i++)
    {
        bestBuy[i]=min(bestBuy[i-1],prices[i-1]); //shortcut to calc. min of all prev elements of array
    }
    int maxProfit=0;
    for(int i=0;i<n;i++)
    {
        int currProfit=prices[i]-bestBuy[i]; //profit=S.P - C.P
        maxProfit=max(currProfit,maxProfit);
    }
    cout<<"\nMaximum Profit:"<<maxProfit;
}
int main()
{
    int prices[]={7,1,5,3,6,4};
    int n=sizeof(prices)/sizeof(int);
    maxProfit(prices,n);
    return 0;
}