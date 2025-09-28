//important variant of monotonic stack
//sum of ranges
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


//important patterns to remember

//nse => n -1 to 0 < 
//pse => 0 to n - 1 <=

//nse or pse mai ek mai <= aur dusre mai <

//pge => 0 to n - 1 <
//nge => n - 1 to 0 <=

//pge or nge mai ek mai < aur dusre mai <=

//n - 1 to 0 if stack empty => n - i else st.top() - i
//0 to n - 1 if stack empty => i + 1 else i - st.top()


class Solution {
private:
    vector<int> findLargest(vector<int>& nums, int n){
        vector<int>pge(n);
        vector<int>nge(n);
        stack<int>st;
        for(int i = 0; i < n; i++){
            int curr = nums[i];
            while(!st.empty() && nums[st.top()] < curr){
                st.pop();
            }
            pge[i] = st.empty() ? i + 1 :  i - st.top();
            st.push(i); 
        }

        while(!st.empty()) st.pop();
        
        for(int i = n - 1; i >= 0; i--){
            int curr = nums[i];
            while(!st.empty() && nums[st.top()] <= curr){
                st.pop();
            }
            nge[i] = st.empty() ? n - i : st.top() - i; 
            st.push(i);
        }

        vector<int>largest(n, 0);
        for(int i = 0; i < n; i++){
            largest[i] = pge[i] * nge[i]; //kitno mai minimum hai = previous mai kitna + next mai kitna
        }
        return largest;
    }
    vector<int> findSmallest(vector<int>& nums, int n){
        vector<int>pse(n);
        vector<int>nse(n);

        stack<int>st;
        for(int i = 0; i < n; i++){
            int curr = nums[i];
            while(!st.empty() && nums[st.top()] >= curr){
                st.pop();
            }
            pse[i] = st.empty() ? i + 1 :  i - st.top();
            st.push(i); 
        }
            

        while(!st.empty()) st.pop();
        
        for(int i = n - 1; i >= 0; i--){
            int curr = nums[i];
            while(!st.empty() && nums[st.top()] > curr){
                st.pop();
            }
            nse[i] = st.empty() ? n - i : st.top() - i; 
            st.push(i);
        }
        
        vector<int>smallest(n, 0);
        for(int i = 0; i < n; i++){
            smallest[i] = pse[i] * nse[i]; //kitno mai maixmum hai = previous mai kitna + next mai kitna
        }
        return smallest;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int>largest = findLargest(nums, n); //koi particular index element kitne subarrays mai maximum hai
        vector<int>smallest = findSmallest(nums, n); //koi particular index element kitne subarrays mai minimum hai
        long long res = 0;
        for(int i = 0; i < n; i++){
            res += (1LL * largest[i] - smallest[i]) * nums[i];
        }
        //res = summation of all (kitno mai largest hai - kitno mai minimum hai) * nums[i] har particular index ka contribution
        return res;
    }
};