#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class MinHeap
{
public:
    int *arr;
    int size;
    // Constructor for the class.
    MinHeap()
    {
        arr = new int[1000];
        arr[0] = -1;
        size = 0;
    }

    // Implement the function to remove minimum element.
    int extractMinElement()
    {
        if (size >= 1)
        {
            return arr[1];
        }
        else
        {
            cout << "Heap is empty" << endl;
            return -1;
        }
    }

    // Implement the function to delete an element.
    void deleteElement()
    {
        if (size < 1)
        {
            return;
        }
        swap(arr[1], arr[size]);
        size--;
        heapify(1);
    }

    // Implement the function to insert 'val' in the min heap.
    void insert(int val)
    {
        size++;
        arr[size] = val;
        int temp = size;
        while (temp > 1)
        {
            int parent = temp / 2;
            if (arr[parent] <= arr[temp])
            {
                return;
            }
            else
            {
                swap(arr[parent], arr[temp]);
                temp = parent;
            }
        }
    }
    // heapify algorithm
    void heapify(int index){
        int leftChild = 2 * index;
        int rightChild = 2 * index + 1;
        int smallest = index;

        if (leftChild <= size && arr[leftChild] < arr[smallest]) {
            smallest = leftChild;
        }
        if (rightChild <= size && arr[rightChild] < arr[smallest]) {
            smallest = rightChild;
        }
        if (smallest != index) {
            swap(arr[index], arr[smallest]);
            heapify(smallest);
        }
    }
};

int main()
{
    MinHeap minheap;
    minheap.insert(10);
    minheap.insert(20);
    minheap.insert(30);
    minheap.insert(40);
    minheap.insert(50);
    minheap.insert(60);
    minheap.insert(70);

    cout << minheap.extractMinElement() << endl;

    minheap.deleteElement();
    minheap.insert(80);
    minheap.insert(5);

    cout << minheap.extractMinElement() << endl;
    return 0;
}