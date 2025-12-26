#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<int> findPSE(vector<int>& heights,int n) {
        stack<int> st;
        vector<int> pse(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? i   : i - st.top() - 1;
            st.push(i);
        }
        return pse;
    }
    vector<int> findNSE(vector<int>& heights, int n) {
        stack<int> st;
        vector<int> nse(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n - i - 1: st.top() - i - 1;
            st.push(i);
        }
        return nse;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left = findPSE(heights, n);
        vector<int> right = findNSE(heights, n);
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, (left[i] + right[i] + 1) * heights[i]);
        }
        return maxi;
    }
};