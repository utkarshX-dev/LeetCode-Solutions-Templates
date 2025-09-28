#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

bool isLeaf(TreeNode<int>* root){
    if(root->left || root->right) return false;
    return true;
}

void leftBoundary(TreeNode<int>* root, vector<int>& res){
    if(isLeaf(root)){
        return;
    }
    res.push_back(root->data);
    //push current node data at the beginning
    if(root->left){
        leftBoundary(root->left, res);
    }else if(root->right){
        leftBoundary(root->right, res);
    }
    return;
}

void rightBoundary(TreeNode<int>* root, vector<int>& res){
    if(isLeaf(root)){
        return;
    }
    if(root->right){
        rightBoundary(root->right, res);
    }else if(root->left){
        rightBoundary(root->left, res);
    }
    //push current node data at the end
    //because we are traversing right boundary in reverse order
    res.push_back(root->data);
    return;
}

void traverseLeafNodes(TreeNode<int>* root, vector<int>& res){
    if(isLeaf(root)){
        res.push_back(root->data); //push leaf node data at first we found it
        return;
    }
    if(root->left){
        traverseLeafNodes(root->left, res);
    }
    if(root->right){
        traverseLeafNodes(root->right, res);
    }
    return;
}

void print(vector<int>& res){
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;
}

vector<int> traverseBoundary(TreeNode<int> *root)
{   
    if(root == nullptr) return {};
    vector<int>res;
    res.push_back(root->data); //curr root node
    if(root->left) leftBoundary(root->left, res); //left boundary nodes except leaf nodes
    if(root->left) traverseLeafNodes(root->left, res);
    //leaf nodes in left subtree
    if(root->right) traverseLeafNodes(root->right, res);
    //leaf nodes in right subtree
    if(root->right) rightBoundary(root->right, res);
    //right boundary nodes except leaf nodes
    return res;
}