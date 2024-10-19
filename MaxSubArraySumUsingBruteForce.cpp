#include<iostream>
#include<limits.h>
using namespace std;

void MaxSumArray(int arr[],int n)
{
    int maxSum=INT_MIN;
    for(int start=0;start<n;start++)
    {
        for(int end=start;end<n;end++)
        {
            int currSum=0;
            for(int i=start;i<=end;i++)
            {
                currSum+=arr[i];
            }
            cout<<currSum<<",";
            maxSum=max(maxSum,currSum);
        }
        cout<<endl;
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