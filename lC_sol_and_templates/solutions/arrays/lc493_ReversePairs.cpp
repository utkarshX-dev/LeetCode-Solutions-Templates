//a inversion if an array is a pair of indices (i, j) such that i < j and arr[i] > arr[j].
//approach : merge sort
//time complexity : O(nlogn)
//space complexity : O(n)
#include <vector>
using namespace std;
class Solution {
private:
    int merge(vector<int>& nums, int s, int mid, int e){
        int pairs = 0;
        int i = s;
        int j = mid + 1;
        while(j <= e && i <= mid){
            if(nums[i] > (long long)2 * nums[j]){
                pairs += mid - i + 1;
                j++;
            }
            else{
                i++;
            }
        }

        vector<int>temp;
        int low = s;
        int high = mid + 1;
        
        while(low <= mid && high <= e){
            if(nums[low] <= nums[high]){
                temp.push_back(nums[low++]);
            }
            else{
                temp.push_back(nums[high++]);
            }
        }

        while(low <= mid){
            temp.push_back(nums[low++]);
        }
        while(high <= e){
            temp.push_back(nums[high++]);
        }
        
        low = s;
        for(auto& x: temp){
            nums[low++] = x;
        }
        return pairs;
    }

    int mergeSort(vector<int>& nums, int s, int e){
        if(s >= e) return 0;
        int mid = s + (e - s )/ 2;
        int res = 0;
        res += mergeSort(nums, s, mid);
        res += mergeSort(nums, mid + 1, e);
        res += merge(nums, s, mid, e);
        return res;
    }
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};