// Your task is to count the number of integers between a and b where no two adjacent digits are the same.

//Input
// The only input line has two integers a and b.
// Output
// Print one integer: the answer to the problem.
// Constraints

// 0 <= b <= 10  ^ 18

// Example
// Input:
// 123 321

// Output:
// 171

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define fastio() ios::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

const int MOD = 1e9 + 7;

ll power(ll a, ll b, ll mod = MOD) {
    ll res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll dp[2][11][20][2];

ll df_func(string& s, ll tight, ll prev, ll idx, bool lz){
    if(idx == s.length()) return 1;
    if(dp[tight][prev][idx][lz] != -1) return dp[tight][prev][idx][lz];
    int lb = 0, ub = tight ? s[idx] - '0' : 9;
    int res = 0;
    for(int i = lb; i <= ub; i++){
        if(i == prev && !lz) continue;
        res += df_func(s, (tight && i == ub), i, idx + 1, (lz && i == 0));
    }
    return dp[tight][prev][idx][lz] = res;
}

void solve() {
    int a, b;
    cin >> a >> b;
    ll res = 0;
    string r = to_string(b);
    string l = to_string(a - 1);
    memset(dp, -1, sizeof(dp));
    ll ans_r = df_func(r, 1, 10, 0, 1);
    memset(dp, -1, sizeof(dp));
    ll ans_l = df_func(l, 1, 10, 0, 1);
    cout << ans_r -  ans_l << '\n';
}

int main() {
    fastio();
    solve();
    return 0;
}