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
    unordered_map<int, int> m;
    TreeNode* f(int postStart, int postEnd, int inStart, int inEnd,
                vector<int>& inorder, vector<int>& postorder) {
        if (postStart > postEnd || inStart > inEnd) {
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int idx = m[postorder[postEnd]];
        int rightLen = inEnd - idx;

        root->left = f(postStart, postEnd - rightLen - 1, inStart, idx - 1, inorder, postorder);
        root->right = f(postEnd - rightLen, postEnd - 1, idx + 1, inEnd, inorder, postorder);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            m[inorder[i]] = i;
        }
        return f(0, n - 1, 0, n - 1, inorder, postorder);
    }
};