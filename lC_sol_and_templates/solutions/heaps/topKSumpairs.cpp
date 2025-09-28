#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
//time complexity: O(nlogn)
//space complexity: O(n)
using namespace std;
class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        vector<int>res;
        int n = a.size();
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        priority_queue<pair<int, pair<int, int>>>pq;
        set<pair<int, int>>st;
        pq.push({a[n-1] + b[n - 1], {n - 1, n - 1}});
        st.insert({n - 1, n - 1});
        
        while(k--){
            auto node = pq.top();
            pq.pop();
            res.push_back(node.first);
            int currX = node.second.first;
            int currY = node.second.second;
            
            int ax = currX - 1;
            if(ax >= 0 && !st.count({ax, currY})){
                pq.push({a[ax] +  b[currY], {ax, currY}});
                st.insert({ax, currY});
            }
            int by = currY - 1;
            if(by >= 0 && !st.count({currX, by})){
                st.insert({currX, by});
                pq.push({a[currX] + b[by], {currX, by}});
            }
        }
        return res;
    }
};