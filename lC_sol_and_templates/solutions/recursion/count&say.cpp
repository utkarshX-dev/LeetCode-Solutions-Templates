#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    string f(int i, int n){
        if(i == 1){
            return "1";
        }
        string curr = "";
        int cnt = 1;
        string temp = f(i - 1, n);
        char ch = temp[0];
        for(int i = 1; i < temp.length(); i++){
            if(temp[i] == temp[i - 1]){
                cnt++;
            }else{
                curr = curr +  to_string(cnt) + ch;
                cnt = 1;
                ch = temp[i];
            }
        }
        curr = curr +  to_string(cnt) + ch;
        return curr;
    }
public:
    string countAndSay(int n) {
        return f(n, n);
    }
};