#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// You are given positive integers low, high, and k.

// A number is beautiful if it meets both of the following conditions:

// The count of even digits in the number is equal to the count of odd digits.
// The number is divisible by k.
// Return the number of beautiful integers in the range [low, high].
class Solution {
private:
    using ll = long long;
    ll dp[2][11][21][2][21];
    ll solve(string& s, ll tight, ll idx, ll cnt, bool lz, int k, int rem){
        if(idx == s.length()) return (!lz && cnt == 10 && rem == 0);
        if(dp[tight][idx][cnt][lz][rem] != -1) return dp[tight][idx][cnt][lz][rem];
        int lb = 0, ub = (tight ? s[idx] - '0' : 9);
        ll res = 0;
        for(int i = lb; i <= ub; i++){
            ll new_lz    = lz && i == 0;
            ll new_tight = tight && i == ub;
            ll new_cnt = cnt;
            int new_rem = (rem * 10 + i) % k;
            if(!new_lz){
                if(i % 2 == 0) new_cnt++;
                else new_cnt--;
            }
            res += solve(s, new_tight, idx + 1, new_cnt, new_lz, k, new_rem);
        }
        return dp[tight][idx][cnt][lz][rem] = res;
    }
    ll calc(ll num, int k){
        string s = to_string(num);
        memset(dp, -1, sizeof(dp));
        return solve(s, 1, 0, 10, 1, k, 0);
    }
public:
    int numberOfBeautifulIntegers(int low, int high, int k) {
        return calc(high, k) - calc(low - 1, k);
    }
};