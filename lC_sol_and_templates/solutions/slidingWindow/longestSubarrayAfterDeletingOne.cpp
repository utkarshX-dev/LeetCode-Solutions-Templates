#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int used = 0, ans = 0, i = 0, n = nums.size();
        for(int j = 0; j < n; j++){
            if(nums[j] == 0){
                used++;
                while(i <= j && used > 1){
                    if(nums[i] == 0){
                        used--;
                    }
                    i++;
                }
            }
            ans = max(ans, j - i + 1 - used);
        }
        return ans - !used;
    }
};