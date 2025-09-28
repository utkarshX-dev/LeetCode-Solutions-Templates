#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//using prefix and suffix array
class Solution1 {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftHeights(n, 0);
        
        for (int i = 1; i < n; i++) {
            leftHeights[i] = max(leftHeights[i - 1], height[i - 1]);
        }
        
        vector<int> rightHeights(n, 0);
        for(int i =  n - 2; i >= 0; i--){
            rightHeights[i] = max(rightHeights[i + 1], height[i + 1]);
        }
        int res = 0;
        
        for (int i = 1; i < n - 1; i++) {
            int waterStored = min(leftHeights[i], rightHeights[i]) - height[i];
            res += waterStored > 0 ? waterStored : 0;
        }
        return res;
    }
};
//two pointer approach
class Solution2 {
public:
    int trap(vector<int>& heights) {
        int n = heights.size();
        int l = 0, r = n - 1;
        int leftMax = 0, rightMax = 0;
        int res = 0;
        while (l <= r) {
            leftMax = max(leftMax, heights[l]);
            rightMax = max(rightMax, heights[r]);
            if (leftMax < rightMax) {
                int trap = leftMax - heights[l];
                res += trap > 0 ? trap : 0;
                l++;
            } else {
                int trap = rightMax - heights[r];
                res += trap > 0 ? trap : 0;
                r--;
            }
        }
        return res;
    }
};