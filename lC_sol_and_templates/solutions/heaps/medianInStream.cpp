#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
//solution 1 Brute force: sorting each time (TLE)
//solution 2 : Insertion sort
//solution 3 : Using two heaps 🔥


class MedianFinder {
public:
    priority_queue<int>maxheap;
    priority_queue<int, vector<int>, greater<int>>minheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxheap.empty() || maxheap.top() > num){
            maxheap.push(num);
        }else{
            minheap.push(num);
        }

        if(maxheap.size() > minheap.size() + 1){
            minheap.push(maxheap.top());
            maxheap.pop();
        }else if(minheap.size() > maxheap.size()){
            maxheap.push(minheap.top());
            minheap.pop();
        }
        //valid cases
        //maxheap.size() == minheap.size();
        //maxheap.size() = minheap.size() + 1;
    }
    
    double findMedian() {
        if((maxheap.size() + minheap.size()) % 2 == 0){
            return (maxheap.top() + minheap.top()) / 2.0;
        }else{
            return (double) maxheap.top();
        }
    }
};

//insertion sort
class MedianFinder2 {
public:
    vector<int>v;
    int idx;
    MedianFinder2(){
        idx = -1;
    }
    
    void addNum(int num) {
        v.push_back(num);
        idx++;
        int temp = idx;
        while(temp > 0 && v[temp - 1] < v[temp]){
            swap(v[temp], v[temp - 1]);
            temp--;
        }
        //insertion sort
        
    }
    
    double findMedian() {
        int n = v.size(), mid = n / 2;
        if(n % 2 == 0){
            return (v[mid] + v[mid - 1])/2.0;
        }else{
            return v[mid];
        }
    }
};

