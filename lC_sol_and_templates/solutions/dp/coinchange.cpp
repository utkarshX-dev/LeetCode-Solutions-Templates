#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<vector<int>> dp;
    int f(int amount, int i, vector<int>& coins) {
        if (amount == 0)
            return 0;
        if (i == coins.size())
            return 1e9;
        if (dp[i][amount] != -1)
            return dp[i][amount];
        int pick = 1e9;
        if (amount >= coins[i])
            pick = 1 + f(amount - coins[i], i, coins);
        int not_pick = f(amount, i + 1, coins);
        return dp[i][amount] = min(pick, not_pick);
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(coins.size() + 1, vector<int>(amount + 1, 1e9));
        for (int i = 0; i <= coins.size(); i++) dp[i][0] = 0;
        for (int i = coins.size() - 1; i >= 0; i--) {
            for (int j = 0; j <= amount; j++) {
                int pick = 1e9;
                if (j >= coins[i]) pick = 1 + dp[i][j - coins[i]];
                int not_pick = dp[i + 1][j];
                dp[i][j] = min(pick, not_pick);
            }
        }
        return dp[0][amount] >= 1e9 ? -1 : dp[0][amount];
    }
};