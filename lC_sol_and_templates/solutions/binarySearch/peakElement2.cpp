#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int i = 0, j = 0;
        int n = mat.size(), m = mat[0].size();
        while(i < n && j < m){
            int curr = mat[i][j];
            if(i - 1 >= 0 && mat[i - 1][j] > curr){
                i = i - 1;
            }
            else if(j - 1 >= 0 && mat[i][j - 1] > curr){
                j = j - 1;
            }else  if(i + 1 < n && mat[i + 1][j] > curr){
                i = i + 1;
            }else  if(j + 1 < m && mat[i][j + 1] > curr){
                j = j + 1;
            }else{
                return {i, j};
            }
        }
        return {i, j};
    }
};