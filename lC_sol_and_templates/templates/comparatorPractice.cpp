#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// If you return true: A is placed before B.

// If you return false: B is placed before A (or they are equal).
int main()
{
    // Sort the vector with these rules:
    // Smaller age comes first
    // If ages are equal, lexicographically larger name comes first
    vector<pair<int, string>> v = {{20, "mohan"}, {20, "arun"}, {25, "john"}};
    
    sort(v.begin(), v.end(), [](const pair<int, string>& a, const pair<int, string>& b){
        if(a.first == b.first) return a.second < b.second;
        else return a.first < b.first;
    });

    // for(int i = 0; i < v.size(); i++){
    //     cout << v[i].first << " " << v[i].second << endl;
    // }

//     Make the comparator such that:
// Even numbers have higher priority than odd numbers
// Among even numbers: smaller number has higher priority
// Among odd numbers: larger number has higher priority
auto cmp = [](const int& a, const int& b){
    if(a % 2 == 0 && b % 2 == 0) return a < b;
    else if(a % 2 != 0 && b % 2 != 0) return a > b;
    else return a % 2 == 0;
};
vector<int>pq;
pq.push_back(7);
pq.push_back(4);
pq.push_back(12);
pq.push_back(3);
pq.push_back(11);
pq.push_back(2);

sort(pq.begin(), pq.end());
    for(int& x : pq){
        cout << x << " ";
    }
    
    return 0;
}