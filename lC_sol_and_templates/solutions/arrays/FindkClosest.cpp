#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>res;
        vector<pair<int, int>>temp;
        for(int& curr : arr){
            temp.push_back({abs(x - curr), curr});
        }
        sort(temp.begin(), temp.end());
        for(int i = 0; i < k; i++){
            res.push_back(temp[i].second);
        }
        sort(res.begin(), res.end());
        return res;
    }
};