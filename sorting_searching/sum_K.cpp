/*
  Given a sorted array and a K. Find all pairs in array with sum equals K
 */
#include <iostream>
#include <vector>
#include <utility>
#define N 10
using namespace std;

/* O(log(N)) */
int bsearch(int elem, int *arr, int loww, int n) {
    
    int low = loww, high = n - 1, mid;
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

/* O(N log(N)) */
vector<pair<int,int> > sum_K(int *arr, int n, int K) {
    
    int pairIndex;
    vector<pair<int,int> > vec;
    for(int i = 0; i < n; ++i) {
        pairIndex = bsearch(K - arr[i], arr, i+1, n);
        if(pairIndex > -1)
            vec.push_back({arr[i], arr[pairIndex]});
    }
    return vec;
}

void print_vector(vector<pair<int,int> > &vec) {
    
    for(int i = 0; i< vec.size(); ++i)
        cout << "(" << vec[i].first << ", " << vec[i].second << ") ";
    cout << endl;
}

int main() {
    
    int arr[N] = {1, 4, 7, 10, 17, 19, 20, 21, 97, 100};
    vector<pair<int,int> >vec;
    
    vec = sum_K(arr, N, 101);
    print_vector(vec);
    
    vec = sum_K(arr, N, 17);
    print_vector(vec);
    
    vec = sum_K(arr, N, 42);
    print_vector(vec);
    
    return 0;
}
