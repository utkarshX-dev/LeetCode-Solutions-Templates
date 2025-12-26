#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2; i++){
            while(i > 0 && i < n - 2 && nums[i] == nums[i - 1]){
                i++;
            }
            if(i >= n - 2) return res;
            int j = i + 1;
            int k = n - 1;
            int target = -nums[i];
            while(j < k){
                if(nums[j] + nums[k] == target){
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++, k--;
                    while(j < k &&nums[j] == nums[j - 1]){
                        j++;
                    }
                    while(k > j && nums[k] == nums[k + 1]){
                        k--;
                    }
                }else if(nums[j] + nums[k] > target){
                    k--;
                }else{
                    j++;
                }
            }
        }
        return res;
    }
};