#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//dfs solution 
// T.C: O(N) traversing + O(n * (nlog + n))
// S.C: map O(horizonalLengthoftree * horizonalLengthoftree) + O(N) recursion stack
class Solution2 {
private:
    map<int, vector<pair<int, int>>> m;
    void f(int level, TreeNode* root, int depth) {
        if (root == nullptr) {
            return;
        }
        m[level].push_back({depth, root->val});
        if (root->left) {
            f(level - 1, root->left, depth + 1);
        }
        if (root->right) {
            f(level + 1, root->right, depth + 1);
        }
        return;
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        f(0, root, 0);
        vector<vector<int>> res;
        for (auto& x : m) {
            sort(x.second.begin(), x.second.end());
            vector<int> curr;
            for(pair<int, int>& temp : x.second){
                curr.push_back(temp.second);
            }
            res.push_back(curr);
        }
        return res;
    }
};

//bfs 
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return {};
        int level = 0;
        queue<pair<TreeNode* , int>>q;
        q.push({root, 0});
        map<int, vector<pair<int, int>>>m;
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                auto node = q.front();
                q.pop();
                m[node.second].push_back({level, node.first->val});
                if(node.first->left){
                    q.push({node.first->left, node.second - 1});
                }
                if(node.first->right){
                    q.push({node.first->right, node.second + 1});
                }
            }
            level++;
        }
        vector<vector<int>> res;
        for (auto& x : m) {
            vector<int> curr;
            sort(x.second.begin(), x.second.end());
            for(auto& temp : x.second){
                curr.push_back(temp.second);
            }
            res.push_back(curr);
        }
        return res;
    }
};