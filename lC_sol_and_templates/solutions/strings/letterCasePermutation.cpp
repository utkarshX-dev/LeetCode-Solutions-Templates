#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<string> res;
    void f(int i, string& s) {
        if (i == s.length()) {
            res.push_back(s);
            return;
        }
        char ch = s[i];
        if (isalpha(ch)) {
            if (isupper(ch)) {
                s[i] = s[i] + 32;
                f(i + 1, s);
                s[i] = s[i] - 32;
                f(i + 1, s);
            } else {
                s[i] = s[i] - 32;
                f(i + 1, s);
                s[i] = s[i] + 32;
                f(i + 1, s);
            }
        } else {
            f(i + 1, s);
        }
    }

public:
    vector<string> letterCasePermutation(string s) {
        f(0, s);
        return res;
    }
};