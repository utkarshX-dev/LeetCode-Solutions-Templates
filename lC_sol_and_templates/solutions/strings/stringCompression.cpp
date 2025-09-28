#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int len = 1, idx = 0;
        char ch = chars[0];
        for (int i = 1; i < n; i++) {
            if (chars[i] == chars[i - 1]) {
                len++;
            } else {
                if (len == 1) {
                    chars[idx++] = ch;
                } else {
                    chars[idx++] = ch;
                    string temp = to_string(len);
                    for (int j = 0; j < temp.size(); j++) {
                        chars[idx++] = temp[j];
                    }
                }
                len = 1;
                ch = chars[i];
            }
        }
        if (len == 1) {
            chars[idx++] = ch;
        } else {
            chars[idx++] = ch;
            string temp = to_string(len);
            for (int j = 0; j < temp.size(); j++) {
                chars[idx++] = temp[j];
            }
        }
        return idx;
    }
};