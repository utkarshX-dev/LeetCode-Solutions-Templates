//recursion->memoization->tabulation->space optimization
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//0 1 1 2 3 5 8

int main(){
    int n;
    cin >> n;
    
    int curr = 1, prev = 0;
    for(int i = 2; i <= n; i++){
        int nextVal = prev + curr;
        prev = curr;
        curr = nextVal;
    }
    cout << curr;
    return 0;
}
