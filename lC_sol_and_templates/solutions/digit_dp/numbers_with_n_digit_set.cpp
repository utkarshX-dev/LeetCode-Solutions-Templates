#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Given an array of digits which is sorted in non-decreasing order. You can write numbers using each digits[i] as many times as we want. For example, if digits = ['1','3','5'], we may write numbers such as '13', '551', and '1351315'.

// Return the number of positive integers that can be generated that are less than or equal to a given integer n.
class Solution {
private:
    unordered_set<int>st;
    int dp[10][2][2];
    int solve(string& s, int idx, bool lz, int tight){
        if(idx == s.length()) return !lz;
        if(dp[idx][lz][tight] != -1) return dp[idx][lz][tight];
        int res = 0;
        if(lz){
            res += solve(s, idx + 1, lz, 0);
        }
        int ub = tight ? s[idx] - '0' : 9;
        for(int x : st){
            if(x > ub) continue;
            int nt = tight && x == (s[idx] - '0');
            res += solve(s, idx + 1, 0, nt);
        }
        return dp[idx][lz][tight] = res;
    }
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        for(auto& x : digits){
            st.insert(x[0] - '0');
        }
        return solve(s, 0, 1, 1);
    }
};