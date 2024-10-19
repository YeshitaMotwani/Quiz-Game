#include<iostream>
using namespace std;

int diagonalSum(int mat[][4],int n,int m)
{
    //O(N^2)
    /*int sum=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==j)
            sum+=mat[i][j];
            else if(j==n-i-1)
            sum+=mat[i][j];
        }
    }
    return sum;*/

    //O(N) - Optimized

    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=mat[i][i]; //pd
        if(i!=n-i-1)
        sum+=mat[i][n-i-1];
    }
    return sum;
}
int main()
{
    int matrix[4][4]={{1,2,3,4},
                      {5,6,7,8},
                      {9,10,11,12},
                      {13,14,15,16}};
    cout<<"\nSum is:"<<diagonalSum(matrix,4,4);
    return 0;
}