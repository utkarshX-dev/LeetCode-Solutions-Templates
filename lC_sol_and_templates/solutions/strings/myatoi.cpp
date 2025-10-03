#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        long long res = 0, neg = 1, n = s.length(), i = 0;
        while(i < n && s[i] == ' '){
            i++;
        }
        bool positive = false;
        if(i < n && s[i] == '-'){
            neg = -1;
            i++;
        }
        if(i < n && s[i] == '+'){
            positive = true;
            i++;
        }
        if(neg == -1 && positive) return 0;
        while(i < n){
            if(!isdigit(s[i])) break;
            res = res * 10 + (s[i] - '0');
            i++;
            if(res > INT_MAX){
                if(neg == -1) res = (long long)INT_MAX + 1;
                else res = INT_MAX;
                break;
            }
        }
        return neg * res;
    }
};