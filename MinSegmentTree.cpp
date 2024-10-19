#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class SegmentTree {
    int n;
    vector<int> tree;

    void buildTree(vector<int> &nums, int start, int end, int node) {
        if (start == end) {
            tree[node] = nums[start];
            return;
        }
        int mid = start + (end - start) / 2;
        buildTree(nums, start, mid, 2 * node + 1);
        buildTree(nums, mid + 1, end, 2 * node + 2);
        tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
    }

    int minQuery(int qi, int qj, int si, int sj, int node) { // si-start, sj-end
        if (qi > sj || qj < si) { // No overlap
            return INT_MAX;
        }
        if (si >= qi && sj <= qj) { // Complete overlap
            return tree[node];
        }
        // Partial overlap
        int mid = si + (sj - si) / 2;
        int leftMin = minQuery(qi, qj, si, mid, 2 * node + 1);
        int rightMin = minQuery(qi, qj, mid + 1, sj, 2 * node + 2);
        return min(leftMin, rightMin);
    }

    void updateUtil(int idx, int newVal, int start, int end, int node) {
        if (start == end) {
            tree[node] = newVal;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx >= start && idx <= mid) // left
            updateUtil(idx, newVal, start, mid, 2 * node + 1);
        else
            updateUtil(idx, newVal, mid + 1, end, 2 * node + 2);
        tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
    }

public:
    SegmentTree(vector<int> &nums) {
        n = nums.size();
        tree.resize(4 * n);
        buildTree(nums, 0, n - 1, 0);
    }

    int rangeQuery(int qi, int qj) {
        return minQuery(qi, qj, 0, n - 1, 0);
    }

    void updateQuery(int idx, int newVal) {
        updateUtil(idx, newVal, 0, n - 1, 0);
    }

    void printTree() {
        for (int el : tree) {
            cout << el << " ";
        }
        cout << endl;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
    SegmentTree st(nums);
    cout << st.rangeQuery(2, 5) << endl;
    cout << st.rangeQuery(5, 8) << endl;
    st.printTree();
    st.updateQuery(0, 8);
    st.printTree();
    return 0;
}
