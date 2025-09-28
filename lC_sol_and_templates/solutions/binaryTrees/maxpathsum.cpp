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
class Solution
{
private:
    int maxi = INT_MIN;
    int f(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int leftSum = max(0, f(root->left));
        int rightSum = max(0, f(root->right));
        maxi = max(maxi, root->val + leftSum + rightSum); // get current maximum
        return root->val + max(leftSum, rightSum);        // return one of these paths
    }

public:
    int maxPathSum(TreeNode *root)
    {
        f(root);
        return maxi;
    }
};