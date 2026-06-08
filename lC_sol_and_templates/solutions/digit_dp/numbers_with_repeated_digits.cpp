#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Given an integer n, return the number of positive integers in the range [1, n] that have at least one repeated digit.
//at least one
//1 2 3 4 5 6 7...
// total - no digits repeated ans...
class Solution {
private:
    using ll = long long;
    ll dp[2][11][2][1024];
    ll solve(string& s, int tight, int idx, int lz, int mask){
        if(idx == s.length()) return !lz;
        if(dp[tight][idx][lz][mask] != -1) return dp[tight][idx][lz][mask];
        int lb = 0;
        int ub = (tight ? s[idx] - '0' : 9);
        ll res = 0;
        for(int dig = lb; dig <= ub; dig++){
            int nt = tight && dig == ub;
            int nlz = lz && dig == 0;
            if(!nlz && (1 & (mask >> dig))) continue;
            int newmask = nlz ? mask : mask | (1 << dig);
            res += solve(s, nt, idx + 1, nlz, newmask);
        }
        return dp[tight][idx][lz][mask] = res;
    }
public:
    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return n - solve(s, 1, 0, 1, 0);    
    }
};