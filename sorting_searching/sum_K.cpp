/*
  Given a sorted array and a K. Find all pairs in array with sum equals K
 */
#include <iostream>
#include <vector>
#include <utility>
#define N 10
using namespace std;

/*
 O(N)
 O(N log(N)) : Method 2
 */
vector<pair<int,int> > sum_K(int *arr, int n, int K) {
    
    int low = 0, high = n - 1, temp;
    vector<pair<int,int> > vec;
    
    while(low < high) {
        temp = arr[low] + arr[high];
        if(temp == K) {
            vec.push_back({arr[low], arr[high]});
            /* Conditions : Elements should be unique */
            ++ low;
            -- high;
        }
        else if(temp < K)
            ++ low;
        else
            -- high;
    }
    
    /* Method 2
     
     int pairIndex;
     for(int i = 0; i < n; ++i) {
     pairIndex = bsearch(K - arr[i], arr, i+1, n);
     if(pairIndex > -1)
     vec.push_back({arr[i], arr[pairIndex]});
     }
     */
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
