#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Edge {
public:
    int v, wt;
    Edge(int v, int wt) {
        this->v = v;
        this->wt = wt;
    }
};

class Graph {
    int V;
    vector<vector<Edge>> l;

public:
    Graph(int V) {
        this->V = V;
        l.resize(V);
    }

    void addEdge(int u, int v, int wt) {
        l[u].push_back(Edge(v, wt));
        l[v].push_back(Edge(u, wt));  // For undirected graph
    }

    void primsAlgo(int src) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        vector<bool> mst(V, false);
        vector<Edge> edgesInMST;
        int ans = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            int wt = pq.top().first;
            pq.pop();

            if (!mst[u]) {
                mst[u] = true;
                ans += wt;
                
                // Add the edge to the MST if it's not the starting node
                if (wt != 0) {
                    edgesInMST.push_back(Edge(u, wt));
                }

                for (auto neighbor : l[u]) {
                    int v = neighbor.v;
                    int currWt = neighbor.wt;
                    if (!mst[v]) {
                        pq.push({currWt, v});
                    }
                }
            }
        }

        cout << "\nFinal cost of MST: " << ans << endl;
        cout << "Edges in the MST:\n";
        for (auto edge : edgesInMST) {
            cout << edge.v << " - " << edge.wt << endl;
        }
    }
};

int main() {
    int V = 4;
    Graph g(V);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 3, 30);
    g.addEdge(0, 2, 15);
    g.addEdge(1, 3, 40);
    g.addEdge(2, 3, 50);

    g.primsAlgo(0);

    return 0;
}