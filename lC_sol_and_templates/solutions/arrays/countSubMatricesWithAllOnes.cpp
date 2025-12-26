#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    int solve(int startRow, int endRow, int m, vector<vector<int>>& mat){
        vector<int>v(m, 1);
        for(int i = 0; i < m; i++){
            for(int j = startRow; j <= endRow; j++){
                v[i] = v[i] & mat[j][i];
            }
        }
        int consecutive = 0, ans = 0;
        for(int i = 0; i < m; i++){
            if(v[i] == 1){
                consecutive++;
                ans += consecutive;
            }else{
                consecutive = 0;
            }
        }
        return ans;
    }
public:
    int numSubmat(vector<vector<int>>& mat) {
        int res = 0, n = mat.size(), m = mat[0].size();
        for(int endRow = 0; endRow < n; endRow++){
            for(int startRow = 0; startRow <= endRow; startRow++){
                res += solve(startRow, endRow, m, mat);
            }
        }
        return res;
    }
};
