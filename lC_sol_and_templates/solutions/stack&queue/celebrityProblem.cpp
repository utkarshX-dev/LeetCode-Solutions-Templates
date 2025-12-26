#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        int n = mat.size();
        stack<int>st;
        for(int i = 0; i < n; i++){
            st.push(i);
        }
        while(st.size() > 1){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            if(mat[a][b]){
                st.push(b);
            }else{
                st.push(a);
            }
            
        }
        //celeb don't know anyone
        int possible = st.top();
        for(int i = 0; i < n; i++){
            if(possible != i && mat[possible][i]){
                return -1;
            }
        }
        //celeb known by everyone
        for(int i = 0; i < n; i++){
            if(!mat[i][possible]){
                return -1;
            }
        }
        return possible;
    }
};