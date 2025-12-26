#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        int i = 0, cnt = 0, n = s.length();
        while(i < n){
            if(i + 1 < n && m[s[i]] < m[s[i + 1]]){
                cnt += (m[s[i + 1]] - m[s[i]]);
                i += 2;
            }else{
                cnt += m[s[i]];
                i += 1;
            }
        }
        return cnt;
    }
};