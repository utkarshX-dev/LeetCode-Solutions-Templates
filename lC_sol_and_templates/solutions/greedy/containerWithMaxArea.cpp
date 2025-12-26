#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), res = 0;
        int i = 0, j = height.size() - 1;
        while(i < j){
            res = max(res, (j - i) * min(height[i], height[j]));
            height[i] < height[j] ? i++ : j--;
        } 
        return res;
    }
};