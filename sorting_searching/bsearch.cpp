#include <iostream>
using namespace std;
#define N 10

int bsearch(int elem, int *arr, int n) {
    
    int low = 0, high = n - 1, mid;
    while(low <= high) {
        
        mid = (low + high)/2;
        
        if(arr[mid] == elem)
            return mid;
        if(arr[mid] < elem)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    
    int arr[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    cout << bsearch(1, arr, N) << endl;
    cout << bsearch(10, arr, N) << endl;
    cout << bsearch(2, arr, N) << endl;
    cout << bsearch(9, arr, N) << endl;
    cout << bsearch(5, arr, N) << endl;
    cout << bsearch(-1, arr, N) << endl;
    cout << bsearch(11, arr, N) << endl;
    return 0;
}
