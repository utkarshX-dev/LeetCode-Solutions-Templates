#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<int> visited, destination, recStack;

    bool dfs(int i, bool isForward, vector<int>& nums) {
        if (recStack[i])
            return true;
        if (visited[i])
            return false;

        visited[i] = 1;
        recStack[i] = 1;

        int next = destination[i];
        if ((nums[next] > 0) != isForward || next == i) {
            recStack[i] = 0;
            return false;
        }

        if (dfs(next, isForward, nums))
            return true;

        recStack[i] = 0;
        return false;
    }

public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return false;
        visited.resize(n, 0);
        destination.resize(n, 0);
        recStack.resize(n, 0);
        for (int i = 0; i < n; i++) {
            int val = (nums[i] + i) % n;
            if (val < 0) {
                destination[i] = n + val;
            } else {
                destination[i] = val;
            }
            // cout << destination[i] << " ";
        }
        // cout << endl;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (dfs(i, nums[i] > 0, nums)) return true;
            }
        }
        return false;
    }
};