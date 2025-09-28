#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
private:
    unordered_map<int, Node*> adj;
    void dfs(Node* node) {
        if (adj.count(node->val)) return;
        adj[node->val] = new Node(node->val);
        for (auto nbr : node->neighbors) {
            dfs(nbr); //first dfs cause to ensure that node must exist
            adj[node->val]->neighbors.push_back(adj[nbr->val]);
        }
    }
public:
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        dfs(node);
        return adj[1];
    }
};