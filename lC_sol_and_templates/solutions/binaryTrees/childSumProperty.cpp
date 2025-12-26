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
//sum of values of left and right child should be equal to parent node value
//if not, then we need to change the value of parent node or child nodes

//questions1: validate the child sum property
class Solution {
private:
    bool f(TreeNode* root){
    if(!root) return true;
    if(!root->right && !root->left){
        return true;
    }
    int sum = 0;
    if(root->left) sum += root->left->val;
    if(root->right) sum += root->right->val;
    return sum == root->val && f(root->left) && f(root->right);
}
public:
    bool checkTree(TreeNode* root) {
        return f(root);
    }
};

//questions2: change the value of parent node or child nodes to satisfy the child sum property
class Solution2 {
private:
 void f(TreeNode* root) {
    if (!root) return;
    int childSum = 0;
    if (root->left) childSum += root->left->val;
    if (root->right) childSum += root->right->val;

    if (childSum < root->val) {
        if (root->left) root->left->val = root->val;
        if (root->right) root->right->val = root->val;
    }
    f(root->left);
    f(root->right);
    int total = 0;
    if (root->left) total += root->left->val;
    if (root->right) total += root->right->val;
    if (root->left || root->right) root->val = total;
}

public:
    TreeNode* makeChildSumPropertyValid(TreeNode* root) {
        if(!root) return root;
        if(!root->right && !root->left){
            return root;
        }
        f(root);
        return root;
    }
};
TreeNode* createTestTree() {
    //      10
    //     /  \
    //    8    2
    //   / \    \
    //  3   5    2
    TreeNode* root = new TreeNode(100);
    root->left = new TreeNode(8);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(2);
    return root;
}

void printLevelOrder(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; ++i) {
            TreeNode* node = q.front(); q.pop();
            cout << node->val << " ";
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << endl;
    }
}

int main() {
    TreeNode* root = createTestTree();
    cout << "Original tree (level order):" << endl;
    printLevelOrder(root);

    Solution sol;
    cout << "Child sum property valid? " << (sol.checkTree(root) ? "Yes" : "No") << endl;

    Solution2 sol2;
    TreeNode* newRoot = sol2.makeChildSumPropertyValid(root);
    cout << "Tree after enforcing child sum property:" << endl;
    printLevelOrder(newRoot);
    return 0;
}