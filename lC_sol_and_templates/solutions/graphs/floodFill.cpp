#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<vector<int>>directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    bool isvalid(int n, int m, int i, int j, vector<vector<int>>& image){
        if(i >= n || j >= m || i < 0 || j < 0){
            return false;
        }
        return true;
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(), m = image[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m, 0));
        queue<pair<int, int>>q;
        q.push({sr, sc});
        int clr = image[sr][sc];
        image[sr][sc] = color; 
        while(!q.empty()){
            auto& node = q.front();
            int i = node.first;
            int j = node.second;
            q.pop();
            for(auto& dir : directions){
                int newx = i + dir[0]; 
                int newy = j + dir[1];
                if(isvalid(n, m, newx, newy, image) && !visited[newx][newy] && image[newx][newy] == clr){
                    visited[newx][newy] = true;
                    image[newx][newy] = color;
                    q.push({newx, newy});
                } 
            }
        }
        return image;
    }
};