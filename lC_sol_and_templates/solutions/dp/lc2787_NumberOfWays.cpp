#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<vector<int>>dp;
    vector<long long>powers;
    int MOD = 1e9 + 7;
    int power(int base, int exp){
        if(exp == 0) return 1;
        int half = power(base, exp/2);
        if(exp % 2 == 0) return half * half;
        return half * half * base;
    }
    int f(int i, int curr, int n, int x){
        if(curr == n) return 1;
        if (i > n || curr > n) return 0; 
        long long extra = powers[i];
        if(extra == -1) return 0; 

        if(dp[i][curr] != -1) return dp[i][curr];
        long long notPick = f(i + 1, curr, n, x);
        long long pick = 0;
        if(curr + extra <= n){
            pick = f(i + 1, curr + extra, n, x);
        }
        return dp[i][curr] = (pick + notPick) % MOD;
    }
public:
    int numberOfWays(int n, int x) {
        dp.resize(n + 1, vector<int>(n + 1, -1));
        powers.resize(n + 1, -1);
        for(int i = 1; i <= n; i++){
            long long res = power(i, x);
            if(res > n) break;
            else powers[i] = res;
        }
        return f(1, 0, n, x);
    }
};