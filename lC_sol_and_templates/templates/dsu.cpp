#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class disjointSet{
private:
    vector<int>rank, parent, size;
public:
    //constructor
    disjointSet(int n){
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
        
    }

    //t.c = O(4alpha) or constant & includes path compression
    int findUltimateParent(int node){
        if(node == parent[node]){
            return node;
        }
        else{
            return parent[node] = findUltimateParent(parent[node]);
        }
    }
    
    //union by rank 
    //t.c = O(4alpha) 
    void unionByrank(int u, int v){
        int ult_u_Parent = findUltimateParent(u);
        int ult_v_Parent = findUltimateParent(v);
        if(ult_u_Parent == ult_v_Parent) return;
        if(rank[ult_u_Parent] < rank[ult_v_Parent]){
            parent[ult_u_Parent] = ult_v_Parent;
        }
        else if(rank[ult_v_Parent] < rank[ult_u_Parent]){
            parent[ult_v_Parent] = ult_u_Parent;
        }
        else{
            parent[ult_u_Parent] = ult_v_Parent; //case of no parent,parent = node same rank
            rank[ult_v_Parent]++; 
        }
    }

    void unionBySize(int u, int v){
        int ult_u_Parent = findUltimateParent(u);
        int ult_v_Parent = findUltimateParent(v);
        if(ult_u_Parent == ult_v_Parent) return;
        if(size[ult_u_Parent] < size[ult_v_Parent]){
            parent[ult_u_Parent] = ult_v_Parent;
            size[ult_v_Parent] += size[ult_u_Parent];
        }
        else{
            parent[ult_v_Parent] = ult_u_Parent;
            size[ult_u_Parent] += size[ult_v_Parent];
        }
    }

};

int main(){
    disjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionByrank(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    ds.unionBySize(3, 7);//without this ds.unionByrank(3, 7) => they don't belong to same component
    
    //check if 3 and 7 belong to same component;
    if(ds.findUltimateParent(1) == ds.findUltimateParent(4)){
        cout << "Belong to same component.\n";
    }
    else{
        cout << "Not part of same component.\n";
    }
    
    return 0;
}