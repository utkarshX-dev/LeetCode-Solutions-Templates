#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root)
            return "#,";

        string result;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr) {
                result += to_string(curr->val) + ",";
                q.push(curr->left);
                q.push(curr->right);
            } else {
                result += "#,";
            }
        }

        return result;
    }

    TreeNode* deserialize(string data) {
        int n = data.size();
        int idx = 0;

        // Read the root value
        string temp = "";
        while (idx < n && data[idx] != ',') {
            temp.push_back(data[idx]);
            idx++;
        }

        if (temp == "#") return NULL;
        idx++; // Skip the comma

        TreeNode* root = new TreeNode(stoi(temp));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();

            // Parse left
            string leftVal = "";
            while (idx < n && data[idx] != ',') {
                leftVal.push_back(data[idx]);
                idx++;
            }
            idx++; // Skip comma
            if (leftVal != "#") {
                TreeNode* leftNode = new TreeNode(stoi(leftVal));
                node->left = leftNode;
                q.push(leftNode);
            }

            // Parse right
            string rightVal = "";
            while (idx < n && data[idx] != ',') {
                rightVal.push_back(data[idx]);
                idx++;
            }
            idx++; // Skip comma
            if (rightVal != "#") {
                TreeNode* rightNode = new TreeNode(stoi(rightVal));
                node->right = rightNode;
                q.push(rightNode);
            }
        }

        return root;
    }
};
