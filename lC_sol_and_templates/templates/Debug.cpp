#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using ll = long long;

#ifdef LOCAL
#define dbg(x) cerr << #x << " = "; _print(x); cerr << endl;
#else
#define dbg(x)
#endif

template <class T> void _print(const T &x) { cerr << x; }
template <class T> void _print(const vector<T> &v) {
    cerr << "[ "; for (auto &i : v) { _print(i); cerr << " "; } cerr << "]";
}

class Solution {
public:
    int exampleFunction(vector<int>& nums, int target) {
        dbg(nums);
        dbg(target);
        return 0;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    Solution sol;
    cout << sol.exampleFunction(nums, target) << "\n";
}
