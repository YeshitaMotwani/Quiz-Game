#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Comparator function to sort activities based on their end times
bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int activitySelection(vector<int> start, vector<int> end, int n) {
    // Create a vector of pairs to store start and end times
    vector<pair<int, int>> activity(n);

    // Populate the activity vector with pairs of start and end times
    for(int i = 0; i < n; i++) {
        activity[i] = make_pair(start[i], end[i]);
    }

    // Sort activities based on their end times
    sort(activity.begin(), activity.end(), compare);

    int currEndTime = activity[0].second;
    int count = 1; // A0 already selected

    // Find non-overlapping activities
    for(int i = 1; i < n; i++) {
        if(activity[i].first > currEndTime) { // Non-overlapping
            count++;
            currEndTime = activity[i].second;
        }
    }

    return count;
}

int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};
    int n = start.size();
    
    cout << "Maximum number of activities: " << activitySelection(start, end, n) << endl;

    return 0;
}
