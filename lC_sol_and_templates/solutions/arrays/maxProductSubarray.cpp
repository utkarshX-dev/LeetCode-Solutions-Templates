//tc O(N)
//sc O(1)
//if all positive return product of all
//if even no of negs return product of all
//if zero reset to 1
//if odd no of negs : neglect a negative answer is in prefix or is in suffix......
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix = 1;
        int suffix = 1;
        int maxProduct = INT_MIN;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;
            prefix *= nums[i];
            suffix *= nums[n - i - 1];
            maxProduct = max(maxProduct, max(suffix, prefix));
        }
        return maxProduct;
    }
};
