#include <iostream>
#include <cstdlib>
#define N 10
using namespace std;

void method1(int *arr) {
    
    int cnt0 = 0, cnt1 = 0;
    
    for(int i = 0; i < N; ++i)
        if(!arr[i])
            ++ cnt0;
        else if(arr[i] == 1)
            ++ cnt1;
    
    for(int i = 0; i < cnt0; ++i)
        arr[i] = 0;
    
    for(int i = cnt0, j = 0; j < cnt1 ; ++i, ++j)
        arr[i] = 1;
    
    for(int i = cnt0 + cnt1; i < N; ++i)
        arr[i] = 2;
}

void method2(int *arr) {
    
    int p = -1;
    for(int i = 0; i < N; ++i) {
        if(!arr[i]) {
            ++p;
            arr[i] = arr[p];
            arr[p] = 0;
        }
    }
    
    for(int i = p + 1; i < N; ++i) {
        if(arr[i] == 1) {
            ++p;
            arr[i] = arr[p];
            arr[p] = 1;
        }
    }
    
    for(int i = p + 1 ; i < N; ++i)
        arr[i] = 2;
}

void method3(int *arr) {
    
    int low = -1, high = N;
    
    for(int i = 0; i < high; ++i) {
        if(!arr[i]) {
            ++ low;
            arr[i] = arr[low];
            arr[low] = 0;
        }
        else if(arr[i] == 2){
            --high;
            arr[i] = arr[high];
            arr[high] = 2;
        }
        if(arr[i] != 1 && i != low)
            --i;
    }
}

void print(int *arr) {
    
    for(int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    
    int arr1[N], arr2[N], arr3[N], arr4[N], arr5[N], arr6[N], arr7[N];
    for(int i = 0; i< N; ++i) {
        arr1[i] = 0;
        arr2[i] = 1;
        arr3[i] = 2;
        arr4[i] = rand() % 2;           // 0s and 1s
        arr5[i] = rand() % 2 + 1;       // 1s and 2s
        arr6[i] = rand() % 2 ? 2 : 0;   // 0s and 2s
        arr7[i] = rand() % 3;           // mix
    }
    
    print(arr1);
    print(arr2);
    print(arr3);
    print(arr4);
    print(arr5);
    print(arr6);
    print(arr7);
    cout <<endl;
    
    /*
     method1(arr1);
     method1(arr2);
     method1(arr3);
     method1(arr4);
     method1(arr5);
     method1(arr6);
     method1(arr7);
     */
    
    /*
     method2(arr1);
     method2(arr2);
     method2(arr3);
     method2(arr4);
     method2(arr5);
     method2(arr6);
     method2(arr7);
     */
    
    /*
     method3(arr1);
     method3(arr2);
     method3(arr3);
     method3(arr4);
     method3(arr5);
     method3(arr6);
     method3(arr7);
     */
    
    print(arr1);
    print(arr2);
    print(arr3);
    print(arr4);
    print(arr5);
    print(arr6);
    print(arr7);
    
    return 0;
}
