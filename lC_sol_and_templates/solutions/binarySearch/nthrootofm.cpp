//t.c : O(log(n)log(m))
//s.c : 0(stackSpace)
#include <bits/stdc++.h>
using namespace std;
class Solution {
  private:
    int power(int n, int m){
        if(m == 0 || n == 1){
            return 1;
        }
        int half = power(n, m/2);
        if(m % 2 == 0){
            return half * half;
        }
        else{
            return half * half * n;
        }
    }
  public:
    int nthRoot(int n, int m) {
        int s = 1, e = m;
        while(s <= e){
            int mid = s + (e - s)/2;
            int res = power(mid, n);
            if(res == m){
                return mid;
            }
            else if(res < m){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
       return -1;
    }
};