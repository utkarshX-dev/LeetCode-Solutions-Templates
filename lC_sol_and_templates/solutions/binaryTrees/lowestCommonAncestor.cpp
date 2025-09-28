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
class Solution {
private:   
    TreeNode* f(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL){
            return NULL;
        }
        if(root == p) return root;
        if(root == q) return root;
        TreeNode* l = f(root->left, p, q);
        TreeNode* r = f(root->right, p, q);
        if(l && r){
            return root;
        }else if(l) return l;
        else return r;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return f(root, p, q);
    }
};