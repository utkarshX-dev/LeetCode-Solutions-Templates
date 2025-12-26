#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<vector<string>> res;
    bool isSafe(int i, int j, int n, vector<string>& board) {
        // rowcheck
        for (int col = 0; col < n; col++) {
            if (col != j && board[i][col] == 'Q') {
                return false;
            }
        }
        // colcheck
        for (int row = 0; row < n; row++) {
            if (row != i && board[row][j] == 'Q') {
                return false;
            }
        }
        // upper left diagonal check
        int x = i - 1, y = j - 1;
        while (x >= 0 && y >= 0) {
            if (board[x][y] == 'Q') {
                return false;
            } else {
                x = x - 1;
                y = y - 1;
            }
        }
        // upper right diagonal check
        x = i - 1, y = j + 1;
        while (x >= 0 && y < n) {
            if (board[x][y] == 'Q') {
                return false;
            } else {
                x = x - 1;
                y = y + 1;
            }
        }
        // lower left digonal
        x = i + 1, y = j - 1;
        while (x < n && y >= 0) {
            if (board[x][y] == 'Q') {
                return false;
            } else {
                x = x + 1;
                y = y - 1;
            }
        }
        // lower right diagonal check
        x = i + 1, y = j + 1;
        while (x < n && y < n) {
            if (board[x][y] == 'Q') {
                return false;
            } else {
                x = x + 1;
                y = y + 1;
            }
        }
        return true;
    }
    void f(int i, int queenCount, int n, vector<string>& board,
           vector<vector<int>>& visited) {
        if (i == n) {
            if (queenCount == n) {
                res.push_back(board);
            }
            return;
        }

        bool possible = false;
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && isSafe(i, j, n, board)) {
                visited[i][j] = 1;
                possible = true;
                board[i][j] = 'Q';
                f(i + 1, queenCount + 1, n, board, visited);
                board[i][j] = '.';
                visited[i][j] = 0;
            }
        }
        if (!possible) {
            return;
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<int>> visited(n, vector<int>(n, 0));
        f(0, 0, n, board, visited);
        return res;
    }
};