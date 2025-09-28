#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool isSafe(int row, int col, char val,vector<vector<char>>& board){
        //all col check
        for(int j = 0; j < 9; j++){
            if(board[row][j] == val){
                return false;
            }
        }
        //all row check
        for(int i = 0; i < 9; i++){
            if(board[i][col] == val){
                return false;
            }
        }
        //grid check
        int rowStart = row - (row % 3);
        int colStart = col - (col % 3);
        for(int i = rowStart; i < rowStart + 3; i++){
            for(int j = colStart; j < colStart + 3; j++){
                if(board[i][j] == val){
                    return false;
                }
            }
        }
        return true;
    }
    bool f(int row, int col, vector<vector<char>>& board) {
        if (row == 9) return true;
        if (col == 9) return f(row + 1, 0, board);;
        if (board[row][col] != '.') return f(row, col + 1, board);

        for (int k = 1; k <= 9; k++) {
            if (isSafe(row, col, k + '0', board)) {
                board[row][col] = k + '0';
                if(f(row, col + 1, board)) return true;
                board[row][col] = '.';
            }
        }
        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        f(0, 0, board);
    }
};