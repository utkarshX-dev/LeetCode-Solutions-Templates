#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//convert to max heap
void print(vector<int>& arr, int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
void heapify(vector<int>& arr, int n, int i){
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;
    int largest = i;
    if(leftChild < n - 1 && arr[leftChild] > arr[largest]){
        largest = leftChild;
    }
    if(rightChild < n - 1 && arr[rightChild] > arr[largest]){
        largest = rightChild;
    }
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }else{
        return;
    }
}
int main(){
    vector<int>arr = {54, 53, 55, 52, 50};
    int n = 5;
    print(arr, n);
    for(int i = n/2; i >= 0; i--){
        heapify(arr, n, i);   
    }
    print(arr, n);
    return 0;
}