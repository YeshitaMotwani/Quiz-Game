#include<iostream>
#include<vector>
#include<string>
using namespace std;
void solveMazeUtil(int maze[][4],int x,int y,string ans,int n,vector<vector<bool>> &vis)
{
    if(x==n-1 && y==n-1 && maze[x][y]==1)
    {
            cout<<ans<<"\n";
            return;
    }
    //Up
    if(x-1>=0 && !vis[x-1][y] && maze[x-1][y]==1) 
    {
        vis[x][y]=true;
        solveMazeUtil(maze,x-1,y,ans+"U",n,vis);
        vis[x][y]=false;
    }
    //down
    if(x+1<n && !vis[x+1][y] && maze[x+1][y]==1)
    {
        vis[x][y]=true;
        solveMazeUtil(maze,x+1,y,ans+"D",n,vis);
        vis[x][y]=false;
    }
    //right
    if(y+1<n && !vis[x][y+1] && maze[x][y+1]==1)
    {
        vis[x][y]=true;
        solveMazeUtil(maze,x,y+1,ans+"R",n,vis);
        vis[x][y]=false;
    }
    //left
    if(y-1>=0 && !vis[x][y-1] && maze[x][y-1]==1)
    {
        vis[x][y]=true;
        solveMazeUtil(maze,x,y-1,ans+"L",n,vis);
        vis[x][y]=false;
    }

}
void solveMaze(int maze[][4],int n)
{
    string ans="";
    vector<vector<bool>> vis(n,vector<bool>(n,false));
    if(maze[0][0]==1) //only move when initial position is 1
        solveMazeUtil(maze,0,0,ans,n,vis);
}
int main()
{
   int maze[][4]={{1,0,0,0},
                {1,1,0,1},
                {1,1,0,0},
                {0,1,1,1}};
    int n=4;
    solveMaze(maze,n);
    return 0;
}