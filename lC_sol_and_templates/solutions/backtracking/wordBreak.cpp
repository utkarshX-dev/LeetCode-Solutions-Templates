#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    unordered_map<string, bool> m;
    bool f(string& curr, vector<string>& wordDict, string& s) {
        if (curr == s) {
            return m[curr] = true;
        }

        if (m.find(curr) != m.end())
            return m[curr];
        for (int i = 0; i < wordDict.size(); i++) {
            string word = wordDict[i];
            if (word.length() + curr.length() <= s.length()) {
                string temp = "";
                int n = word.length();
                for(int i = curr.length(); i < curr.length() + n; i++){
                    temp += s[i];
                }
                if (temp == word) {
                    string next = curr + word;
                    if (f(next, wordDict, s))
                        return m[curr] = true;
                }
            }
        }
        return m[curr] = false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        string curr = "";
        return f(curr, wordDict, s);
    }
};