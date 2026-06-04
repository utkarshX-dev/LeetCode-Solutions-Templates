#include <iostream>
#include <bits/stdc++.h>

// Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

// Example 1:

// Input: n = 13
// Output: 6
// Example 2:

// Input: n = 0
// Output: 0

using namespace std;
class Solution {
private:
    int dp[2][12][12];
    int solve(int tight, string& s, int cnt, int idx){
        if(idx == s.length()) return cnt;
        if(dp[tight][cnt][idx] != -1) return dp[tight][cnt][idx];
        int lb = 0;
        int ub = (tight ? s[idx] - '0' : 9);
        int res = 0;
        for(int i = lb; i <= ub; i++){
            res += solve((tight && i == ub), s, cnt + (i == 1), idx + 1);
        }
        return dp[tight][cnt][idx] = res;
    }
public:
    int countDigitOne(int n) {
        string r = to_string(n);
        memset(dp, -1, sizeof(dp));
        return solve(1, r, 0, 0);
    }
};
int main(){
    
    return 0;
}
