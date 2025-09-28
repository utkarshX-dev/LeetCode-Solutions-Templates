#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    int MOD = 1e9 + 7;
    // void print(vector<int>& arr){
    //     for(int i = 0; i < arr.size(); i++){
    //         cout << arr[i] << " ";
    //     }
    //     cout << endl;
    // }
    // void prefix(vector<long long>& arr){
    //     int size = arr.size();
    //     for(int i = 1; i < size; i++){
    //         arr[i] = (arr[i] * arr[i - 1])% MOD;
    //     }
    // }
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int i = 0;
        int temp = 1;
        vector<long long>arr;
        while(n != 0){
            if(n & 1) arr.push_back(temp);
            n = n >> 1;
            temp *= 2;
        }
        
        // print(arr);
        // prefix(arr);
        
        // print(arr);
        
        int size = queries.size();
        vector<int>res(size, 1);
        for(int i = 0; i < size; i++){
            int l = queries[i][0], r = queries[i][1];
            for(int j = l; j <= r; j++){
                res[i] = (res[i] * arr[j]) % MOD;
            }
        }
        return res;
    }
};
