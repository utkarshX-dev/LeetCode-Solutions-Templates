#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<vector<int>>directions = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
    bool isValid(int n, int m, int i, int j){
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    bool f(int idx, int n, int m, int i, int j, vector<vector<char>>& board, string& word, vector<vector<bool>>& visited){
        if(idx == word.length() - 1) return true;
        visited[i][j] = true;
        for(auto& dir : directions){
            int newi = i + dir[0];
            int newj = j + dir[1];
            if(isValid(n, m, newi, newj) && !visited[newi][newj] && board[newi][newj] == word[idx + 1] && f(idx + 1, n, m, newi, newj, board, word, visited)){
                return true;
            }
        }
        visited[i][j] = false;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == word[0] && f(0, n, m, i, j, board, word, visited)){
                    return true;
                }
            }
        }
        return false;
    }
};