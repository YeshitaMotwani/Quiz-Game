#include<iostream>
#include<limits.h>
using namespace std;

void CountSort(int arr[],int n)
{
    int freq[100000];
    int minVal=INT_MAX,maxVal=INT_MIN;
    for(int i=0;i<n;i++)
    {
        minVal=min(minVal,arr[i]);
        maxVal=max(maxVal,arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        freq[arr[i]]++;
    }
    for(int i=minVal,j=0;i<=maxVal;i++)
    {
        while(freq[i]>0)
        {
            arr[j++]=i;
            freq[i]--;
        }
    }
}
void PrintArr(int arr[],int n)
{
    cout<<"\nSorted Array is:\n";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int n;
    cout<<"\nEnter the value of n:";
    cin>>n;
    cout<<"\nEnter "<<n<<" elements:";
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    CountSort(arr,n);
    PrintArr(arr,n);
    return 0;
}