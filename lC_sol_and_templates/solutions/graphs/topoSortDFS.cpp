#include <bits/stdc++.h>
using namespace std;
class Solution {
  private:
    stack<int>st;
    vector<vector<int>>adj;
    vector<bool>visited;
    void topoSort(int i){
        visited[i] = true;
        for(int& nbr : adj[i]){
            if(!visited[nbr]){
                topoSort(nbr);
            }
        }
        st.push(i);
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        adj.resize(V);
        visited.resize(V, false);
        for(auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
        }
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                topoSort(i);
            }
        }
        
        vector<int>res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};