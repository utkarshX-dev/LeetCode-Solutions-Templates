#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size(), temp = 0;
        for(int i = 0; i < 32; i++){
            int oneBitCnt = 0;
            for(int j = 0; j < n; j++){
                if(nums[j] & (1 << i)){
                    oneBitCnt++;
                }
            }
            if(oneBitCnt % 2 != 0){
                temp = temp | (1 << i);
            }
        }
        return temp;
    }
};