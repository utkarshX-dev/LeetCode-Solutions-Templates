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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        
        while (root != NULL) {
            res.push_back(root->val);
            
            if (!root->left) {
                root = root->right;
            } else {
                TreeNode* temp = root->left;
                
                // Find the rightmost node of the left subtree
                while (temp->right) {
                    temp = temp->right;
                }

                // Attach root->right to rightmost node's right (NOT left!)
                temp->right = root->right;

                // Move left and nullify right
                root->right = NULL;
                root = root->left;
            }
        }
        return res;
    }
};
