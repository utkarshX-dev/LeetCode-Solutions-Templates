#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class NumArray {
private:
    vector<int>segment, nums;
    int n;
    void builtTree(int i, int l, int r){
        if(l == r){
            segment[i] = nums[l];
            return;
        }

        int mid = l + (r - l) / 2;
        
        builtTree(2 * i + 1, l , mid);
        builtTree(2 * i + 2, mid + 1 , r);
        
        segment[i] = segment[2 * i + 1] + segment[2 * i + 2];
    }

    void update(int idx, int val, int l, int r, int i){
        if(l == r){
            segment[i] = val;
            return;
        }
        int mid = l + (r - l) / 2;
        if(idx <= mid){
            update(idx, val, l, mid, 2 * i + 1);
        }else{
            update(idx, val, mid + 1, r, 2 * i + 2);
        }
        segment[i] = segment[2 * i + 1] + segment[2 * i + 2];
    }

    int rangeSum(int l, int r, int s, int e, int i){
        if(r < s || e < l){
            return 0;
        }else if(s <= l && r <= e){
            return segment[i];
        }else{
            int mid = l + (r - l)/2;
            return rangeSum(l, mid, s, e, 2 * i + 1) + rangeSum(mid + 1, r, s, e, 2 * i + 2); 
        }
    }
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        this->nums = nums;
        segment.resize(4 * n, -1);
        builtTree(0, 0, n - 1);
    }
    
    void update(int index, int val) {
        update(index, val, 0, n - 1, 0);
    }
    
    int sumRange(int left, int right) {
        return rangeSum(0, n - 1,left, right, 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */