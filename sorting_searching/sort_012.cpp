/*
 Dutch flag problem : Sort array of 0s, 1s and 2s
 */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <functional>
#include <utility>
#define N 10
using namespace std;

void method1(int *arr, int n) {
    
    int cnt0 = 0, cnt1 = 0;
    
    for(int i = 0; i < n; ++i)
        if(!arr[i])
            ++ cnt0;
        else if(arr[i] == 1)
            ++ cnt1;
    
    for(int i = 0; i < cnt0; ++i)
        arr[i] = 0;
    
    for(int i = cnt0, j = 0; j < cnt1 ; ++i, ++j)
        arr[i] = 1;
    
    for(int i = cnt0 + cnt1; i < n; ++i)
        arr[i] = 2;
}

void method2(int *arr, int n) {
    
    int p = -1;
    for(int i = 0; i < n; ++i) {
        if(!arr[i]) {
            ++p;
            arr[i] = arr[p];
            arr[p] = 0;
        }
    }
    
    for(int i = p + 1; i < n; ++i) {
        if(arr[i] == 1) {
            ++p;
            arr[i] = arr[p];
            arr[p] = 1;
        }
    }
    
    for(int i = p + 1 ; i < n; ++i)
        arr[i] = 2;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void method3(int *arr, int n) {
    
    int low = -1, high = n;
    
    for(int i = 0; i < n - 1 ; ++i) {
        
        if(i < high) {
            if(!arr[i]) {
                ++ low;
                if(i != low)
                    swap(arr[i], arr[low]);
            }
            else if(arr[i] == 2){
                --high;
                if(i != high)
                    swap(arr[i], arr[high]);
            }
            // exchanged element is still either 0 or 2
            if(arr[i] != 1 && i != low)
                --i;
        }
    }
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
    
    int arr1[N], arr2[N], arr3[N], arr4[N], arr5[N], arr6[N], arr7[N],
    arr8[2] = {0,0}, arr9[2] = {1,1}, arr10[2] = {2,2}, arr11[2] = {1,0}, arr12[2] = {2,1}, arr13[2] = {2,0},
    arr14[1] = {0}, arr15[1] = {1}, arr16[1] = {2};
    for(int i = 0; i< N; ++i) {
        arr1[i] = 0;
        arr2[i] = 1;
        arr3[i] = 2;
        arr4[i] = rand() % 2;           // 0s and 1s
        arr5[i] = rand() % 2 + 1;       // 1s and 2s
        arr6[i] = rand() % 2 ? 2 : 0;   // 0s and 2s
        arr7[i] = rand() % 3;           // mix
    }
    
    vector<pair<int*, int>> v;
    v.push_back({arr1,N});
    v.push_back({arr2,N});
    v.push_back({arr3,N});
    v.push_back({arr4,N});
    v.push_back({arr5,N});
    v.push_back({arr6,N});
    v.push_back({arr7,N});
    v.push_back({arr8,2});
    v.push_back({arr9,2});
    v.push_back({arr10,2});
    v.push_back({arr11,2});
    v.push_back({arr12,2});
    v.push_back({arr13,2});
    v.push_back({arr14,1});
    v.push_back({arr15,1});
    v.push_back({arr16,1});
    
    // sort_print(v, method1);
    // sort_print(v, method2);
    sort_print(v, method3);
    
    return 0;
}

