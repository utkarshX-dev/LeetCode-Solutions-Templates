#include <iostream>
using namespace std;
int EvenfindSum(int n){
    int sum = 0;
    for(int i = 0; i <= n; i += 2){
        sum += i;
    }
    return sum;
}

int main(){
    int n;
    cin >> n;
    cout << EvenfindSum(n);
    return 0;
}