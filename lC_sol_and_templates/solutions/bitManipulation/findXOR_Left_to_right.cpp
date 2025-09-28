#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//t.c = O(1)
//s.c = O(1)
class Solution {
  private:
    int XOR(int n){
        if(n % 4 == 1) return 1; 
        else if(n % 4 == 2) return n + 1;
        else if(n % 4 == 3) return 0;
        else return n;
    }
  public:
    int findXOR(int l, int r) {
        // complete the function here
        return XOR(l - 1) ^ XOR(r);
    }
};