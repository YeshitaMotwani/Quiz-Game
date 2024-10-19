#include <iostream>
using namespace std;

pair<int, int> search_key(int matrix[][3], int rows, int cols, int key) {
  // Loop through each element of the matrix
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (matrix[i][j] == key) {
        // Key found, return the row and column
        return make_pair(i, j);
      }
    }
  }

  // Key not found, return (-1, -1)
  return make_pair(-1, -1);
}

int main() {
  int matrix[][3] = {
    // Sample sorted matrix (replace with your data)
    {1, 4, 7},
    {2, 5, 8},
    {3, 6, 9}
  };
  int rows = 3;
  int cols = 3;
  int key;
  cout<<"\nEnter key to be searched:";
  cin>>key;

  pair<int, int> result = search_key(matrix, rows, cols, key);

  if (result.first == -1) {
    cout << "Key not found in the matrix." << endl;
  } else {
    cout << "Key found at (" << result.first << ", " << result.second << ")" << endl;
  }

  return 0;
}
