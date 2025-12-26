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
    vector<string> res;
    void f(string temp, TreeNode* root) {
        if (!root->left && !root->right) {
            res.push_back(temp);
            return;
        }
        if (root->left) {
            f(temp + "->" + to_string(root->left->val), root->left);
        }
        if (root->right) {
            char ch = root->right->val + '0';
            f(temp +  "->" + to_string(root->right->val), root->right);
        }
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string temp = to_string(root->val);
        f(temp, root);
        return res;
    }
};