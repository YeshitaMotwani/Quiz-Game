#include <iostream>
using namespace std;

void SpiralMatrix(int n, int m) 
{
    char mat[n][m];
    int srow = 0, erow = n - 1;
    int scol = 0, ecol = m - 1;
    char x='X';

    while (srow <= erow && scol <= ecol) 
    {
        // Top
        for (int j = scol; j <= ecol; j++) {
            mat[srow][j]=x;
        }
        // Right
        for (int i = srow + 1; i <= erow; i++) {
            mat[i][ecol]=x;
        }
        // Bottom
        for (int j = ecol - 1; j >= scol; j--) {
            if (srow == erow)
                break;
            mat[erow][j]=x;
        }
        // Left
        for (int i = erow - 1; i >= srow + 1; i--) {
            if (scol == ecol)
                break;
            mat[i][scol]=x;
        }
        srow++;
        scol++;
        erow--;
        ecol--;
         x = (x == 'O')? 'X': 'O';
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<mat[i][j];
        }
        cout<<"\n";
    }
}

int main() {
    SpiralMatrix(6,7);
    return 0;
}
