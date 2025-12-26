#include <iostream>
#include <bits/stdc++.h>
using namespace std;


//Approach case1 [nums] normal kadane sum
//case2 [sum1, minsum, sum2] find minsum-> totalsum - minsum
//return max(case1, case2) 
// ** edge case: if minsum = whole array sum(totalSum) return normal sum 


//one pass solution
class Solution2 {
private:
    pair<int, pair<int, int>> kadaneMaxMinSum(vector<int>& nums){
        int totalSum = 0;
        int currSum = 0;
        int maxSum = INT_MIN;
        int currminSum = 0, minSum = 0;
        for(int& x : nums){
            currSum += x;
            maxSum = max(maxSum, currSum);
            if(currSum < 0){
                currSum = 0;
            }
            currminSum += x;
            minSum = min(minSum, currminSum);
            if(currminSum > 0){
                currminSum = 0;
            }
            totalSum += x;
        }
        return {totalSum, {maxSum, minSum}};
    }
    
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        auto curr = kadaneMaxMinSum(nums);
        int totalSum = curr.first, normalSum = curr.second.first, minSum = curr.second.second;
        if(totalSum == minSum) return normalSum;
        return max(totalSum - minSum, normalSum);
    }
};

//two pass solution
class Solution {
private:
    pair<int, int> kadaneMaxSum(vector<int>& nums){
        int totalSum = 0;
        int currSum = 0;
        int maxSum = INT_MIN;
        for(int& x : nums){
            currSum += x;
            maxSum = max(maxSum, currSum);
            if(currSum < 0){
                currSum = 0;
            }
            totalSum += x;
        }
        return {totalSum, maxSum};
    }
    int kadaneMinSum(vector<int>& nums){
        int currSum = 0, minSum = 0;
         for(int& x : nums){
            currSum += x;
            minSum = min(minSum, currSum);
            if(currSum > 0){
                currSum = 0;
            }
        }
        return minSum;
    }
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        auto curr = kadaneMaxSum(nums);
        int totalSum = curr.first, normalSum = curr.second;
        int minSum = kadaneMinSum(nums);
        if(totalSum == minSum) return normalSum;
        return max(totalSum - minSum, normalSum);
    }
};

