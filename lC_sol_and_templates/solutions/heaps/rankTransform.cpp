#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        for(int i = 0; i < n; i++){
            pq.push({arr[i], i});
        }
        int rank = 0;
        int prev = INT_MAX;
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            if(node.first != prev){
                rank++;
                arr[node.second] = rank;
            }else{
                arr[node.second] = rank;
            }
            prev = node.first;
            
        }
        return arr;
    }
};