#include <iostream>
#include <vector>
#include <string>
using namespace std;

void mergeSort(vector<string>& arr, int low, int high);
void merge(vector<string>& arr, int low, int mid, int high);

void mergeSort(vector<string>& arr, int low, int high) {
    if(low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid); // Sort the first half
        mergeSort(arr, mid + 1, high); // Sort the second half
        merge(arr, low, mid, high); // Merge the sorted halves
    }
}

void merge(vector<string>& arr, int low, int mid, int high) {
    vector<string> left(arr.begin() + low, arr.begin() + mid + 1);
    vector<string> right(arr.begin() + mid + 1, arr.begin() + high + 1);

    int i = 0, j = 0, k = low;
    while(i < left.size() && j < right.size()) {
        if(left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    // Copy the remaining elements of left, if there are any
    while(i < left.size()) {
        arr[k++] = left[i++];
    }

    // Copy the remaining elements of right, if there are any
    while(j < right.size()) {
        arr[k++] = right[j++];
    }
}

int main() {
    vector<string> arr = {"sun", "earth", "mars", "mercury"};
    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for(const string& str : arr) {
        cout << str << " ";
    }
    cout << endl;

    return 0;
}
