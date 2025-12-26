#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    stack<char>st;
    int minAddToMakeValid(string s) {
        int openCnt = 0, closeCnt = 0, n = s.length();
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                st.push('(');
            }else if(s[i] == ')'){
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }else{
                    st.push(')');
                }
            }
        }
        return st.size();
    }
};