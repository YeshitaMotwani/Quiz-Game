#include<iostream>
using namespace std;
int main()
{
    int num;
    do
    {
        cout<<"\nEnter a number:";
        cin>>num;
    }while(num%10!=0);
    cout<<"\nIt's a multiple of 10";
    return 0;
}