#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int>segmentTree;
void builtTree(int i, int l, int r, vector<int>& nums){
    if(l == r){
        segmentTree[i] = nums[r];
        return;
    }
    int mid = l + (r - l) / 2;
    builtTree(2 * i + 1, l, mid, nums);
    builtTree(2 * i + 2, mid + 1, r, nums);
    segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2]; 
}

void update(int i, int l, int r, int idx, int val){
    if(l == r){
        segmentTree[i] = val;
        return;
    }
    int mid = l + (r - l) / 2;
    if(idx <= mid){
        //left mai jao
        update(2 * i + 1, l, mid, idx, val);
    }else{
        //right mai jao
        update(2 * i + 2, mid + 1, r, idx, val);
    }
     segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2]; 
}

void print(vector<int>& v, int n){
    for(int i = 0; i < 2 * n; i++){
        cout << segmentTree[i] << " "; 
    }
    cout << endl;
}

int main(){
    vector<int>nums = {3, 1, 2, 7};
    int n = nums.size();
    segmentTree.resize(2 * n, -1);
    builtTree(0, 0, n - 1, nums);
    print(segmentTree, n);
    update(0, 0, n - 1,  1, 2);
    print(segmentTree, n);
    
    return 0;
}