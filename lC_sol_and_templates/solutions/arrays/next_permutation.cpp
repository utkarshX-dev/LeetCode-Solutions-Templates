#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& arr) {

        // Stores index of pivot element
        // Pivot = first element from right such that:
        // arr[i] < arr[i + 1]
        int pivot = -1;

        int n = arr.size();

        // STEP 1:
        // Find pivot from the right side
        // The suffix after pivot is in descending order
        for(int i = n - 2; i >= 0; i--) {
            if(arr[i] < arr[i + 1]) {
                pivot = i;
                break;
            }
        }

        // STEP 2:
        // If no pivot exists, array is completely descending
        // Example: [5,4,3,2,1]
        // This is the largest permutation,
        // so next permutation will be the smallest one
        if(pivot == -1) {
            reverse(begin(arr), end(arr));
            return;
        }

        // STEP 3:
        // Find the first element from right
        // which is greater than arr[pivot]
        // Since suffix is descending,
        // first greater element gives minimal increase
        for(int i = n - 1; i > pivot; i--) {
            if(arr[i] > arr[pivot]) {
                swap(arr[i], arr[pivot]);
                break;
            }
        }

        // STEP 4:
        // Reverse the suffix to make it smallest possible
        // because currently it is in descending order
        reverse(arr.begin() + pivot + 1, arr.end());
    }
};