//normalize index - starting point
//2* i & 2 * i + 1
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

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<unsigned long long, TreeNode* >>q;
        q.push({1, root});
        long long width = 0;
        while(!q.empty()){
            int n = q.size();
            long long mini = INT_MAX;
            long long maxi = INT_MIN;
            long long start = q.front().first;
            for(int i = 0; i < n; i++){
                auto node = q.front();
                q.pop();
                long long index = node.first - start;
                TreeNode* temp = node.second;
                mini = min(mini, index);
                maxi = max(maxi, index);
                if(temp->left){
                    q.push({2 * index ,  temp->left});
                }
                if(temp->right){
                    q.push({2 * index  + 1, temp->right});
                }
            }
            width = max(width, maxi - mini + 1); 
        }
        return (int)width;
    }
};