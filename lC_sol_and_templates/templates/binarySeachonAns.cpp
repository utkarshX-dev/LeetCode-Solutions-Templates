#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool isPossible(vector<int>& nums, int mid){
    return 1;// 0 on basis of conditional check
}
int main(){
    vector<int>nums = {1, 2, 3, 4, 5};
    int n = nums.size();
    int s = 0;
    int e = n - 1;
    int res = -1;
    while(s <= e){
        int mid = s + (e - s) / 2;
        if(isPossible(nums, mid)){
            res = mid;
            //move to left or right on basis of problem
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }
    return res;
}