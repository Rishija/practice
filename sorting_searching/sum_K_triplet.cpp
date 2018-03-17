/*
 Given a sorted array and a K. Find all triplets in array with sum equals K
 */
#include <iostream>
#include <vector>
#include <tuple>
#define N 10
using namespace std;

/* O(N)
 O(N log(N)) : Method 2
 */
vector<tuple<int,int> > sum_K(int *arr, int loww, int n, int K) {
    
    int low = loww, high = n - 1, temp;
    vector<tuple<int,int> > vec;
    
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
     for(int i = low; i < n; ++i) {
     pairIndex = bsearch(K - arr[i], arr, i+1, n);
     if(pairIndex > -1) {
     vec.push_back({arr[i], arr[pairIndex]});
     }
     }
     */
    return vec;
}

/* O(N^2) */
vector<tuple<int,int,int> > sum_K_triplet(int *arr, int n, int K) {
    
    int size;
    vector<tuple<int,int> > temp;
    vector<tuple<int, int, int> > ans;
    
    for(int i = 0; i < n; ++i) {
        
        temp = sum_K(arr, i + 1, n, K - arr[i]);
        size = temp.size();
        
        for(int j = 0; j < size; ++j)
            ans.push_back({arr[i], get<0>(temp[j]), get<1>(temp[j])});
    }
    return ans;
}

void print_vector(vector<tuple<int,int,int> > &vec) {
    
    for(int i = 0; i< vec.size(); ++i)
        cout << "(" << get<0>(vec[i]) << ", " << get<1>(vec[i]) << ", " << get<2>(vec[i]) << ") ";
    cout << endl;
}

int main() {
    
    int arr[N] = {1, 4, 7, 9, 10, 19, 20, 21, 30, 50};
    vector<tuple<int,int,int> > ans;
    
    ans = sum_K_triplet(arr, N, 60);
    print_vector(ans);
    
    ans = sum_K_triplet(arr, N, 2);
    print_vector(ans);
    
    ans = sum_K_triplet(arr, N, 40);
    print_vector(ans);
    return 0;
}
