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
//method 1 
//******inorder traversal of bst is sorted**********
class Solution1 {
private:
    vector<int>in;
    void inOrder(TreeNode* root){
        if(root == NULL) return;
        inOrder(root->left);
        in.push_back(root->val);
        inOrder(root->right);
    }
public:
    bool isValidBST(TreeNode* root) {
        inOrder(root);
        for(int i = 1; i < in.size(); i++){
            if(in[i] <= in[i - 1]){
                return false;
            }
        }
        return true;
    }
};
//method 2
//using [min, max] range
class Solution {
private:
    bool f(TreeNode* root, long long maxi, long long mini){
        if(root == NULL) return true;
        if(root->val >= maxi || root->val <= mini){
            return false;
        }
        bool left = f(root->left, root->val, mini);
        bool right = f(root->right, maxi, root->val);
        return left && right;
    }
public:
    bool isValidBST(TreeNode* root) {
        return f(root, LLONG_MAX, LLONG_MIN);
    }
};