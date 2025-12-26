#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//approach 1 top k frequent elements
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>m;
        for(int& x : nums){
            m[x]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        for(auto& x : m){
            int a = x.second;
            int b = x.first;
            pq.push({a, b});
            if(pq.size() > k) pq.pop();
        }
        vector<int>res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};


//Approach 2 : bucket sort
class Solution2 {
public:
    //time complexity: o(n + n + k); hashing + bucket filling + answer filling
    //space complexity: O(n + n) map and array
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>m;
        for(int& x : nums){
            m[x]++;
        }
        vector<vector<int>>bucket(n + 1);
        for(auto& x : m){
            int ele = x.first;
            int freq = x.second;
            bucket[freq].push_back(ele);
        }
        vector<int>res;
        for(int i = n; i >= 0; i--){
            for(int j = 0; j < bucket[i].size(); j++){
                res.push_back(bucket[i][j]);
                if(res.size() == k){
                    return res;
                }
            }
        }
        
        return {};
    }
};