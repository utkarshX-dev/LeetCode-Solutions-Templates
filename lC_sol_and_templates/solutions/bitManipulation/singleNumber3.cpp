//xor of whole
//first 1 bit: find no of right shifts
//group them
//return xor
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int temp = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            temp ^= nums[i];
        }
        int shifts = 0;
        while(temp != 0){
            if(temp & 1) break;
            temp = temp >> 1;
            shifts++;
        }
        int bitmask = 0, group_a = 0, group_b = 0;
        bitmask = bitmask | (1 << shifts);
        for(int i = 0; i < n; i++){
            if(bitmask & nums[i]){
                group_a ^= nums[i];
            }else{
                group_b ^= nums[i];
            }
        }
        return {group_a, group_b};
    }
};