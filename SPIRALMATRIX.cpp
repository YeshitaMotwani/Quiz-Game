#include <iostream>
using namespace std;

void SpiralMatrix(int mat[][3], int n, int m) {
    int srow = 0, erow = n - 1;
    int scol = 0, ecol = m - 1;

    while (srow <= erow && scol <= ecol) {
        // Top
        for (int j = scol; j <= ecol; j++) {
            cout << mat[srow][j] << " ";
        }
        // Right
        for (int i = srow + 1; i <= erow; i++) {
            cout << mat[i][ecol] << " ";
        }
        // Bottom
        for (int j = ecol - 1; j >= scol; j--) {
            if (srow == erow)
                break;
            cout << mat[erow][j] << " ";
        }
        // Left
        for (int i = erow - 1; i >= srow + 1; i--) {
            if (scol == ecol)
                break;
            cout << mat[i][scol] << " ";
        }
        srow++;
        scol++;
        erow--;
        ecol--;
    }
    cout << "\n";
}

int main() {
    int matrix[][3] = {{7},
                        {9},
                        {6}};
    SpiralMatrix(matrix, 3, 1);
    return 0;
}
