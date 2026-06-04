// Problem Description
// You are given two nodes p and q from a binary tree where each node has a reference to its parent node. Your task is to find their lowest common ancestor (LCA).

// The node structure includes:

// val: the value of the node
// left: pointer to the left child
// right: pointer to the right child
// parent: pointer to the parent node
// The lowest common ancestor is defined as the lowest node in the tree that has both p and q as descendants. Note that a node can be considered a descendant of itself.    

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* p, TreeNode* q) {
        // Use a hash set to store all ancestors of node p
        unordered_set<TreeNode*> visitedAncestors;

        // Traverse from node p to root, storing all ancestors
        for (TreeNode* currentNode = p; currentNode != nullptr; currentNode = currentNode->parent) {
            visitedAncestors.insert(currentNode);
        }

        // Traverse from node q to root
        // The first node that exists in p's ancestors is the LCA
        for (TreeNode* currentNode = q; currentNode != nullptr; currentNode = currentNode->parent) {
            if (visitedAncestors.count(currentNode)) {
                return currentNode;
            }
        }

        // This line should never be reached if inputs are valid
        return nullptr;
    }
};
