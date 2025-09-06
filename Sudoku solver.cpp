#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>> &board, int val) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == val) return false; // row check
        if (board[i][col] == val) return false; // col check
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val) return false; // subgrid check
    }
    return true;
}

bool solve(vector<vector<int>> &board) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == 0) {
                for (int val = 1; val <= 9; val++) {
                    if (isSafe(row, col, board, val)) {
                        board[row][col] = val;
                        if (solve(board)) return true;
                        board[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<int>> board(9, vector<int>(9));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }

    if (solve(board)) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists" << endl;
    }
    return 0;
}
