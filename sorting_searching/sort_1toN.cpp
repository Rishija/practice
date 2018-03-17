/*
 An array of size N. Has unique element from 1 to N sort it.
 */
#include <iostream>
using namespace std;
#define N 10

void swap(int &a, int &b) {
    
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    
    int arr[N] = {8, 3, 5, 1, 9, 2, 10, 4, 7, 6}, i = 0;
    
    while(i < N) {
        if(arr[i] != (i+1))
            swap(arr[arr[i] - 1], arr[i]);
        else
            ++i;
    }
    /* Method 2
     
    for(int i = 0; i < N; ++i) {
        
        int index = (arr[i] - 1) % (N);
        arr[index] += N * index;
    }
    
    for(int i = 0; i < N; ++i)
        arr[i] = (arr[i] - 1) / N + 1;
     */
    
    for(int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << endl;
    
    return 0;
}
