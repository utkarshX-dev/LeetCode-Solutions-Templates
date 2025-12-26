//t.c : O(nlogn + n3)
//s.c : 0(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                long long currTarget = (long long)target - nums[i] - nums[j];
                // two pointers
                int s = j + 1;
                int e = n - 1;
                while (s < e) {
                    if (nums[s] + nums[e] == currTarget) {
                        while (s < e && nums[s] == nums[s + 1]) {
                            s++;
                        }
                        while (s < e && nums[e] == nums[e - 1]) {
                            e--;
                        }
                        res.push_back({nums[i], nums[j], nums[s], nums[e]});
                        s++;
                        e--;
                    } else if (nums[s] + nums[e] < currTarget) {
                        s++;
                    } else {
                        e--;
                    }
                }
            }
        }
        return res;
    }
};