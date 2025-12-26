#include <iostream>
using namespace std;
class MaxHeap{
public:
    int *arr;
    int index;
    int size;
    
    MaxHeap(){
        size = 100;
        arr = new int[101];
        arr[0] = -1;
        index = 0;
    }

    void insert(int ele){
        index++;
        arr[index] = ele;
        int temp = index;
        while (temp > 1)
        {
            int parent = temp/2;
            if(arr[parent] < arr[temp]){
                swap(arr[parent], arr[temp]);
                temp = parent;
            }else{
                return;
            }
        }
    }
    void deleteEle(){
        if(index < 1){
            cout << "max heap is empty" << endl;
            return;
        }
        swap(arr[1], arr[index]);
        index--;
        heapify(1);
    }

    void heapify(int i){
        int leftChild = 2 * i;
        int rightChild = 2 * i + 1;
        int greatest = i;
        if (leftChild <= index && arr[leftChild] > arr[greatest])
        {
            greatest = leftChild;
        }
        if (rightChild <= index && arr[rightChild] > arr[greatest])
        {
            greatest = rightChild;
        }
        if(greatest != i){
            swap(arr[i], arr[greatest]);
            heapify(greatest);
        }
    }

    void getTopElement(){
        if(index < 1){
            cout << "heap is empty" << endl;
        }else{
            cout << "Top Element : " << arr[1] << endl;
        }
    }
};
int main()
{
    MaxHeap maxheap;
    maxheap.getTopElement();
    maxheap.insert(10);
    maxheap.getTopElement();
    maxheap.getTopElement();
    maxheap.insert(50);
    maxheap.insert(90);
    maxheap.getTopElement();
    maxheap.insert(20);
    maxheap.insert(100);
    maxheap.deleteEle();
    maxheap.getTopElement();
    return 0;
}