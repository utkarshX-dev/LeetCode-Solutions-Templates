#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<vector<int>>dp;
    bool solve(int i, int target, vector<int>& nums){
        if(target == 0) return true;
        if(i == nums.size()) return false;
        if(dp[i][target] != -1) return dp[i][target];
        bool pick = false;
        if(target >= nums[i]){
            pick = solve(i + 1, target - nums[i], nums);
        }
        bool notPick = solve(i + 1, target, nums);
        return dp[i][target] = pick || notPick;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        if(sum % 2 != 0) return false;
        int target = sum/2;
        dp.resize(nums.size(), vector<int>(target + 1, -1));
        return solve(0, target, nums);
    }
};