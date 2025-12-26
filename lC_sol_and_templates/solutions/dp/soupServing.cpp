//as n increases probability of a getting empty first increases too because we don't have any case where b is pour 100 ml and a is poured 0 ml
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<vector<int>>cases = {{100, 0}, {75, 25}, {25, 75}, {50, 50}};
    vector<vector<double>>dp;
    double f(int a, int b){
        if(a <= 0 && b <= 0) return 0.5;
        if(a <= 0) return 1.0;
        if(b <= 0) return 0.0;
        if(dp[a][b] != -1) return dp[a][b]; 

        double probability = 0;
        for(auto& x : cases){
            probability = probability + 0.25 * f(a - x[0], b - x[1]);
        }
        return dp[a][b] = probability;
    }
public:
    double soupServings(int n) {
        if(n >= 5000) return 1;
        dp.resize(5000, vector<double>(5000, -1));
        return f(n, n);
    }
};