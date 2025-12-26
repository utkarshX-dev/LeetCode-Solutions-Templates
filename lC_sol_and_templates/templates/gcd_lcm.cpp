#include <iostream>
using namespace std;
//does not matter gcd(a,b) or gcd(b,a) both return same value
int gcd(int a, int b){
    if(a == 0) return b;
    return gcd(b % a, a);
}
int main(){
    int a, b;
    cout << "Enter value of numbers" << endl;
    cin >> a >> b; 
    cout << "GCD "; 
    cout << gcd(a, b) << endl;
    cout << "LCM ";
    cout << (a * b) / gcd(a, b) << endl;
    return 0;
}