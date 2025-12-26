#include <bits/stdc++.h>
#include <iostream>
using namespace std;
template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T dat)
    {
        this->data = dat;
        left = NULL;
        right = NULL;
    }
};
void f(int level, TreeNode<int> *root, map<int, pair<int, int>> &mp, int depth)
{
    if (root == NULL)
        return;
    if (!mp.count(level))
    {
        mp[level] = {root->data, depth};
    }
    else
    {
        if (mp[level].second > depth)
        {
            mp[level] = {root->data, depth};
        }
    }
    if (root->left)
    {
        f(level - 1, root->left, mp, depth + 1);
    }
    if (root->right)
    {
        f(level + 1, root->right, mp, depth + 1);
    }
}
vector<int> getTopView(TreeNode<int> *root)
{
    if (root == NULL) return {};
    map<int, pair<int, int>> mp; // horizonal val depth
    vector<int> res;
    f(0, root, mp, 0);
    for (auto &x : mp)
    {
        res.push_back(x.second.first);
    }
    return res;
}

//method 2 bfs level order traversal
vector<int> getTopView(TreeNode<int> *root)
{
    if (root == NULL) return {};
    map<int, int> mp; // horizonal val depth
    vector<int> res;
    int level = 0;
    queue<pair<TreeNode<int> *, int>> q; // node, level
    q.push({root, level});
    while(!q.empty()){
        int n = q.size();
        while(n > 0){
            auto node = q.front();
            q.pop();
            n--;
            if(!mp.count(node.second)){
                mp[node.second] = node.first->data; // ek baar mil gya toh definitely best solution h kyuki utmost left or right se hi mila hai
            }
            if(node.first->left) q.push({node.first->left, node.second - 1});
            if(node.first->right) q.push({node.first->right, node.second + 1});
        }
    }
    for (auto &x : mp)
    {
        res.push_back(x.second);
    }
    return res;
}