/*
 Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand. Find the minimum element. You may assume no duplicate exists in the array
 */
#include <iostream>
#include <vector>
using namespace std;

int min(vector<int> a) {
    
    int n = a.size();
    if(!n)
        return -1;
    if(n == 1)
        return a[0];
    
    int low = 0, high = n - 1, mid;
    
    while(low < high) {
        mid = low + (high - low) / 2;
        
        if(a[low] < a[high])    // sorted
            return a[low];
        
        if(a[mid] > a[high])    // search in right half
            low = mid + 1;
        else
            high = mid;
    }
    return a[low];
    
    /* Method 2
     
     while(low <= high) {
     
         mid = low + (high - low) / 2;
     
         if(a[mid] > a[(mid + 1 + n) % n])
             return a[(mid + 1 + n) % n];
     
         if(a[(mid - 1 + n) % n] > a[mid])
             return a[mid];
     
         if(a[low] > a[mid])
             high = mid - 1;
         else
             low = mid + 1;
     }
     return -1;  // Xcode compulsion
     
     */
}

int main() {
    vector<int> a = {80,90,100,10,20,30,40,50,60,70};
    cout << min(a) << endl;
    
    a = {20,10};
    cout << min(a) << endl;
    
    a = {50};
    cout << min(a) << endl;
    
    a = {10,20,30,40};
    cout << min(a) << endl;
    
    a = {10,20};
    cout << min(a) << endl;
    
    a = {20,30,10};
    cout << min(a) << endl;
}
