#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        if(t.length() > n) return "";

        int startIdx = 0, minWindowSize = INT_MAX, requiredCnt = t.length();
        unordered_map<char, int> mp;
        for (char ch : t) mp[ch]++;
        int i = 0, j = 0;
        
        while(j < n){
            if(mp.find(s[j]) != mp.end()){
                if (mp[s[j]] > 0) requiredCnt--; //imp
                mp[s[j]]--;
            }
            while(requiredCnt == 0){
                if(j - i + 1 < minWindowSize){
                    minWindowSize = j - i + 1;
                    startIdx = i;
                }
                if(mp.find(s[i]) != mp.end()){
                    mp[s[i]]++;
                    if (mp[s[i]] > 0) requiredCnt++; //imp
                }
                i++;
            }
            j++;
        }
        return  minWindowSize == INT_MAX ?  "" : s.substr(startIdx, minWindowSize); //(pos -> pos + len)
    }
};