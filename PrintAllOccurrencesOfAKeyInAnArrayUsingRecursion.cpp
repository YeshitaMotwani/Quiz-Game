#include<iostream>
#include<vector>
using namespace std;

void printOccur(int arr[],int n,int i,int key)
{
    if(i==n)
    return;
    if(arr[i]==key)
    {
        cout<<i<<" ";
    }
    printOccur(arr,n,i+1,key);
}
int main()
{
    int arr[]={3,2,4,5,6,2,7,2,2};
    printOccur(arr,9,0,2);
    return 0;
}