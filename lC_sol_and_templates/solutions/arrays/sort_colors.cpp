#include <bits/stdc++.h>
using namespace std;
//two pass solution
class Solution {
public:
    void sortColors(vector<int>& nums) {
        //sort (0,1) & 2
        int i = 0, j = nums.size() - 1;
        while(i < j){
            if(nums[j] == 2) j--;
            else if(nums[i] == 1 || nums[i] == 0) i++;
            else{
                swap(nums[i], nums[j]);
                i++, j--;
            }
        }
        if(nums[j] == 2) j--;
        i = 0;
        while(i < j){
            if(nums[j] == 1) j--;
            else if(nums[i] == 0) i++;
            else{
                swap(nums[i], nums[j]);
                i++, j--;
            }
        }
        //sort 0 & 1
    }
};
//one pass solution
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;
        
        while (mid <= high) {
                if (nums[mid] == 0) {
                    swap(nums[mid], nums[low]);
                    low++;
                    mid++;
                } 
            else if (nums[mid] == 1) {
                mid++;
            } 
            else { // nums[mid] == 2
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
