#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int>dp;
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> mp;
        dp.resize(nums.size() + 3, 0);
        for (auto& x : nums) {
            mp[x]++;
        }
        vector<int> temp;
        for (auto& x : mp) {
            temp.push_back(x.first);
        }
        dp[temp.size() - 1] = temp[temp.size() - 1] * mp[temp[temp.size() - 1]];
        for (int idx = temp.size() - 2; idx >= 0; idx--) {
            int not_pick = dp[idx + 1];
            int pick = temp[idx] * mp[temp[idx]];
            if (temp[idx + 1] == temp[idx] + 1) {
                pick += dp[idx + 2];
            } else {
                pick += dp[idx + 1];
            }
            dp[idx] = max(pick, not_pick);
        }
        return dp[0];
    }
};