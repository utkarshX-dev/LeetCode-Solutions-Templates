#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;
        unordered_map<int, int>m;
        for(int& x : hand){
            m[x]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        for(auto& x: m){
            pq.push({x.first, x.second});
        }
        while(!pq.empty()){
            vector<pair<int, int>>temp;
            for(int i = 0; i < groupSize; i++){
                if(!pq.empty()){
                    temp.push_back(pq.top());
                    pq.pop();
                }else return false;
            }
            int prev = temp[0].first;
            int freqSt = temp[0].second;
            freqSt--;
            if(freqSt > 0){
                pq.push({prev, freqSt});
            }
            for(int i = 1; i < groupSize; i++){
                int curr = temp[i].first;
                if(curr != prev + 1){
                    return false;
                }else{
                    prev = curr;
                }
                int freq = temp[i].second;
                freq--;
                if(freq > 0){
                    pq.push({curr, freq});
                }
            }
        }
        return true;
    }
};