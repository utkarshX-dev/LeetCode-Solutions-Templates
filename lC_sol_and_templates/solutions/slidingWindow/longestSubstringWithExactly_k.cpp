#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n = s.length();
        unordered_map<char, int>mp;
        int i = 0;
        int ans = -1;
        for(int j = 0; j < n; j++){
            mp[s[j]]++;
            while(i < j && mp.size() > k){
                mp[s[i]]--;
                if(mp[s[i]] == 0){
                    mp.erase(s[i]);
                }
                i++;
            }
            if(mp.size() == k){
                ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};