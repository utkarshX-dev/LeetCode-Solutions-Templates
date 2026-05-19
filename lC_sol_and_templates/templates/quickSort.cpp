#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int s, int e){
    int idx = s - 1;
    int pivot = arr[e];
    for(int j = s; j < e; j++){
        if(pivot >= arr[j]){
            idx++;
            swap(arr[idx], arr[j]);
        }
    }

    idx++;
    swap(arr[idx], arr[e]);
    return idx;
}

void quickSort(vector<int>& arr, int s, int e){
    if(s >= e) return;
    int pivotIdx = partition(arr, s, e);
    quickSort(arr, s, pivotIdx - 1);
    quickSort(arr, pivotIdx + 1, e);
}

void print(vector<int>& arr){
    for(int& x : arr){
        cout << x << " ";
    }
    cout << endl;
}

int main(){
    vector<int>arr = {4, 3, 1, 2, 9};
    cout << "Before quick sort: ";
    print(arr);

    quickSort(arr, 0, arr.size() - 1);
    cout << "After quick sort: ";
    print(arr);
    return 0;
}