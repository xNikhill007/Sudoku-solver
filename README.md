/**
 * @file sudoku_solver.cpp
 * @brief Implementation of a backtracking algorithm to solve Sudoku puzzles
 * @author Your Name
 * @date 2023
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Checks if placing a value in a specific cell is valid according to Sudoku rules
 * @param row The row index of the cell
 * @param column The column index of the cell
 * @param board The current state of the Sudoku board
 * @param val The value to be checked
 * @return true if the placement is valid, false otherwise
 */
bool issafe(int row, int column, vector<vector<int>> &board, int val) {
    int n = board.size();
    for(int i = 0; i < n; i++) {
        // Row check
        if(board[row][i] == val) {
            return false;
        }
        // Column check
        if(board[i][column] == val) {
            return false; 
        }
        // 3x3 sub-grid check
        if(board[3 * (row / 3) + i / 3][3 * (column / 3) + i % 3] == val) {
            return false;
        }
    }
    return true;
}

/**
 * @brief Recursive function to solve the Sudoku puzzle using backtracking
 * @param board The Sudoku board to be solved
 * @return true if a solution is found, false otherwise
 */
bool solve(vector<vector<int>>& board) {
    int n = board[0].size();
    for(int row = 0; row < n; row++) {
        for(int col = 0; col < n; col++) {
            // Check if cell is empty
            if(board[row][col] == 0) {
                for(int val = 1; val <= 9; val++) {
                    if(issafe(row, col, board, val)) {
                        board[row][col] = val;
                        // Recursive call
                        bool furthersol = solve(board);
                        if(furthersol) {
                            return true;
                        } else {
                            // Backtrack
                            board[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

/**
 * @brief Main function to solve the Sudoku puzzle
 * @param sudoku The Sudoku board to be solved (modified in place)
 */
void solveSudoku(vector<vector<int>>& sudoku) {
    solve(sudoku);
}

/**
 * @brief Helper function to print the Sudoku board
 * @param board The Sudoku board to be printed
 */
void printSudoku(const vector<vector<int>>& board) {
    for (int i = 0; i < board.size(); i++) {
        if (i % 3 == 0 && i != 0) {
            cout << "------+-------+------" << endl;
        }
        for (int j = 0; j < board[0].size(); j++) {
            if (j % 3 == 0 && j != 0) {
                cout << "| ";
            }
            if (board[i][j] == 0) {
                cout << ". ";
            } else {
                cout << board[i][j] << " ";
            }
        }
        cout << endl;
    }
}

/**
 * @brief Example usage of the Sudoku solver
 */
int main() {
    // Example Sudoku board (0 represents empty cells)
    vector<vector<int>> sudoku = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    
    cout << "Original Sudoku:" << endl;
    printSudoku(sudoku);
    cout << endl;
    
    solveSudoku(sudoku);
    
    cout << "Solved Sudoku:" << endl;
    printSudoku(sudoku);
    
    return 0;
}
