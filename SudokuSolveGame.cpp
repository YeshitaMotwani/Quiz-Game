#include<iostream>
using namespace std;
void printSudoku(int sudoku[9][9],int row,int col)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<sudoku[i][j]<<" ";
        }
        cout<<"\n";
    }
}
bool isSafe(int sudoku[9][9],int row,int col,int dig)
{
    //vertical -> col-fixed, row changes
    for(int i=0;i<9;i++)
    {
        if(sudoku[i][col]==dig)
            return false;
    }
    //horizontal -> row-fixed,col changes
    for(int j=0;j<9;j++)
    {
        if(sudoku[row][j]==dig)
            return false;
    }
    //3x3 grid
    int startRow=(row/3)*3;
    int startCol=(col/3)*3;
    for(int i=startRow;i<startRow+3;i++)
    {
        for(int j=startCol;j<startCol+3;j++)
        {
            if(sudoku[i][j]==dig)
                return false;
        }
    }
    return true;
}
bool sudokuSolve(int sudoku[9][9], int row, int col) {
    if (row == 9) { // All rows have been traversed - Base case
        printSudoku(sudoku, 9, 9); // Print the solved Sudoku
        return true;
    }
    int nextRow = row;
    int nextCol = col + 1;
    if (nextCol == 9) {
        nextRow = row + 1; // Move to next row
        nextCol = 0; // Start at the first column of the next row
    }
    if (sudoku[row][col] != 0) { // Digit already exists -> move to next position
        return sudokuSolve(sudoku, nextRow, nextCol); // Next cell call
    }
    for (int dig = 1; dig <= 9; dig++) {
        if (isSafe(sudoku, row, col, dig)) {
            sudoku[row][col] = dig; // Place digit on that cell
            if (sudokuSolve(sudoku, nextRow, nextCol)) { // Call next cell
                return true;
            }
            sudoku[row][col] = 0; // After Backtracking -> false -> 0(empty)
        }
    }
    return false; // No valid digit found for this cell
}

int main()
{
    int sudoku[9][9]={{0,0,8,0,0,0,0,0,0},
                {4,9,0,1,5,7,0,0,2},
                {0,0,3,0,0,4,1,9,0},
                {1,8,5,0,6,0,0,2,0},
                {0,0,0,0,2,0,0,6,0},
                {9,6,0,4,0,5,3,0,0},
                {0,3,0,0,7,2,0,0,4},
                {0,4,9,0,3,0,0,5,7},
                {8,2,7,0,0,9,0,1,3}};
    sudokuSolve(sudoku,0,0);
    return 0;
}