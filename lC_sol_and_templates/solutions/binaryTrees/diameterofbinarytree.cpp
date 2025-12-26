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
    int maxi = -1;
    int f(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int leftHeight = f(root->left);
        int rightHeight = f(root->right);
        maxi = max(leftHeight + rightHeight, maxi);
        return max(leftHeight, rightHeight) + 1; 
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        f(root);
        return maxi;
    }
};