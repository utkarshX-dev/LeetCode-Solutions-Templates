#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    int maxi = 0;
    vector<vector<int>> dp;
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        dp.resize(n + 1, vector<int>(m + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int right = dp[i][j + 1];
                int diagonal = dp[i + 1][j + 1];
                int bottom = dp[i + 1][j];
                if (matrix[i][j] == '1') {
                    int res = 1 + min(right, min(diagonal, bottom));
                    maxi = max(maxi, res * res);
                    dp[i][j] = res;
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return maxi;
    }
};