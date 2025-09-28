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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if ((p == NULL && q != NULL) || (p != NULL && q == NULL)) {
            return false;
        }
        if(p == NULL &&  q == NULL) return true;
        bool curr = (p->val == q->val);
        if (!curr) {
            return false;
        }
        bool leftCheck = isSameTree(p->left, q->left);
        if (!leftCheck) {
            return false;
        }
        bool rightCheck = isSameTree(p->right, q->right);
        return curr && leftCheck && rightCheck;
    }
};