#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string>temp;
        for(int i = 0; i < n; i++){
            temp.push_back(to_string(nums[i]));
        }
        sort(temp.begin(), temp.end(), [](string& a, string& b){
            return a + b > b + a;
        });
        string res = "";
        for(int i = 0; i < n; i++){
            res += temp[i];
        }
        bool allZero = true;
        for(int i = 0; i < res.size(); i++){
            if(res[i] != '0'){
                allZero = false;
                break;
            }
        }
        return allZero ? "0" : res;
    }
};