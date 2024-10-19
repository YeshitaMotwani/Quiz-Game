#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph {
    int V;
    list<pair<int, int>> *l;

public:
    Graph(int V) {
        this->V = V;
        l = new list<pair<int, int>>[V];
    }

    void addEdge(int u, int v, int w) {
        l[u].push_back({v, w});
        l[v].push_back({u, w});
    }

    void print() {
        for (int u = 0; u < V; u++) {
            cout << u << ":";
            for (auto it = l[u].begin(); it != l[u].end(); ++it) {
                cout << " {" << it->first << "," << it->second << "},";
            }
            cout << endl;
        }
    }
    void primsAlgo(int src){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; 
        //Min Heap(wt,u)
        pq.push({0,src});
        vector<bool> mst(V,false);
        int ans=0;
        while(!pq.empty()){
            int u=pq.top().second;
            int wt=pq.top().first;
            pq.pop();
            if(!mst[u]){
                mst[u]=true;
                ans+=wt;
                list<pair<int,int>> neighbors=l[u];
                for(pair<int,int> n:neighbors){
                    int v=n.first;
                    int currWt=n.second;
                    pq.push({currWt,v});
                }
            }
        }
        cout<<"\nFinal cost of MST:"<<ans;
    }
    
};

int main() {
    Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 15);
    g.addEdge(0, 3, 30);
    g.addEdge(1, 3, 40);
    g.addEdge(2, 3, 50);

    g.print();

    g.primsAlgo(0);

    return 0;
}
