#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int value, weight;
};

bool compare(pair<double, int> p1, pair<double, int> p2) {
    return p1.first > p2.first; // descending - ratio
}

// Function to get the maximum total value in the knapsack.
double fractionalKnapsack(int w, Item arr[], int n) {
    vector<pair<double, int>> ratio(n, make_pair(0.0, 0)); // pair(ratio, idx) -> (double, int)
    
    for(int i = 0; i < n; i++) {
        double r = arr[i].value / (double) arr[i].weight;
        ratio[i] = make_pair(r, i);
    }
    sort(ratio.begin(), ratio.end(), compare);
    double ans = 0.0;
    for(int i = 0; i < n; i++) {
        int idx = ratio[i].second; 
        if (arr[idx].weight <= w) {
            ans += arr[idx].value;
            w -= arr[idx].weight;
        } else { // last item => partially add
            ans += ratio[i].first * (double)w;
            w = 0; // remaining capacity = 0 as last item has been added partially in the knapsack
            break;
        }
    }
    return ans;
}

int main() {
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(arr) / sizeof(arr[0]);
    int w = 50;
    cout << "Maximum value in Knapsack = " << fractionalKnapsack(w, arr, n);
    return 0;
}
