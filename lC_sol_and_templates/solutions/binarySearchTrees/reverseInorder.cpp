//if left->node->right then ascending order [inorder traversal]
//if right->node->left then descending order [reverse inorder traversal]
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
    void reverseInorder(TreeNode* root, vector<int>& result) {
        if (root == NULL) return;
        
        // Traverse the right subtree first
        
        reverseInorder(root->right, result);
        // Visit the current node
        result.push_back(root->val);
        
        // Traverse the left subtree
        reverseInorder(root->left, result);
    }
    
    vector<int> getReverseInorder(TreeNode* root) {
        vector<int> result;
        reverseInorder(root, result);
        return result;
    }
};
void print(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}
int main(){
    //create a example binary search tree
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    Solution sol;
    vector<int> result = sol.getReverseInorder(root);
    print(result);  
    return 0;
}
