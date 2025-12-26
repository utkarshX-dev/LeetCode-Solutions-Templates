#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (int i = 0; i < tasks.size(); i++) {
            freq[tasks[i] - 'A']++;
        }

        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) {
                pq.push(freq[i]);
            }
        }

        int time = 0;
        while (!pq.empty()) {
            vector<int> temp;
            for (int i = 0; i <= n; i++) {
                if (!pq.empty()) {
                    int curr = pq.top();
                    pq.pop();
                    curr--;
                    temp.push_back(curr);
                }
            }
            for (int it : temp) {
                if(it != 0) pq.push(it);
            }
            if (pq.empty()) {
                time += temp.size();
            } else
                time += n + 1;
        }
        return time;
    }
};