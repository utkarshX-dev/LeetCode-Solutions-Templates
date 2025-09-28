#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

//method 2 
//tc = O(h) (h is the height of the tree in the worst case it can be O(n) for skewed trees)
//sc = O(1) (no extra space is used)
class Solution2 {
  private:
    Node* pred = NULL;
    Node* succ = NULL;
    Node* rightMost(Node* root){
        while(root->right != NULL){
            root = root->right;
        }
        return root;
    }
    Node* leftMost(Node* root){
        while(root->left != NULL){
            root = root->left;
        }
        return root;
    }
    void f(Node* root, int key){
        if(!root){
            return;
        }
        if(root->data > key){
            succ = root;
            f(root->left, key);
        }else if(root->data < key){
            pred = root;
            f(root->right, key);
        }else{
            if (root->left != nullptr)
                pred = rightMost(root->left);
            if (root->right != nullptr)
                succ = leftMost(root->right);
            return;
        }
    }
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
       pred = succ = NULL;
       f(root, key);
       return {pred, succ};
    }
};


//method 3
//tc = O(n) (for inorder traversal in the worst case)
//sc = O(n) (for storing the inorder traversal + recursion stack)
class Solution3
{
private:
    void inorder(vector<Node *> &v, Node *root)
    {
        if (!root)
            return;
        inorder(v, root->left);
        v.push_back(root);
        inorder(v, root->right);
    }

public:
    vector<Node *> findPreSuc(Node *root, int key)
    {
        vector<Node *> v;
        inorder(v, root);
        Node *pred = NULL, *succ = NULL;
        for (int i = 0; i < v.size(); i++)
        {

            if (v[i]->data < key)
            {
                pred = v[i];
            }

            else if (v[i]->data > key)
            {
                succ = v[i];
                break;
            }
        }
        return {pred, succ};
    }
};