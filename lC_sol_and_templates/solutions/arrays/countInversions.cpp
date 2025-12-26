//a inversion if an array is a pair of indices (i, j) such that i < j and arr[i] > arr[j].
//approach : merge sort
//time complexity : O(nlogn)
//space complexity : O(n)
#include <vector>
using namespace std;
class Solution {
  public:
    private:
    int merge(int s, int mid, int e, vector<int>&arr){
        int i = s;
        int j = mid + 1;
        vector<int>temp;
        int inversions = 0;
        while(i <= mid && j <= e){
            if(arr[i] <= arr[j]){
                temp.push_back(arr[i]);
                i++;
            }
            else{
                inversions += mid - i + 1;
                temp.push_back(arr[j]);
                j++;
            }
        }
        while(i <= mid){
            temp.push_back(arr[i]);
            i++;
        }
        while(j <= e){
            temp.push_back(arr[j]);
            j++;
        }
        i = s;
        for(auto& x : temp){
            arr[i] = x;
            i++;
        }
        return inversions;
    }
  public:
    int mergeSort(vector<int>& arr, int s, int e) {
        if(s >= e){
            return 0;
        }
        int res = 0;
        int mid = s + (e - s) / 2; 
        res += mergeSort(arr, s, mid);
        res += mergeSort(arr, mid + 1, e);
        res += merge(s, mid, e, arr);
        return res;
    }
    int inversionCount(vector<int> &nums){
        return mergeSort(nums, 0, nums.size() - 1);
    } 
};