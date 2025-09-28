#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0, res = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        long long currSum = 0;
        for(int i = 0; i < n - 1; i++){
            currSum += nums[i];
            sum -= nums[i];
            if(currSum >= sum){
                res++;
            }
        }
        return res;
    }
};