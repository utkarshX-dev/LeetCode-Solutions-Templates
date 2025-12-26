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
    int f(TreeNode* root){
        if(root == NULL) return 0;
        int leftHeight = 0;
        int rightHeight = 0;
        TreeNode* tempLeft = root;
        TreeNode* tempRight = root;
        while(tempLeft || tempRight){
            if(tempLeft){
                leftHeight++;
                tempLeft = tempLeft->left;
            }
            if(tempRight){
                rightHeight++;
                tempRight = tempRight->right;
            }
        }
        if(leftHeight == rightHeight){
            return pow(2, leftHeight) - 1;
        }else{
            return f(root->left) + f(root->right) + 1;
        }
    }
public:
    int countNodes(TreeNode* root) {
        return f(root);
    }
};