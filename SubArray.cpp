#include<iostream>
using namespace std;

void SubArray(int arr[],int n)
{
    
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
    SubArray(arr,n);
    return 0;
}