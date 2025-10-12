#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> res(n, -1);
        unordered_map<int,int> full;
        set<int> sunny;

        for(int i = 0; i < n; i++) {
            if(rains[i] > 0) {
                int lake = rains[i];
                if(full.count(lake)) {
                    auto it = sunny.lower_bound(full[lake]);
                    if(it == sunny.end()) return {};
                    res[*it] = lake;
                    sunny.erase(it);
                }
                full[lake] = i;
                res[i] = -1;
            } else {
                sunny.insert(i);
                res[i] = 1;
            }
        }

        return res;
    }
};