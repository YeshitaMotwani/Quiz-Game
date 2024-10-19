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
    void dfsHelper(int st,vector<bool> &vis){
        cout<<st<<" ";
        vis[st]=true;
        list<int> neighbours=l[st];
        for(int v:neighbours){
            if(!vis[v]){
                dfsHelper(v,vis);
            }
        }
    }
    void dfs(){
       vector<bool> vis(V,false);
       for(int i=0;i<V;i++){
            if(!vis[i])
            {
                dfsHelper(i,vis);
                cout<<endl;
            }
            cout<<endl;
        }
    }
    
};
int main(){
    Graph graph(10);
    //Undirected
    graph.addEdge(1,6);
    graph.addEdge(1,4);
    graph.addEdge(4,9);
    graph.addEdge(4,3);
    graph.addEdge(3,7);
    graph.addEdge(3,8);
    graph.addEdge(2,5);
    graph.addEdge(2,0);
    //graph.print();
    graph.dfs();
    return 0;
}