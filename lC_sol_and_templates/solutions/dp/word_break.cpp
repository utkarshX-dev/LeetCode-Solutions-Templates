#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    unordered_set<string>st;
    vector<int>dp;
    bool solve(int i, string& s){
        if(i == s.length()){
            return dp[i] = true;
        }
        if(dp[i] != -1) return false;
        string temp = "";
        for(int idx = i; idx < s.length(); idx++){
            temp.push_back(s[idx]);
            if(st.find(temp) != st.end()){
                if(solve(idx + 1, s)){
                    return dp[i] = true;
                }
            }
        }
        return dp[i] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for(int i = 0; i < wordDict.size(); i++){
            st.insert(wordDict[i]);
        }
        dp.resize(s.length() + 1, -1);
        return solve(0, s);   
    }
};