#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node{
 public:
    int val;
    Node* next;
        
 Node(int val){
    this->val = val;
    this->next = nullptr;
  }
};
class MyStack {
  public:
    Node *head;
    MyStack(){
        head = new Node(-1);
    }
    
    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
    }

    int pop() {
        if(head->val == -1){
            return -1;
        }else{
            Node* temp = head;
            int val = temp->val;
            head = head->next;
            delete temp;
            return val;
        }
        
    }
};