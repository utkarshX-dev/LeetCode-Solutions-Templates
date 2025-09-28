//dfs
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution1 {
private:
    map<int, int> m;
    void dfs(TreeNode* root, int depth) {
        if (!root) return;
        if (!m.count(depth)) {
            m[depth] = root->val; // ek baar mil gya toh definitely best solution h kyuki utmost right se hi mila hai
        }
        dfs(root->right, depth + 1); // right first
        dfs(root->left, depth + 1);
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        dfs(root, 0);
        for(auto& x : m){
            res.push_back(x.second);
        }
        return res;
    }
};

//bfs
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        queue<TreeNode* >q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            while(n > 1){
                auto node = q.front();
                q.pop();
                n--;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            auto node = q.front(); //take the rightmost available
            q.pop();
            res.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return res;
    }
};