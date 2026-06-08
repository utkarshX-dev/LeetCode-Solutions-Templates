#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// You are given two numeric strings num1 and num2 and two integers max_sum and min_sum. We denote an integer x to be good if:

// num1 <= x <= num2
// min_sum <= digit_sum(x) <= max_sum.
// Return the number of good integers. Since the answer may be large, return it modulo 109 + 7.

// Note that digit_sum(x) denotes the sum of the digits of x.
class Solution {
private:
    using ll = long long;
    ll MOD = 1e9 + 7;
    ll mini, maxi;
    ll dp[24][2][402];
    ll solve(string& s, int idx, int tight, int curr_sum){
        if(idx == s.length()) return curr_sum >= mini;
        if(dp[idx][tight][curr_sum] != -1) return dp[idx][tight][curr_sum];
        int lb = 0;
        int ub = tight ? s[idx] - '0' : 9;
        ll res = 0;
        for(int dig = 0; dig <= ub; dig++){
            if(curr_sum + dig > maxi) continue; 
            int newTight = tight && dig == ub;
            res = (res + solve(s, idx + 1, newTight, curr_sum + dig)) % MOD;
        }
        return dp[idx][tight][curr_sum] = (res % MOD);
    }
    string subtractOne(string s) {
    int i = s.size() - 1;
    while (i >= 0 && s[i] == '0') {
        s[i] = '9';
        i--;
    }
    if (i >= 0) s[i]--;

    int pos = 0;
    while (pos + 1 < s.size() && s[pos] == '0') pos++;
    return s.substr(pos);
}
public:
    int count(string num1, string b, int min_sum, int max_sum) {
        mini = min_sum, maxi = max_sum;
        string a = subtractOne(num1);

        memset(dp, -1, sizeof(dp));
        ll right_ans = solve(b, 0, 1, 0);
        
        memset(dp, -1, sizeof(dp));
        ll left_ans = solve(a, 0, 1, 0);
        
        return (right_ans - left_ans + MOD) % MOD;
    }
};