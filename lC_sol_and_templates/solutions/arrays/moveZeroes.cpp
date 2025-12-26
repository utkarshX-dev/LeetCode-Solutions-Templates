#include <bits/stdc++.h>
using namespace std;
class Solution1 {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                swap(nums[j++], nums[i]);
            }
        }
        while(j < n){
            nums[j++] = 0;
        }
    }
};
class Solution2 {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                swap(nums[j++], nums[i]);
            }
        }
        while(j < n){
            nums[j++] = 0;
        }
    }
};