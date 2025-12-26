#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
//brute force approach
//time complexity: O(n^2)
//space complexity: O(h) 
class Solution {
  public:
    int largest = 1;
    bool validateBST(Node* root, long long maxi, long long mini){
        if(!root){
            return true;
        }
        if(maxi <= root->data || mini >= root->data){
            return false;
        }
        return validateBST(root->left, root->data, mini) && validateBST(root->right, maxi, root->data);
    }
    
    int countNodes(Node* root){
        if(!root){
            return 0;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    void solve(Node* root){
        if(!root) return;
        if(validateBST(root, LLONG_MAX, LLONG_MIN)){
            largest = max(largest, countNodes(root));
        }
        solve(root->left);
        solve(root->right);
    }
    int largestBst(Node *root) {
        solve(root);
        return largest;
    }
};

//OPTIMISED APPROACH
//time complexity: O(n)
//space complexity: O(h)
class nodevalue{
    public:
    int maxVal;
    int minVal;
    bool isValidBST;
    int size;

    nodevalue(int maxVal,int minVal,int size, bool isValidBST){
        this->size = size;
        this->maxVal = maxVal;
        this->minVal = minVal;
        this->isValidBST = isValidBST;
    }
};

nodevalue* solve(TreeNode* root){
    if(!root){
        return new nodevalue(INT_MIN, INT_MAX, 0, true);
    }
    if(!root->left && !root->right){
        return new nodevalue(root->data, root->data, 1, true);
    }   
    nodevalue* left = solve(root->left);
    nodevalue* right = solve(root->right);
    if(left->isValidBST && right->isValidBST && left->maxVal < root->data && root->data < right->minVal){
        return new nodevalue(max(left->maxVal, root->data), min(left->minVal, root->data), 1 + left->size + right->size, true);
    }else{
        return new nodevalue(INT_MAX, INT_MIN, max(left->size, right->size) ,false);
    }
}

int largestBST(TreeNode * root){
    return solve(root)->size;
}