#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph{
    int V;
    list<int>* l;
    public:
    Graph(int V){
        this->V=V;
        l=new list<int> [V];
    }
    void addEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void print(){
        for(int u=0;u<V;u++) //Traverse all edges
        {
            list<int> neighbours=l[u];
            cout<<u<<":";
            for(int v:neighbours){
                cout<<v<<" ";
            }
            cout<<endl;
        }
    }
    //Using DFS
    /*bool hasPathHelper(int src,int dest,vector<bool> &vis){
        if(src==dest)
            return true;
        vis[src]=true;
        list<int> neighbours=l[src];
        for(int v:neighbours){
            if(!vis[v])
            {
                if(hasPathHelper(v,dest,vis))
                    return true;
            }
        }
        return false;
    }*/
   //Using BFS
   bool hasPathHelper(int src, int dest, vector<bool> &vis){
        if(src == dest)
            return true;
        
        queue<int> q;
        q.push(src);
        vis[src] = true;

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int neighbour : l[curr]){
                if(neighbour == dest)
                    return true;
                if(!vis[neighbour]){
                    vis[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
        return false;
    }

    bool hasPath(int src, int dest){
        vector<bool> vis(V, false);
        return hasPathHelper(src, dest, vis);
    }
};
int main(){
    Graph graph(5);
    //Undirected
    graph.addEdge(0,1);
    graph.addEdge(1,2);
    graph.addEdge(1,3);
    graph.addEdge(2,3);
    graph.addEdge(2,4);
    //graph.print();
    cout<<graph.hasPath(1,4);
    return 0;

}