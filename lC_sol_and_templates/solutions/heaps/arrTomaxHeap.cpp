#include <iostream>
#include <vector>
using namespace std;
void heapify(vector<int>& arr, int i, int size){
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        int greatest = i;
        if(leftChild < size && arr[leftChild] > arr[greatest]){
            greatest = leftChild;
        }
        if(rightChild < size && arr[rightChild] > arr[greatest]){
            greatest = rightChild;
        }
        if(greatest != i){
            swap(arr[greatest], arr[i]);
            heapify(arr, greatest, size);
        }else{
            return;
        }
    }
vector<int>MinToMaxHeap(int n, vector<int>&nums)
{
	// Write your code here.
    for(int i = n/2; i >=0; i--){
        heapify(nums, i, n);
    }
    return nums;
}