#include<iostream>
using namespace std;

void SubArray(int arr[],int n) //O(n^3)
{
    for(int start=0;start<n;start++)
    {
        for(int end=start;end<n;end++)
        {
            //cout<<"("<<start<<","<<end<<")"<<" ";
            for(int i=start;i<=end;i++)
            {
                cout<<arr[i];
            }
            cout<<",";
        }
        cout<<"\n";
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
    SubArray(arr,n);
    return 0;
}