#include<iostream>
using namespace std;

void ReverseArray(int arr[],int n)
{
    int copyArr[n];
    for(int i=0;i<n;i++)
    {
        int j=n-i-1;
        copyArr[i]=arr[j];
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=copyArr[i];
    }
}

void PrintArray(int arr[],int n)
{
    cout<<"\nArray after reversing is:\n";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
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
    ReverseArray(arr,n);
    PrintArray(arr,n);
    return 0;
}

