#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<vector<int>> dp;
    bool isPalindrome(string& s, int i, int j) {
        if(i >= j) return true;
        if(dp[i][j] != -1) return dp[i][j];
        if (s[i] != s[j]) {
            return false;
        }
        return dp[i][j] = isPalindrome(s, i + 1, j - 1);
    }

    vector<vector<string>> res;
    void f(string& s, int i, vector<string>& temp) {
        if (i == s.length()) {
            res.push_back(temp);
            return;
        }
        string curr = "";
        for (int idx = i; idx < s.length(); idx++) {
            curr.push_back(s[idx]);
            if (isPalindrome(s, i, idx)) {
                temp.push_back(curr);
                f(s, idx + 1, temp);
                temp.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        dp.resize(n + 1, vector<int>(n + 1, -1));
        vector<string> temp = {};
        f(s, 0, temp);
        return res;
    }
};