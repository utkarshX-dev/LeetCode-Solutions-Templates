#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
private:
    int ans = -1;
    void dfs(TreeNode* root, int k, int& cnt){
        if(!root){
            return;
        }
        dfs(root->left, k, cnt);
        cnt++;
        if(cnt == k){
            ans = root->val;
            return;
        }
        dfs(root->right, k, cnt);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        dfs(root, k, cnt);
        return ans;
    }
};