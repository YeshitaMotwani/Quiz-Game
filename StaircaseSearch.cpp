#include<iostream>
using namespace std;

bool staircaseSearch(int mat[][4],int n,int m,int key)
{
    int i=0,j=m-1;
    while(i<n && j>=0)
    {
        if(mat[i][j]==key)
        {
            cout<<"\nKey found at ("<<i<<","<<j<<")"<<endl;
            return true;
        }
        else if(mat[i][j]>key) //left
        j--;
        else
        i++;
    }
    cout<<"\nKey not found";
    return false;
}
int main()
{
    int mat[3][4]={{1,2,3,4},
                    {5,6,7,8},
                    {9,10,11,12}};
    int key;
    cout<<"\nEnter the key to be searched:";
    cin>>key;
   staircaseSearch(mat,3,4,key);
    return 0;
}