#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<vector<int>>dp;
    int f(int i, int prev, vector<int>& nums1, unordered_map<int, vector<int>>&mp){
        if(i == nums1.size()){
            return 0;
        }
        if(dp[i][prev + 1] != -1) return dp[i][prev + 1];
        int val = nums1[i];
        vector<int>& curr = mp[val];
        int not_pick = f(i + 1, prev, nums1, mp);
        int pick = 0;
        for(int& idx : curr){
            if(idx > prev){
                pick = max(pick, 1 + f(i + 1, idx, nums1, mp));
            }
        }
        return dp[i][prev + 1] =  max(pick, not_pick);
    }
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        dp.resize(n, vector<int>(m + 1, -1));
        unordered_map<int, vector<int>>mp;
        for(int i = 0; i < nums2.size(); i++){
            mp[nums2[i]].push_back(i);
        }
        return f(0, -1, nums1, mp);
    }
};