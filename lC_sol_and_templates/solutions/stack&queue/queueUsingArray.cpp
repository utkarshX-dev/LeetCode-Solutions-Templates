#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Queue {

	int front, rear, cnt, size;
	vector<int> arr;

public:
	Queue()
	{
		cnt = 0;
		size = 100001;
		front = 0;
		rear = 0;
		arr.resize(100001);
	}

	// Enqueue (add) element 'e' at the end of the queue.
	void enqueue(int e){
		if(cnt != size){
			arr[rear % size] = e;
			rear++;
			cnt++;
		}
	}

	// Dequeue (retrieve) the element from the front of the queue.
	int dequeue(){
		if(cnt == 0) return -1;
		else{
			int val = arr[front];
			front = (front + 1) % size;
			cnt--;
			return val;
		}
	}
};