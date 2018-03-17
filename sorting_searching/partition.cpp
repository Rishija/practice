#include <iostream>
#define N 10
using namespace std;

void swap(int &a, int &b) {
    
    int temp = a;
    a = b;
    b = temp;
}

int partition(int *arr, int startFrom, int pivotIndex) {
    
    int pivot = arr[pivotIndex], i = startFrom - 1;
    for(int j = startFrom; j < pivotIndex; ++j){
        if(arr[j] <= pivot){
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[pivotIndex]);
    return i+1;     // return index of pivot element
}

void print_array(int *arr, int n) {
    
    for(int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    
    int arr[] = {60, 70, 40, 100, 80, 10, 50, 90, 30, 20};
    
    cout << "Correct index of " << arr[N - 1] << ": " << partition(arr, 0, N - 1) << endl;
    print_array(arr, N);
    
    cout << "Correct index of " << arr[N - 1] << ": " << partition(arr, 0, N - 1) << endl;
    print_array(arr, N);
    
    return 0;
}
