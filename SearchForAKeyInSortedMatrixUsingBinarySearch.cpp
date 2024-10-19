#include <iostream>

using namespace std;

pair<int, int> search_key(int matrix[][3], int rows, int cols, int key) {
  // Loop through each row
  for (int i = 0; i < rows; i++) {
    // Perform binary search on the current row
    int left = 0, right = cols - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (matrix[i][mid] == key) {
        return make_pair(i, mid); // Key found, return row and column
      } else if (matrix[i][mid] < key) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
  }

  // Key not found
  return make_pair(-1, -1);
}

int main() {
  int matrix[][3L] = {
    // Sample sorted matrix
    {1, 4, 7},
    {2, 5, 8},
    {3, 6, 9}
  };
  int rows = 3;
  int cols = 3;
  int key;
  cout<<"\nEnter the key to be searched:";
  cin>>key;

  pair<int, int> result = search_key(matrix, rows, cols, key);

  if (result.first == -1) {
    cout << "Key not found in the matrix." << endl;
  } else {
    cout << "Key found at (" << result.first << ", " << result.second << ")" << endl;
  }

  return 0;
}
