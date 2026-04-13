#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//itertive
double solvePow(double a, int b){
        double res = 1;
        while(b > 0){
            if(b % 2 == 1){
                res = res * a;
            }
            a = a * a;
            b /= 2;
        }
        return res;
}
//recursive
double myPow(double x, int n) {
    if (n == 0) return 1.0;
    if (n < 0) {
        x = 1 / x;
        if (n == INT_MIN) { 
            return x * myPow(x, INT_MAX);
        }
        n = -n;
    }
        
    double half = myPow(x, n / 2);
    if (n % 2 == 0) return half * half;
    else return x * half * half;
}
