#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int& curr : asteroids){
            bool destroyed = false;
            while(!st.empty() && st.top() > 0 && curr < 0){
                if(abs(st.top()) == abs(curr)){
                    destroyed = true;
                    st.pop();
                    break;
                }else if(abs(st.top()) > abs(curr)){
                    destroyed = true;
                    break;
                }
                else{
                    st.pop();
                }
            }
            if(!destroyed){
                st.push(curr);
            }
        }

        vector<int> res;
        while (!st.empty()) {
            res.insert(res.begin(), st.top());
            st.pop();
        }
        return res;
    }
};
