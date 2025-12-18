#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0, n = version1.length(), m = version2.length();
        while(i < n || j < m){
            int val1 = 0, val2 = 0;
            while(i < n && version1[i] != '.'){
                val1 = val1 * 10 + (version1[i] - '0');
                i++;
            }
            while(j < m && version2[j] != '.'){
                val2 = val2 * 10 + (version2[j] - '0');
                j++;
            }
            if(val1 > val2) return 1;
            else if(val1 < val2) return -1;
            i++, j++;
        }
        return 0;
    }
};