#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<char>st;
        for(int i = 0; i < n; i++){
            char ch = s[i];
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }
            else if(!st.empty() &&  ch == '}' && st.top() == '{'){
                st.pop();
            }
            else if(!st.empty() &&  ch == ']' && st.top() == '['){
                st.pop();
            }
            else if(!st.empty() &&  ch == ')' && st.top() == '('){
                st.pop();
            }
            else return false;
        }
        return st.size() == 0;
    }
};