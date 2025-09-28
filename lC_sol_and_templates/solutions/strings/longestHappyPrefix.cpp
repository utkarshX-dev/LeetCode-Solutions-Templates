#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length();
        vector<int> lps(n, 0);
        int pre = 0, suf = 1;
        while (suf < n) {
            while (pre > 0 && s[pre] != s[suf]) {
                pre = lps[pre - 1];
            }
            if (s[pre] == s[suf]) {
                lps[suf] = pre + 1;
                pre++;
            }
            suf++;
        }
        return s.substr(0, lps[n - 1]);
    }
};