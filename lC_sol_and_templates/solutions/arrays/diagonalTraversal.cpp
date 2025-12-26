#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int ia = 0, ja = 0, ib = 0, jb = 0;
        bool flip = true;
        vector<int> res;
        while (ja < m && ib < n) {
            if (!flip) {
                int i = ib, j = jb;
                while (i <= ia && j >= ja) {
                    res.push_back(mat[i][j]);
                    i++, j--;
                }
            } else {
                int i = ia, j = ja;
                while (i >= ib && j <= jb) {
                    res.push_back(mat[i][j]);
                    i--, j++;
                }
            }

            if (ia == n - 1) {
                ja++;
            } else {
                ia++;
            }
            if (jb == m - 1) {
                ib++;
            } else {
                jb++;
            }
            flip = !flip;
        }
        return res;
    }
};