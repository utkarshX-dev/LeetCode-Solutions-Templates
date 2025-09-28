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
    unordered_map<int, int>m;
    TreeNode* f(int preStart, int preEnd, int inStart, int inEnd, vector<int>& preorder, vector<int>& inorder){
        if(preStart > preEnd || inStart > inEnd){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[preStart]);
        int idx = m[preorder[preStart]];
        int leftLen = idx - inStart;
        root->left = f(preStart + 1, preStart + leftLen, inStart, idx - 1, preorder, inorder);
        root->right = f(preStart + leftLen + 1, preEnd, idx + 1, inEnd, preorder ,inorder); 
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for(int i = 0; i < n; i++){
            m[inorder[i]] = i;
        }
        return f(0, n - 1, 0, n - 1, preorder, inorder);
    }
};