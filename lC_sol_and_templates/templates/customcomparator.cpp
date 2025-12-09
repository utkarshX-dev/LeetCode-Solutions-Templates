#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //comparator for heaps
    auto cmp = [](const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.first > b.first; // min heap based on first
    };

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        decltype(cmp)>
        pq(cmp); // must pass comparator to constructor

    //comparator for sort
    auto cmp2 = [](const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.second < b.second; // ascending order based on second
    };
    vector<pair<int, int>> vec = {{1, 3}, {2, 1}, {4, 2}};
    sort(vec.begin(), vec.end(), cmp2);

    //for maps and sets
    auto cmp3 = [](const int &a, const int &b)
    {
        return a > b; // descending order
    };
    set<int, decltype(cmp3)> s(cmp3); // must pass comparator to constructor
    s.insert(3);
    s.insert(1);
    return 0;
}