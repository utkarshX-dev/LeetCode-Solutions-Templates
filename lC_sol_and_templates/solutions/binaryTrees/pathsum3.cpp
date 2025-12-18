//dfs
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
private:
    int cnt = 0;
    using ll = long long;
    unordered_map<ll, int> mp;
    void f(TreeNode* root, ll& temp, ll targetSum) {
        if (!root) return;
        temp += root->val;
        if (mp.find(temp - targetSum) != mp.end()) {
            cnt += mp[temp - targetSum];
        }
        mp[temp]++;
        f(root->left, temp, targetSum);
        f(root->right, temp, targetSum);
        mp[temp]--;
        temp -= root->val;
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        ll temp = 0;
        mp[0] = 1;
        f(root, temp, targetSum);
        return cnt;
    }
};