#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// We call a positive integer special if all of its digits are distinct.

// Given a positive integer n, return the number of special integers that belong to the interval [1, n].
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
    int countSpecialNumbers(int n) {
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return solve(s, 1, 0, 1, 0);
    }
};