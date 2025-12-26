#include <iostream>
#include <vector>
#include <map>
#include <queue>
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
};

vector<int> bottomView(TreeNode<int> *root)
{
    if (root == NULL)
        return {};
    map<int, int> mp; // horizonal val depth
    vector<int> res;
    int level = 0;
    queue<pair<TreeNode<int> *, int>> q; // node, level
    q.push({root, level});
    while (!q.empty())
    {
        int n = q.size();
        while (n > 0)
        {
            auto node = q.front();
            q.pop();
            n--;
            mp[node.second] = node.first->data; //change to overwrite the value at this level
            if (node.first->left)
                q.push({node.first->left, node.second - 1});
            if (node.first->right)
                q.push({node.first->right, node.second + 1});
        }
    }
    for (auto &x : mp)
    {
        res.push_back(x.second);
    }
    return res;
}
