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
    bool f(TreeNode* l, TreeNode* r){
        if((l && !r) || (!l && r)) return false;
        if(!l && !r) return true;
        bool curr = (l->val == r->val);
        bool left = f(l->left, r->right);
        bool right = f(l->right, r->left);
        return curr && left && right;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return f(root->left, root->right);
    }
};