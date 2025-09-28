#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//backtracking approach
class Solution1 {
public:
    vector<vector<int>>res;
    void f(int i, vector<int>& nums, vector<int>& temp) {
        if (i == nums.size()) {
            res.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        f(i + 1, nums, temp);
        temp.pop_back();
        f(i + 1, nums, temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp = {};
        f(0, nums, temp);
        return res;
    }
};
//iterative approach
class Solution2 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>res;
        res.push_back({});
        for(int i = 0; i < n; i++){
            int currSize = res.size();
            int val = nums[i];
            for(int j = 0; j < currSize; j++){
                vector<int>temp = res[j];
                temp.push_back(val);
                res.push_back(temp);
            }
        }
        return res;
    }
};
//using bit manipulation
//🔥Wowwwwwwwwwwwwwwwwwww........
class Solution3 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        int n = nums.size();
        int possibleSubsets = 1 << n;
        for(int i = 0; i < possibleSubsets; i++){
            vector<int>temp = {};
            int idx = 0;
            for(int idx = 0; idx < n; idx++){
                if((i >> idx) & 1){
                    temp.push_back(nums[idx]);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};