#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class MaxHeap
{
public:
    int *arr;
    int size;
    // Constructor for the class.
    MaxHeap()
    {
        arr = new int[1000];
        arr[0] = -1;
        size = 0;
    }

    // Implement the function to remove maximum element.
    int extractMaxElement()
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
        int i = 1;
        while (i <= size)
        {
            int curr = i;
            int rightChild = 2 * curr;
            int leftChild = 2 * curr + 1;

            if (leftChild <= size && arr[curr] < arr[leftChild])
            {
                curr = leftChild;
            }
            if (rightChild <= size && arr[curr] < arr[rightChild])
            {
                curr = rightChild;
            }

            if (curr != i)
            {
                swap(arr[curr], arr[i]);
                i = curr;
            }else
            {
                return;
            }
        }
    }

    // Implement the function to insert 'val' in the max heap.
    void insert(int val)
    {
        size++;
        arr[size] = val;
        int temp = size;
        while (temp > 1)
        {
            int parent = temp / 2;
            if (arr[parent] >= arr[temp])
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
};

int main()
{
    MaxHeap maxheap;
    maxheap.insert(10);
    maxheap.insert(20);
    maxheap.insert(30);
    maxheap.insert(40);
    maxheap.insert(50);
    maxheap.insert(60);
    maxheap.insert(70);

    cout << maxheap.extractMaxElement() << endl; //70

    maxheap.deleteElement();
    maxheap.insert(80);

    cout << maxheap.extractMaxElement() << endl; //80
    
    maxheap.deleteElement();
    maxheap.deleteElement();
    cout << maxheap.extractMaxElement() << endl; //50

    return 0;
}