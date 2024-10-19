#include<iostream>
using namespace std;

void ReverseArray(int arr[],int n)
{
    int start=0,end=n-1;
    while(start<end)
    {
        //Swap 1st and last element, swap 2nd and 2nd last element
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
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