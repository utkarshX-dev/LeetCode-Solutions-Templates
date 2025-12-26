#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        if(k >= n) return "0";
        stack<char>st;
        for(int i = 0; i < n; i++){
            char ch = num[i];
            while(!st.empty() &&  k && st.top() > ch){
                st.pop();
                k--;
            }
            st.push(ch);
        }
        string res = "";
        while(k != 0){
            st.pop();
            k--;
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        int i = 0;
        while(i < res.length() && res[i] == '0'){
            i++;
        }
        string result = "";
        while(i < res.size()){
            result.push_back(res[i]);
            i++;
        }

        return result.length() == 0 ? "0" : result;
    }
};