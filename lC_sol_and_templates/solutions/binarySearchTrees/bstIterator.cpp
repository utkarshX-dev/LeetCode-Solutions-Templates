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
class BSTIterator {
public:
    stack<TreeNode* >st;
    void pushAllLeft(TreeNode* root){
        while(root != NULL){
            st.push(root);
            root = root->left;
        }
    }
    BSTIterator(TreeNode* root) {
        pushAllLeft(root);
    }
    
    int next() {
        TreeNode* node = st.top();
        st.pop();
        pushAllLeft(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return st.size() > 0;
    }
};