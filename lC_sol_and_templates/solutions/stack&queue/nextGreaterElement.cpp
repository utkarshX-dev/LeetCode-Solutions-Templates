#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>mp;
        stack<int>st;
        st.push(-1);
        int n = nums2.size(), i = n - 1;
        while(i >= 0){
            int val = nums2[i];
            while(st.top() != -1 && st.top() <= val){
                st.pop();
            }
            mp.insert({val, st.top()});
            st.push(val);
            i--;
        }

        int m = nums1.size();
        for(int i = 0; i < m; i++){
            nums1[i] = mp[nums1[i]];
        }
        return nums1;
    }
};