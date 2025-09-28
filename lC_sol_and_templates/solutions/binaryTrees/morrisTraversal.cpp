#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// this would change the tree structure
// t.c : O(n)
// s.c : O(1)

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        TreeNode *curr = root;
        vector<int> res;
        while (curr != NULL)
        {
            if (curr->left)
            {
                TreeNode *temp = curr->left;
                while (temp->right != nullptr)
                {
                    temp = temp->right;
                }
                temp->right = curr;
                temp = curr;
                curr = curr->left;
                temp->left = nullptr; // remove old left link so that it don't go in loop
            }
            else
            {
                res.push_back(curr->val);
                curr = curr->right;
            }
        }
        return res;
    }
};

//method 2: without changing the tree structure
class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        vector<int>res;
        while(curr != NULL){
            if(curr->left){
                //two cases already visited left subtree or not
                TreeNode* temp = curr;
                temp = curr->left;
                while(temp->right != NULL && temp->right != curr){
                    temp = temp->right;
                }
                if(temp->right == curr){ //thread exists
                    temp->right = nullptr; //remove thread
                    res.push_back(curr->val); //put backtrack value in res
                    curr = curr->right;
                }else{
                    temp->right = curr;
                    curr = curr->left;
                }
            }
            else{
                res.push_back(curr->val);
                curr = curr->right;
                //if thread exists it will backtrack like recur else curr got null making the traveral to end
            }
            
        }
        return res;
    }
};