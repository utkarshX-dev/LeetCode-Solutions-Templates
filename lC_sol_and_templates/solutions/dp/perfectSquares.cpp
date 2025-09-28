#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<int> dp;
public:
    int numSquares(int n) {
        dp.resize(n + 1, INT_MAX);
        vector<int> squares;
        for (int i = 1; i <= n; i++) {
            if (i * i <= n) {
                squares.push_back(i * i);
            } else {
                break;
            }
        }
        dp[n] = 0;
        for (int val = n - 1; val >= 0; val--) {
            for (int num : squares) {
                int nextVal = val + num;
                if (nextVal > n) break; 
                int res = dp[nextVal];
                if (res != INT_MAX) {
                    dp[val] = min(dp[val], 1 + res);
                }
            }
        }
        int res = dp[0];
        return res == INT_MAX ? 0 : res;
    }
};