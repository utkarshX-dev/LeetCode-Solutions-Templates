//a inversion if an array is a pair of indices (i, j) such that i < j and arr[i] > arr[j].
//approach : merge sort
//time complexity : O(n)
//space complexity : O(n)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>freq(n * n + 1, 0);
        for(auto& vec : grid){
            for(auto& it : vec){
                freq[it]++;
            }
        }
        int missing = -1;
        int repeated = -1;
        for(int i = 1; i <= n * n; i++){
            if(freq[i] == 0){
                missing = i;
            }
            if(freq[i] > 1){
                repeated = i;
            }
        }
        return {repeated, missing};
    }
};