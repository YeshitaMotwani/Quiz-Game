#include<iostream>
using namespace std;
bool isSafe(int x,int y,int n,int sol[][8])
{
    return (x>=0 && x<n && y>=0 && y<n && sol[x][y]==-1); //valid row and col indices and unvisited pos
}
void printSol(int sol[][8],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<sol[i][j]<<" ";
        }
        cout<<"\n";
    }
}
bool solveKTUtil(int x,int y,int n,int sol[][8],int movei,int xMove[],int yMove[])
{
    int next_x,next_y;
    if(movei==n*n)
        return true;
    else
    {
        for(int i=0;i<8;i++)
        {
            next_x=x+xMove[i];
            next_y=y+yMove[i];
            if(isSafe(next_x,next_y,n,sol))
            {
                sol[next_x][next_y]=movei;
                if(solveKTUtil(next_x,next_y,n,sol,movei+1,xMove,yMove))
                    return true;
                else
                    sol[next_x][next_y]=-1; //backtracking
            }
        }
    }
    return false;
}
bool solveKT(int n)
{
    int sol[8][8];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            sol[i][j]=-1; //Mark all positions as -1(unvisited)
        }

    }
    int xMove[]={2,1,-1,-2,-2,-1,1,2};
    int yMove[]={1,2,2,1,-1,-2,-2,-1};
    sol[0][0]=0; //Starts from 0,0 pos -> visited
    if(!solveKTUtil(0,0,n,sol,1,xMove,yMove))
    {
        cout<<"\nSolution does not exist";
        return false;
    }
    else
    {
        printSol(sol,n);
        return true;
    }
}
int main()
{
    int n=8;
    solveKT(n);
    return 0;
}
