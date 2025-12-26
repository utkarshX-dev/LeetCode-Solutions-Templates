#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    void solve(int i, int& target, vector<int>& temp, vector<vector<int>>& res,
               vector<int>& candidates) {
        if (target == 0) {
            res.push_back(temp);
            return;
        }
        if (i == candidates.size()) {
            return;
        }
        if (target >= candidates[i]) {
            target -= candidates[i];
            temp.push_back(candidates[i]);
            solve(i, target, temp, res, candidates);

            temp.pop_back();
            target += candidates[i];
        }
        solve(i + 1, target, temp, res, candidates);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        solve(0, target, temp, res, candidates);
        return res;
    }
};