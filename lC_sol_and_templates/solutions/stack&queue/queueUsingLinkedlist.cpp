#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node* next) : data(x), next(next) {}
};

struct Queue {
    Node* front;
    Node* rear;
    Queue() {
        front = rear = nullptr;
    }
    void push(int x);
    int pop();
};

void Queue::push(int x) {
    Node* newNode = new Node(x);
    if(front == nullptr){
        front = newNode;
        rear = newNode;
    }
    else{
        rear->next = newNode;
        rear = rear->next;
    }
}

int Queue::pop() {
    if(front == nullptr) return -1;
    int curr = front->data;
    front = front->next;
    return curr;
}