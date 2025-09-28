#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (grid[i][j] == '2') return;
        grid[i][j] = '2';
        for (auto& dir : directions) {
            int newi = i + dir[0];
            int newj = j + dir[1];
            if (newi < grid.size() && newj < grid[0].size() && newi >= 0 &&
                newj >= 0 && grid[newi][newj] == '1') {
                dfs(grid, newi, newj);
            }
        }
    }
    void bfs(vector<vector<char>>& grid, int i, int j) {
        queue<pair<int, int>> q;
        q.push({i, j});
        while (!q.empty()) {
            int curri = q.front().first;
            int currj = q.front().second;
            grid[curri][currj] = '2';
            q.pop();
            for (auto& dir : directions) {
                int newi = curri + dir[0];
                int newj = currj + dir[1];
                if (newi < grid.size() && newj < grid[0].size() && newi >= 0 &&
                    newj >= 0 && grid[newi][newj] == '1') {
                    dfs(grid, newi, newj);
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    cnt++;
                    bfs(grid, i, j);
                }
            }
        }
        return cnt;
    }
};