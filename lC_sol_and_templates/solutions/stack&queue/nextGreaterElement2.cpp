#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>newArr = nums;
        for(int i = 0; i < n; i++){
            newArr.push_back(nums[i]);
        }

        stack<int>st;
        int i = 2 * n - 1;
        while(i >= 0){
            int val = newArr[i];
            while(!st.empty() && st.top() <= val){
                st.pop();
            }
            if(st.empty()){
                newArr[i] = -1;
            }
            else newArr[i] = st.top();
            st.push(val);
            i--;
        }
        for(int i = 0; i < n; i++){
            nums[i] = newArr[i];
        }
        return nums;
    }
};