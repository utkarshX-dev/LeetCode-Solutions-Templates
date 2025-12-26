#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int count = 0; 
        int n = matrix.size(), m = matrix[0].size();
        vector<int> curr(m + 1, 0);
        vector<int> prev(m + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int right = curr[j + 1];
                int diagonal = prev[j + 1];
                int bottom = prev[j];
                if (matrix[i][j] == 1) {
                    int res = 1 + min(right, min(diagonal, bottom));
                    count += res;
                    curr[j] = res;
                } else {
                    curr[j] = 0;
                }
            }
            prev = curr;
        }
        return count;
    }
};