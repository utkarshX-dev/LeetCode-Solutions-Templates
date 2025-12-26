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
public:
    TreeNode* first = NULL;
    TreeNode* middle = NULL;
    TreeNode* last = NULL;
    TreeNode* prev = NULL;

    void inorder(TreeNode* curr){
        if(!curr) return;
        inorder(curr->left);
        if(prev && prev->val > curr->val){
            if(!first){
                first = prev;
                middle = curr;  
            }else{
                last = curr;
            }
        }
        prev = curr;
        inorder(curr->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        if(last != NULL){
            swap(first->val, last->val);
        }else{
            swap(first->val, middle->val);
        }
    }
};