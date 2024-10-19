#include<iostream>
#include<vector>
using namespace std;

class DisjointSet {
public:
    int n;
    vector<int> par;
    vector<int> rank;

    DisjointSet(int n) {
        this->n = n;
        for (int i = 0; i < n; i++) {
            par.push_back(i); // Each element is a parent of itself
            rank.push_back(0); // Initialize rank of each element with 0
        }
    }

    int find(int x) { // Returns parent of element x
        if (par[x] == x)
            return x;
        return par[x] = find(par[x]); // Path compression (Optimization) => Tree Flat => height reduce
    }

    void unionByRank(int a, int b) {
        // Step 1: Find parA and parB
        int parA = find(a);
        int parB = find(b);
        
        // Step 2: Compare ranks of parA and parB => Greater Rank => New par/leader
            if (rank[parA] == rank[parB]) {
                // parA or parB can be new parent/leader
                // Assume parA as new parent/leader
                par[parB] = parA;
                rank[parA]++; //Update rank of new parent/leader as height of tree increases
            }
            else if (rank[parA] > rank[parB]) {
                // parA becomes new parent/leader
                par[parB] = parA;
            } 
            else {
                // rank[parA] < rank[parB] => parB becomes new parent/leader
                par[parA] = parB;
            }
        }

    void getInfo() {
        for (int i = 0; i < n; i++) {
            cout << i << ": " << par[i] << ", " << rank[i] << endl;
        }
    }
};

int main() {
    DisjointSet dj(6);
    dj.unionByRank(0, 2);
    cout << "Parent of 2: " << dj.find(2) << endl;
    dj.unionByRank(1, 3);
    dj.unionByRank(2, 5);
    dj.unionByRank(0, 3);
    cout << "Parent of 2: " << dj.find(2) << endl;
    dj.unionByRank(0, 4);
    dj.getInfo();
    return 0;
}
