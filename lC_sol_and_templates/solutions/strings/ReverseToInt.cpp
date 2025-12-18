#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    using ll = long long;
    int reverse(ll x) {
        bool neg = false;
        if(x < 0) neg = true;
        x = abs(x);
        string s = to_string(x);
        ll res = 0;
        for(int i = s.length() - 1; i >= 0; i--){
            res = res * 10 + (s[i] - '0');
            if(neg && res > abs((ll) INT_MIN)) return 0;
            if(!neg && res > INT_MAX) return 0;
        }
        return res * (neg ? -1 : 1);
    }
};