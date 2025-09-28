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
class Solution1 {
private:
     int f(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int leftHeight = f(root->left);
        int rightHeight = f(root->right);
        return max(leftHeight, rightHeight) + 1;
    }
    bool solve(TreeNode* root){
        if(root == nullptr){
            return true;
        }
        bool leftBalance = solve(root->left);
        bool rightBalance = solve(root->right);
        int leftHeight = f(root->left);
        int rightHeight = f(root->right);
        bool heightBalance = abs(leftHeight - rightHeight) <= 1 ? true : false;
        return leftBalance && rightBalance && heightBalance;
    }
public:
    bool isBalanced(TreeNode* root) {
        return solve(root);
    }
};
//method 2 not much intuitive but more efficient
class Solution {
private:
    int height(TreeNode* root){
        if(root == nullptr) return 0;
        int leftHeight = height(root->left);
        if(leftHeight == -1) return -1;
        int rightHeight = height(root->right);
        if(rightHeight == -1) return -1;
        if(abs(leftHeight - rightHeight) > 1) return -1;
        return max(leftHeight, rightHeight) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};