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
    void flatten(TreeNode* root) {
        if(!root) return;
        TreeNode* curr = root;
        while(curr != NULL){
            if(curr->left){
                TreeNode* temp = curr->left;
                TreeNode* temp1 = curr->left;
                curr->left = NULL;
                while(temp->right != NULL){
                    temp = temp->right;
                }
                temp->right = curr->right;
                curr->right = temp1;
            }
            curr = curr->right;
        }
    }
};