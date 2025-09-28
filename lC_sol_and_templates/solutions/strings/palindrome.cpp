#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while(i < j){
            if(s[j] == ' ' || !isalnum(s[j])){
                j--;
                continue;
            }
            if(s[i] == ' ' || !isalnum(s[i])){
                i++;
                continue;
            }
            if(tolower(s[i]) != tolower(s[j])){
                return false;
            }
            i++, j--;

        }
        return true;
    }
};