#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<vector<int>> dp;

public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        dp.resize(nums.size(), vector<int>(target + 1, 0));
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= target; j++) {
                long long ways = 0;
                for (int idx = 0; idx < n; idx++) {
                    if (j - nums[idx] >= 0) {
                        ways += dp[i][j - nums[idx]];
                    }
                }
                dp[i][j] = ways;
            }
        }
        return dp[0][target];
    }
};