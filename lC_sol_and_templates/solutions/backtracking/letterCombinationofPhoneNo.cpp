#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:    
    vector<string>res;
    void f(int i, string& digits, unordered_map<char, string>&mp, string& temp){
        if(i == digits.length()){
            res.push_back(temp);
            return;
        }
        string curr = mp[digits[i]];
        for(int idx = 0; idx < curr.length(); idx++){
            temp.push_back(curr[idx]);
            f(i + 1, digits, mp, temp);
            temp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        unordered_map<char, string>mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        string temp = "";
        f(0, digits, mp, temp);
        return res;
    }
};