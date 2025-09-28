//t.c : O(n)
//s.c : 0(1)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//binary search and two pointers
//two pointer approach..........
class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
       int n = a.size();
       int m = b.size();
       int cnt = 0;
       int i = 0, j = 0;
       while(i < n && j < m){
           cnt++;
           if(a[i] < b[j]){
               if(cnt == k) return a[i];
               i++;
           }else{
               if(cnt == k) return b[j];
               j++;
           }
       }
       while(i < n){
           cnt++;
           if(cnt == k) return a[i];
           i++;
       }
       while(j < m){
           cnt++;
           if(cnt == k) return b[j];
           j++;
       }
       return -1;
    }
};