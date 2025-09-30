#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//IIIDII first D is pivot bs on (III and DII) 
class Solution {
private:
    int bs(int s, int e, int target, vector<int>& arr){
        while(s <= e){
            int mid = s + (e - s )/ 2;
            if(arr[mid] == target){
                return mid;
            }else if(arr[mid] < target){
                s = mid + 1;
            }else{
                e = mid - 1;
            }
        }
        return -1;
    }
    int pivotIdx(vector<int>& nums){
        int n = nums.size(), pivot = -1, s = 0, e = n - 1;
        while (s < e) {
            int mid = s + (e - s) / 2;
            if (nums[0] <= nums[mid]) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }
        return s;
    }
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 1) return nums[0] == target ? 0 : -1;
        int pivot = pivotIdx(nums);
        int res1 = bs(0, pivot - 1, target, nums);
        if(res1 != -1) return res1;
        int res2 = bs(pivot , nums.size() - 1, target, nums);
        if(res2 != -1) return res2;
        return -1;
    }
};