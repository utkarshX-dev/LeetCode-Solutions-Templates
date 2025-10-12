#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int>dp(n, -1);
        int ans  = INT_MIN;
        for(int i = n - 1; i >= 0; i--){
            int curr = energy[i];
            if(i + k < n){
                curr += dp[i + k];
            }
            ans = max(ans, curr);
            dp[i] = curr;
        }
        return ans;
    }
};