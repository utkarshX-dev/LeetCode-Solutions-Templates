#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>>directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        queue<pair<int, int>>q;
        int totalFresh = 0;
        int time = 0, n = grid.size(), m = grid[0].size(); 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({i , j});
                }else if(grid[i][j] == 1){
                    totalFresh++;
                }
            }
        }

        int affected = 0;
        while(!q.empty()){
            int size = q.size();
            bool valid = false;
            for(int i = 0; i < size; i++){
                auto curr = q.front();
                q.pop();
                for(auto& dir : directions){
                    int newi = curr.first + dir[0];
                    int newj = curr.second + dir[1];
                    if(newi < n && newj < m && newi >= 0 && newj >= 0 && grid[newi][newj] == 1){
                        grid[newi][newj] = 2;
                        q.push({newi, newj});
                        valid = true;
                        affected++;
                    }
                }
            }
            if(valid) time++;
        }
        if(affected != totalFresh) return -1;
        else return time;
    }
};