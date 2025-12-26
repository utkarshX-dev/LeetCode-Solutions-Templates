#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> segmentTree, lazy;
vector<int> arr;

void builtTree(int i, int l, int r)
{
    if (l == r){
        segmentTree[i] = arr[l];
        return;
    }

    int mid = l + (r - l) / 2;
    builtTree(2 * i + 1, l, mid);
    builtTree(2 * i + 2, mid + 1, r);

    segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2];
}

void updateQuery(int val, int i, int l, int r, int idx)
{
    if (l == r){
        segmentTree[i] = val;
        return;
    }

    int mid = l + (r - l) / 2;
    if (idx <= mid){
        updateQuery(val, 2 * i + 1, l, mid, idx);
    }
    else{
        updateQuery(val, 2 * i + 2, mid + 1, r, idx);
    }
    segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2];
}

int getRangeSum(int i, int l, int r, int s, int e){
    if(r < s || e < l){
        return 0;
    }else if(s <= l && r <= e){
        return segmentTree[i];
    }else{
        int mid = l + (r - l)/2;
        return getRangeSum(2 * i + 1, l, mid, s, e) + getRangeSum(2 * i + 2, mid + 1, r, s, e);
    }
}

void printSegmentTree(int n) {
    for (int i = 0; i < 2 * n; i++) {
        cout << segmentTree[i] << " ";
    }
    cout << endl;
}


void lazyProporgation(int i, int s, int e, int l, int r, int val){
    if(lazy[i] != 0){
        segmentTree[i] += (r - l + 1) * lazy[i];
        if(l != r){
            lazy[2 * i + 1] += lazy[i];
            lazy[2 * i + 2] += lazy[i];
        }
        lazy[i] = 0;
    }
    if(r < s || e < l){
        return;
    }else  if(s <= l && r <= e){
        segmentTree[i] += (r - l + 1) * val;
        if(l != r){
            lazy[2 * i + 1] += val;
            lazy[2 * i + 2] += val;
        }
        return;
    }else{
        int mid = l + (r - l)/2;
        lazyProporgation(2 * i + 1, l, mid, s, e, val);
        lazyProporgation(2 * i + 2, mid + 1, r, s, e, val);
        segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2]; 
    }
}


int main()
{
    arr = {1, 2, 3, 4};
    int n = arr.size();

    segmentTree.resize(4 * n, 0);
    lazy.resize(4 * n, 0);
    builtTree(0, 0, n - 1);

    cout << "Segment Tree after build:\n";
    printSegmentTree(n);

    cout << "Range sum (1, 3): ";
    cout << getRangeSum(0, 0, n - 1, 1, 3) << endl;

    updateQuery(10, 0, 0, n - 1, 2);

    cout << "Segment Tree after update (index 2 = 10):\n";
    printSegmentTree(n);

    cout << "Range sum (1, 3) after update: ";
    cout << getRangeSum(0, 0, n - 1, 1, 3) << endl;

    return 0;
}
