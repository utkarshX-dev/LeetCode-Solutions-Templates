#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// You are given two integers num1 and num2 representing an inclusive range [num1, num2].

// The waviness of a number is defined as the total count of its peaks and valleys:

// A digit is a peak if it is strictly greater than both of its immediate neighbors.
// A digit is a valley if it is strictly less than both of its immediate neighbors.
// The first and last digits of a number cannot be peaks or valleys.
// Any number with fewer than 3 digits has a waviness of 0.
// Return the total sum of waviness for all numbers in the range [num1, num2].
class Solution {
private:
    using ll = long long;

    struct Node {
        ll cnt;
        ll wave;
    };

    Node dp[18][2][2][11][11];
    bool vis[18][2][2][11][11];

    Node solve(string& s, int idx, int tight, int started, int prev2, int prev1) {
        if (idx == s.size()) return {1, 0};

        if (vis[idx][tight][started][prev2][prev1]) return dp[idx][tight][started][prev2][prev1];
        vis[idx][tight][started][prev2][prev1] = true;

        Node ans = {0, 0};

        int ub = tight ? s[idx] - '0' : 9;

        for (int d = 0; d <= ub; d++) {
            int ntight = tight && (d == ub);
            if (!started && d == 0) {
                auto child = solve(s, idx + 1, ntight, 0, 10, 10);
                ans.cnt += child.cnt;
                ans.wave += child.wave;
            }
            else if (!started) {
                auto child = solve(s, idx + 1, ntight, 1, 10, d);
                ans.cnt += child.cnt;
                ans.wave += child.wave;
            }
            else if (prev2 == 10) {
                auto child = solve(s, idx + 1, ntight, 1, prev1, d);
                ans.cnt += child.cnt;
                ans.wave += child.wave;
            }
            else {
                ll add = ((prev2 < prev1 && prev1 > d) || (prev2 > prev1 && prev1 < d));
                auto child = solve(s, idx + 1, ntight, 1, prev1, d);
                ans.cnt += child.cnt;
                ans.wave += child.wave + add * child.cnt;
            }
        }

        return dp[idx][tight][started][prev2][prev1] = ans;
    }

    ll calc(ll x) {
        if (x <= 0) return 0;
        string s = to_string(x);
        memset(vis, 0, sizeof(vis));
        return solve(s, 0, 1, 0, 10, 10).wave;
    }

public:
    long long totalWaviness(long long num1, long long num2) {
        return calc(num2) - calc(num1 - 1);
    }
};