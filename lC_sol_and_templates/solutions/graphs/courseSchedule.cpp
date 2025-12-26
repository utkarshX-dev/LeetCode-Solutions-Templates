#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//method 1 similar to detect cycle in directed graph
class Solution {
private:
    bool cycleFound(int i, vector<bool>& visited, vector<bool>& path, vector<vector<int>>& adj){
        path[i] = true;
        visited[i] = true;
        
        for(int& nbr : adj[i]){
            if(!visited[nbr]){
                if(cycleFound(nbr, visited, path, adj)){
                    return true;
                }
            }
            if(path[nbr]){
                return true;
            }
        }
        
        path[i] = false;
        return false;
    }
public:
    bool canFinish(int V, vector<vector<int>>& edges) {
        vector<bool>path(V, false);
        vector<bool>visited(V, false);
        vector<vector<int>>adj(V);
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                if(cycleFound(i, visited, path, adj)){
                    return false;
                }
            }
        }
        return true;
    }
};


//method 2 topological sort BFS
class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& edges) {
        vector<vector<int>>adj(V);
        vector<int>indegree(V, 0);
        for(auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        
        queue<int>q;
        
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        int cnt = 0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            cnt++;
            for(int& nbr : adj[curr]){
                indegree[nbr]--;
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
        return cnt == V;;
    }
};

//method 3 topological sort DFS dont go through this 

