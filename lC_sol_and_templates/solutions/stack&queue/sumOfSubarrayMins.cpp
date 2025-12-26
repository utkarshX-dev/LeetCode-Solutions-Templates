#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<int> findPSE(vector<int>& arr, int n){
        vector<int>pse(n);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            pse[i] = st.empty() ? -1  : st.top();
            st.push(i);
        }
        return pse;
    }
    vector<int> findNSE(vector<int>& arr, int n){
        vector<int>nse(n);
        stack<int> st;
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int MOD = 1e9 + 7;
        vector<int> pse = findPSE(arr, n);
        vector<int> nse = findNSE(arr, n);
        long long res = 0;
        for(int i = 0; i < n; i++){
            int left = i - pse[i];
            int right = nse[i] - i;
            res = (res + 1LL * arr[i] * left * right) % MOD;
        }
        return (int)res;  
    }
};