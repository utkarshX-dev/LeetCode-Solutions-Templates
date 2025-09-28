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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode* >q;
        vector<vector<int>> res;
        bool toggle = false;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int>curr;
            for(int i = 0; i < size; i++){
                TreeNode* temp = q.front();
                curr.push_back(temp->val);
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(toggle){
                reverse(curr.begin(), curr.end());
            }
            toggle = !toggle;
            res.push_back(curr);
        }
        return res;
    }
};