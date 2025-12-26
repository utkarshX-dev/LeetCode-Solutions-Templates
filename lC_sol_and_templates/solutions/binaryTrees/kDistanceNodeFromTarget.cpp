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
//dijkstra's variant for tree
class Solution {
private:
    vector<vector<int>> adj;
    void createAdj(TreeNode* root){
        if(root == NULL) return;
        if(root->left){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            createAdj(root->left);
        }
        if(root->right){
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
            createAdj(root->right);
        }
    }
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        adj.resize((501));
        createAdj(root);

        vector<int> dist(501, INT_MAX);
        dist[target->val] = 0;
        
        queue<pair<int, int>> q;  //monotonic queue no pq needed 
        q.push({0, target->val}); // distance node
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int currDist = temp.first;
            int node = temp.second;
            if(currDist > k) break;
            for(int& nbs : adj[node]){
                if(dist[nbs] > currDist + 1){
                    dist[nbs] = currDist + 1;
                    q.push({dist[nbs], nbs});
                }
            }
        }

        vector<int>res;
        for(int i = 0; i <= 500; i++){
            if(dist[i] == k){
                res.push_back(i);
            }
        }
        return res;
    }
};