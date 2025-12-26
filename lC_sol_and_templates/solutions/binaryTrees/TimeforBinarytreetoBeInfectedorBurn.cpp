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
// Amount of Time for Binary Tree to Be Infected or Burn
//simple graph bfs
class Solution {
public:
    int maxi = -1;
    unordered_map<int, vector<int>>adj;
    void dfs(TreeNode* root){
        if(root == NULL) return;
        maxi = max(maxi, root->val);
        if(root->left){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            dfs(root->left);
        }
        if(root->right){
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
            dfs(root->right);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        dfs(root);
        vector<int>time(maxi + 1, INT_MAX);
        
        int minTime = 0;
        time[start] = 0;
        queue<pair<int, int>>q;
        q.push({time[start], start});
        
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                auto temp = q.front();
                q.pop();
                int currTime = temp.first;
                int node = temp.second;
                vector<int>& nbrs = adj[node];
                for(int& nbr : nbrs){
                    if(time[nbr] > currTime + 1){
                        time[nbr] = currTime + 1;
                        minTime = max(minTime, time[nbr]);
                        q.push({time[nbr], nbr});
                    }
                }
            }
        }
        return minTime;
    }
};