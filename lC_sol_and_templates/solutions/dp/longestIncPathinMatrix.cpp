#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool isValid(int i, int j, int n, int m){
        return i >= 0 && j >= 0 && i < n && j < m; 
    }
    vector<vector<int>>directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<int>>dp;
    int f(int i, int j, vector<vector<int>>& grid, int n, int m){
        if(dp[i][j] != -1) return dp[i][j];
        int curr = 1;
        for(auto& dir : directions){
            int newi = i + dir[0];
            int newj = j + dir[1];
            if(isValid(newi, newj, n, m) && grid[newi][newj] > grid[i][j]){
                curr = max(curr, 1 + f(newi, newj, grid, n, m));
            }
        }
        return dp[i][j] = curr;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        dp.resize(n, vector<int>(m, -1));
        int res = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                res = max(res, f(i, j, grid, n, m));
            }
        }
        return res;
    }
};