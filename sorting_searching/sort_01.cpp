#include <iostream>
#include <cstdlib>
#define N 10
using namespace std;

void method1(int *arr) {
    
    int cnt = 0;
    
    for(int i = 0; i < N; ++i)
        if(!arr[i])
            ++cnt;
    
    for(int i = 0; i < cnt; ++i)
        arr[i] = 0;
    
    for(int i = cnt; i < N; ++i)
        arr[i] = 1;
}

void method2(int *arr) {
    
    int p = -1;
    for(int i = 0; i < N; ++i)
        if(!arr[i])
            arr[++p] = 0;
    
    for(int i = p + 1; i < N; ++i)
        arr[i] = 1;
}

void method3(int *arr) {
    
    int low = -1, high = N;
    
    for(int i = 0; i < high; ++i) {
        if(!arr[i])
            arr[++low] = 0;
        else {
            --high;
            arr[i] = arr[high];
            arr[high] = 1;
            if(arr[i])
                --i;
        }
    }
}

void print(int *arr) {
    
    for(int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    
    int arr1[N], arr2[N], arr3[N];
    for(int i = 0; i< N; ++i) {
        arr1[i] = 0;
        arr2[i] = 1;
        arr3[i] = rand() % 2;
    }
    
    /*
     method1(arr1);
     method1(arr2);
     method1(arr3);
     */
    
    /*
     method2(arr1);
     method2(arr2);
     method2(arr3);
     */
    
    /*
     method3(arr1);
     method3(arr2);
     method3(arr3);
    */
    
    print(arr1);
    print(arr2);
    print(arr3);
    
    return 0;
}
