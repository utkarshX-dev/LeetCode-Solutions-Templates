#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    int distinctAtMost(vector<int>& s, int k) {
        int n = s.size();
        unordered_map<int, int> mp;
        int i = 0;
        int ans = 0;
        for (int j = 0; j < n; j++) {
            mp[s[j]]++;
            while (mp.size() > k) {
                mp[s[i]]--;
                if (mp[s[i]] == 0) {
                    mp.erase(s[i]);
                }
                i++;
            }
            ans += j - i + 1;
        }
        return ans;
    }

public:
    int subarraysWithKDistinct(vector<int>& s, int k) {
        return distinctAtMost(s, k) - distinctAtMost(s, k - 1);
    }
};