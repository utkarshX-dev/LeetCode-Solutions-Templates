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

//tc: O(h), sc O(h)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    TreeNode* f(TreeNode* root, int key) {
        if (root == NULL) {
            return NULL;
        }
        if (root->val > key) {
            root->left = f(root->left, key);
        } else if (root->val < key) {
            root->right = f(root->right, key);
        } else {
            if (!root->right && !root->left) {
                return NULL;
            } else if (root->right && !root->left) {
                return root->right;
            } else if (root->left && !root->right) {
                return root->left;
            } else {
                TreeNode* inSucc = root->right;
                while (inSucc->left != NULL) {
                    inSucc = inSucc->left;
                }
                root->val = inSucc->val;
                root->right = deleteNode(root->right, root->val);
            }
        }
        return root;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) { 
        return f(root, key); 
    }
};
//tc: O(n), sc O(n)
class Solution2 {
private:
    vector<int>vec;
    void dfs(TreeNode* root, int key){
        if(root == NULL){
            return;
        }
        if(root->val != key){
            vec.push_back(root->val);
        }
        dfs(root->left, key);
        dfs(root->right, key);
    }
    TreeNode* insertIntoBST(TreeNode* root, int x) {
        if(root == NULL){
            return new TreeNode(x);
        }
        if(root->val > x){
            root->left = insertIntoBST(root->left, x);
            return root;
        }else{
            root -> right = insertIntoBST(root->right, x);
            return root;
        }
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        dfs(root, key);
        TreeNode* newRoot = NULL;
        for(int i = 0; i < vec.size(); i++){
            newRoot = insertIntoBST(newRoot, vec[i]);
        }
        return newRoot;
    }
};