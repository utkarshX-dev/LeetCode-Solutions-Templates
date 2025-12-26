#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
class Solution {
  public:
    int minValue(Node* root) {
        if(root->left){
            return minValue(root->left);
        }else{
            return root->data;
        }
    }
    int maxValue(Node* root){
        if(root->right){
            return maxValue(root->right);
        }else{
            return root->data;
        }
    }
};