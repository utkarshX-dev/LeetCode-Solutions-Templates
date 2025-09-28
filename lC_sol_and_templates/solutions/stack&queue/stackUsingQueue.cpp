#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//using 1 queue
class MyStack {
public:
    queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
        int n = q.size();
        q.push(x);
        for(int i = 0; i < n; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.size() == 0;
    }
};
//using 2 queues
class MyStack2 {
public:
queue<int>q1;
queue<int>q2;
    MyStack2() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while(q1.size() != 1){
            q2.push(q1.front());
            q1.pop();
        }
        int val = q1.front();
        q1.pop();
        while(q2.size() != 0){
            q1.push(q2.front());
            q2.pop();
        }
        return val;
    }
    
    int top() {
         while(q1.size() != 1){
            q2.push(q1.front());
            q1.pop();
        }
        int val = q1.front();
        q2.push(val);
        q1.pop();
        while(q2.size() != 0){
            q1.push(q2.front());
            q2.pop();
        }
        return val;
    }
    
    bool empty() {
        return q1.empty();
    }
};

