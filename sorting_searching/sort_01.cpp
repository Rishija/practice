#include <iostream>
#include <cstdlib>
#include <vector>
#include <functional>
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

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void method3(int *arr) {
    
    int low = 0, high = N;
    
    for(int i = 0; i < high; ++i) {
        if(arr[i] == 0) {
            if(i != low)
                swap(arr[i], arr[low]);
            ++ low;
        }
        else {
            --high;
            swap(arr[i], arr[high]);
            if(arr[i] == 1)
                --i;
        }
    }
}

void print(int *arr) {
    
    for(int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

void sort_print(vector<int*> &v, function<void(int*)>sortFn) {
    
    for(int i = 0; i < v.size(); ++i) {
        sortFn(v[i]);
        print(v[i]);
    }
}

int main() {
    
    int arr1[N], arr2[N], arr3[N];
    for(int i = 0; i< N; ++i) {
        arr1[i] = 0;
        arr2[i] = 1;
        arr3[i] = rand() % 2;
    }
    
    vector<int*> v;
    v.push_back(arr1);
    v.push_back(arr2);
    v.push_back(arr3);
    
    // sort_print(v, method1);
    // sort_print(v, method2);
    sort_print(v, method3);
    
    return 0;
}
