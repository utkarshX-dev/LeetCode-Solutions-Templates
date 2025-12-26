#include <bits/stdc++.h>
using namespace std;
void sortZeroesAndOne(int input[], int size)
{
    int i = 0;
    int j = size - 1;
    while(i < j){
        if(input[j]){
            j--;
        }else if(!input[i]){
            i++;
        }else{
            swap(input[i], input[j]);
            i++, j--;
        }
    }
}