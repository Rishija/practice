/*
  A sorted array is rotated, find and element in it. eg. 1 3 5 7 9 becomes 5 7 9 1 3
 */
#include <iostream>
using namespace std;

/* O(log(N)) */
int bsearch(int elem, int *arr, int start, int n) {
    
    int low = start, high = start + n - 1, mid, mid1;
    while(low <= high) {
        
        mid = (low + high)/2;
        mid1 = mid % n;
        
        if(arr[mid1] == elem)
            return mid1;
        if(arr[mid1] < elem)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

/* O(log(N)) */
int changeAt(int *arr, int n) {
    
    int low = -1, high = n, mid;
    
    for(int i = 0; i < n; ++i) {
        
        if(low == high  - 2)
            return low + 1;
        
        mid = (low + high) / 2;
        
        if(arr[mid] > arr[mid + 1])     // change from index mid
            return mid;
        
        if(arr[mid - 1] > arr[mid])     // change at index mid-1
            return mid - 1;
        
        if(arr[low + 1] < arr[mid])     // error on right side
            low = mid + 1;
        else
            high = mid - 1;             // error on left side
    }
    
    return 0;
}

/* O(log(N)) */
int rotated_bsearch(int elem, int *arr, int n) {
    
    int t = changeAt(arr, n);
    return bsearch(elem, arr, t + 1, n);
}

void print(int *arr, int n) {
    
    cout << "{ ";
    for(int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << " }" << endl;
    
    for(int i = 0; i < n; ++i)
        cout << arr[i] << "\t->\t" << rotated_bsearch(arr[i], arr, n) << endl;
    cout << endl;
}

int main() {
    
    int arr1[10] = {80,90,100,10,20,30,40,50,60,70},
    arr2[2] = {20,10},
    arr3[3] = {50},
    arr4[4] = {10,20,30,40};
    
    print(arr1, 10);
    print(arr2, 2);
    print(arr3, 1);
    print(arr4, 4);
    
    return 0;
}
