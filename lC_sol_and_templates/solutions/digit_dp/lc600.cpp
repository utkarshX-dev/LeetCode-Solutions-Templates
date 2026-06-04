#include <iostream>
#include <bits/stdc++.h>

// Given a positive integer n, return the number of the integers in the range [0, n] whose binary representations do not contain consecutive ones.

// Example 1:

// Input: n = 5
// Output: 5
// Explanation:
// Here are the non-negative integers <= 5 with their corresponding binary representations:
// 0 : 0
// 1 : 1
// 2 : 10
// 3 : 11
// 4 : 100
// 5 : 101
// Among them, only integer 3 disobeys the rule (two consecutive ones) and the other 5 satisfy the rule. 
// Example 2:

// Input: n = 1
// Output: 2
// Example 3:

// Input: n = 2
// Output: 3

class Solution {
private:
    int dp[2][32][11];
    int solve(string& s, int tight, int idx, int prev){
        if(idx == s.length()) return 1;
        if(dp[tight][idx][prev] != -1) return dp[tight][idx][prev];
        int lb = 0;
        int ub = (tight ? s[idx] - '0' : 1);
        int res = 0;
        for(int i = lb; i <= ub; i++){
            if(prev == 1 && i == 1) continue;
            res += solve(s, (tight && i == ub), idx + 1, i);
        }
        return dp[tight][idx][prev] = res;
    }
public:
    int findIntegers(int n) {
        int len = log2(n) + 1;
        bitset<32> bs(n);
        string binaryString = bs.to_string();
        memset(dp, -1, sizeof(dp));
        return solve(binaryString, 1, 0, 10);
    }
};
using namespace std;
int main(){
    
    return 0;
}


