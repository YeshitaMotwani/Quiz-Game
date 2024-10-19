#include<iostream>
#include<limits.h>
using namespace std;

void MaxSumArray(int arr[],int n)
{
    int maxSum=INT_MIN;
    int currSum=0;
    for(int i=0;i<n;i++)
    {
        currSum+=arr[i];
        maxSum=max(maxSum,currSum);
        if(currSum<0) //Negative values always decrease the value of sum. So, no need to add them.
        currSum=0;
    }
    cout<<"\nMaximum sum of subarray:"<<maxSum<<endl;
}
int main()
{
    int n;
    cout<<"\nEnter value of n:";
    cin>>n;
    int arr[n];
    cout<<"\nEnter "<<n<<" elements:";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    MaxSumArray(arr,n);
    return 0;
}