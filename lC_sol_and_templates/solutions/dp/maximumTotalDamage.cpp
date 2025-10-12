#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<long long> dp;
public:
    long long maximumTotalDamage(vector<int>& nums) {
        map<int, int> mp;
        dp.resize(nums.size() + 5, 0);
        for (auto& x : nums) {
            mp[x]++;
        }
        vector<long long> temp;
        for (auto& x : mp) {
            temp.push_back(x.first);
        }
        dp[temp.size() - 1] = temp[temp.size() - 1] * mp[temp[temp.size() - 1]];
        for (int idx = temp.size() - 2; idx >= 0; idx--) {
            long long not_pick = dp[idx + 1];
            long long pick = temp[idx] * mp[temp[idx]];
            if (idx + 2 < temp.size() && temp[idx + 1] == temp[idx] + 1 && temp[idx + 2] == temp[idx] + 2) {
                pick += dp[idx + 3];
            } else if (temp[idx + 1] == temp[idx] + 1 || temp[idx + 1] == temp[idx] + 2) {
                pick += dp[idx + 2];
            } else {
                pick += dp[idx + 1];
            }
            dp[idx] = max(pick, not_pick);
        }
        return dp[0];
    }
};