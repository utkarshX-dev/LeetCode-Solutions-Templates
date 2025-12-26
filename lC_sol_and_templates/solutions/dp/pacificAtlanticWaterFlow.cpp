#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited, int n, int m) {
        visited[i][j] = true;
        for (auto& dir : directions) {
            int newi = i + dir[0];
            int newj = j + dir[1];
            if (newi >= 0 and newj >= 0 and newi < n and newj < m && !visited[newi][newj] && grid[newi][newj] >= grid[i][j]) {
                dfs(newi, newj, grid, visited, n, m);
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<bool>> atlantic(n, vector<bool>(m, false));
        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<int>> res;

        for (int j = 0; j < m; j++) {
            dfs(0, j, grid, pacific, n, m);
        }
        for (int j = 0; j < m; j++) {
            dfs(n - 1, j, grid, atlantic, n, m);
        }
        for (int i = 0; i < n; i++) {
            dfs(i, 0, grid, pacific, n, m);
        }
        for (int i = 0; i < n; i++) {
            dfs(i, m - 1, grid, atlantic, n, m);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (atlantic[i][j] && pacific[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};