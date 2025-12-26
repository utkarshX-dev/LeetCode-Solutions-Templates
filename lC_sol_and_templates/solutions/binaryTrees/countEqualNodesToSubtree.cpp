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
    int cnt = 0;
    pair<int, int> f(TreeNode* root){
        if(root == NULL) return {0, 0};
        auto left = f(root->left);
        auto right = f(root->right);
        int total = left.first + right.first + root->val;
        int nodes = left.second + right.second + 1;
        if(total / nodes == root->val){
            cnt++;
        }
        return {total, nodes};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        f(root);
        return cnt;
    }
};