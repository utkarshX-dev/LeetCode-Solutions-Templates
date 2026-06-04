#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution{
public:
    int matchCnt = 0;
    TreeNode *solve(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root) return NULL;

        TreeNode *left = solve(root->left, p, q);
        TreeNode *right = solve(root->right, p, q);

        if (root == p || root == q){
            matchCnt++;
            return root;
        }

        if (left && right)
            return root;
        return left ? left : right;
    }
};