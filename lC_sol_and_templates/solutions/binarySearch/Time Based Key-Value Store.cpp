#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int time) {
        if (mp.find(key) != mp.end()) {
            int s = 0;
            auto& vec = mp[key];
            int e = vec.size() - 1;
            int res = -1;
            while (s <= e) {
                int mid = s + (e - s) / 2;
                if (vec[mid].first == time) {
                    return vec[mid].second;
                } else if (vec[mid].first < time) {
                    res = mid;
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }
            if (res == -1)return "";
            else return vec[res].second;
        } else {
            return "";
        }
    }
};
