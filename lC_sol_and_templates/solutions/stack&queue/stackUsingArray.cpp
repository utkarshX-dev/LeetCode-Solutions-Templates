#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Stack {
private:
    int *arr;
    int topIdx;
    int size;
public:
    
    Stack(int capacity) {
        size = capacity;
        arr = new int[capacity];
        topIdx = -1;
    }

    void push(int num) {
        if(topIdx != size - 1){
            topIdx++;
            arr[topIdx] = num;
        }
    }

    int pop() {
        if(topIdx != -1){
            int val = arr[topIdx];
            topIdx--;
            return val;
        }else{
            return -1;
        }
    }
    
    int top() {
        if(topIdx != -1){
            return arr[topIdx];
        }else return -1;
    }
    
    int isEmpty() {
        if(topIdx == -1){
            return 1;
        }else return 0;
    }
    
    int isFull() {
       if(topIdx == size - 1){
           return 1;
       }else return 0;
    }
};
