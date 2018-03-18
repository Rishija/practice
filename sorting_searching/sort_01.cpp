/*
 Sort array of 0s and 1s
 */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <functional>
#define N 10
using namespace std;

void method1(int *arr, int n) {
    
    int cnt = 0;
    
    for(int i = 0; i < n; ++i)
        if(!arr[i])
            ++cnt;
    
    for(int i = 0; i < cnt; ++i)
        arr[i] = 0;
    
    for(int i = cnt; i < n; ++i)
        arr[i] = 1;
}

void method2(int *arr, int n) {
    
    int p = -1;
    for(int i = 0; i < n; ++i)
        if(!arr[i])
            arr[++p] = 0;
    
    for(int i = p + 1; i < n; ++i)
        arr[i] = 1;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void method3(int *arr, int n) {
    
    int low = 0, high = n, i = 0;
    
    while(i < high) {
        if(arr[i] == 0) {
            if(i != low)
                swap(arr[i], arr[low]);
            ++ low;
        }
        else {
            --high;
            swap(arr[i], arr[high]);
        }
        if(arr[i] == 0)
            ++i;
    }
}

// partioning
void method4(int *arr, int n) {
    
    int pivot = arr[n-1], p = -1;
    for(int j = 0; j < n - 1; ++j){
        if(pivot == 0) {
            if(arr[j] <= pivot){
                ++p;
                swap(arr[p], arr[j]);
            }
        }
        else {
            if(arr[j] < pivot){
                ++p;
                swap(arr[p], arr[j]);
            }
        }
    }
    if(pivot == 0)
        swap(arr[p + 1], arr[n - 1]);
}

void print(int *arr, int n) {
    
    for(int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

void sort_print(vector<pair<int*, int>> &v, function<void(int*, int)>sortFn) {
    
    for(int i = 0; i < v.size(); ++i) {
        sortFn(v[i].first, v[i].second);
        print(v[i].first, v[i].second);
    }
}

int main() {
    
    int arr1[N], arr2[N], arr3[N], arr4[2] = {0,1}, arr5[2] = {1,0};
    for(int i = 0; i< N; ++i) {
        arr1[i] = 0;
        arr2[i] = 1;
        arr3[i] = rand() % 2;
    }
    
    vector<pair<int*,int>> v;
    v.push_back({arr1, 10});
    v.push_back({arr2, 10});
    v.push_back({arr3, 10});
    v.push_back({arr4, 2});
    v.push_back({arr5, 2});
    
    // sort_print(v, method1);
    // sort_print(v, method2);
    // sort_print(v, method3);
    sort_print(v, method4);
    
    return 0;
}

