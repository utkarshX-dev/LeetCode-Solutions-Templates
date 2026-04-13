#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------------
DIFFERENCE ARRAY (ADDITION)
-------------------------------------------------------
We use a diff array to handle range updates in O(1)

Idea:
For query [l, r, val]:
    diff[l] += val
    diff[r+1] -= val   (if within bounds)

Then take prefix sum of diff and add to original array
-------------------------------------------------------
*/
void diffArrayAddition(vector<int>& nums, vector<vector<int>>& queries){
    int n = nums.size();

    // Step 1: Create diff array initialized with 0
    vector<int> diff(n, 0);

    // Step 2: Apply all queries in O(q)
    for(auto& query : queries){
        int l = query[0];
        int r = query[1];
        int val = query[2];

        diff[l] += val;

        // mark end of range
        if(r + 1 < n){
            diff[r + 1] -= val;
        }
    }

    // Step 3: Convert diff → actual increments using prefix sum
    for(int i = 1; i < n; i++){
        diff[i] += diff[i - 1];
    }

    // Step 4: Apply updates to original array
    for(int i = 0; i < n; i++){
        nums[i] += diff[i];
    }
}


/*
-------------------------------------------------------
DIFFERENCE ARRAY (MULTIPLICATION)
-------------------------------------------------------
⚠️ WARNING:
- Works ONLY when:
    1. No zero values involved
    2. Division is exact (no precision loss)

Idea:
For query [l, r, val]:
    diff[l] *= val
    diff[r+1] /= val

Then prefix product and apply to nums
-------------------------------------------------------
*/
void diffArrayMultiplication(vector<int>& nums, vector<vector<int>>& queries){
    int n = nums.size();

    // Use long long to avoid overflow
    vector<long long> diff(n, 1);

    // Step 1: Apply queries
    for(auto& query : queries){
        int l = query[0];
        int r = query[1];
        long long val = query[2];

        diff[l] *= val;

        // reverse effect after r
        if(r + 1 < n){
            diff[r + 1] /= val;  // ⚠️ must divide cleanly
        }
    }

    // Step 2: Prefix product
    for(int i = 1; i < n; i++){
        diff[i] *= diff[i - 1];
    }

    // Step 3: Apply to nums
    for(int i = 0; i < n; i++){
        nums[i] *= diff[i];
    }
}


/*
-------------------------------------------------------
UTILITY FUNCTION TO PRINT ARRAY
-------------------------------------------------------
*/
void printArray(const vector<int>& nums){
    for(int x : nums){
        cout << x << " ";
    }
    cout << "\n";
}


/*
-------------------------------------------------------
MAIN FUNCTION (TESTING)
-------------------------------------------------------
*/
int main() {

    // ----------- ADDITION TEST -----------
    vector<int> nums1 = {1, 2, 3, 4, 5};

    // queries: [l, r, val]
    vector<vector<int>> queries1 = {
        {1, 3, 2},   // add 2 from index 1 to 3
        {0, 2, 1}    // add 1 from index 0 to 2
    };

    diffArrayAddition(nums1, queries1);

    cout << "After Addition Updates:\n";
    printArray(nums1);


    // ----------- MULTIPLICATION TEST -----------
    vector<int> nums2 = {1, 2, 3, 4, 5};

    vector<vector<int>> queries2 = {
        {1, 3, 2},   // multiply by 2 from index 1 to 3
        {0, 2, 3}    // multiply by 3 from index 0 to 2
    };

    diffArrayMultiplication(nums2, queries2);

    cout << "After Multiplication Updates:\n";
    printArray(nums2);

    return 0;
}