#include <vector>
#include <iostream>
using namespace std;

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
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<bool>path(V, false);
        vector<bool>visited(V, false);
        vector<vector<int>>adj(V);
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                if(cycleFound(i, visited, path, adj)){
                    return true;
                }
            }
        }
        return false;
    }
};