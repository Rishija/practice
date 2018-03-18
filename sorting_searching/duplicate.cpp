/*
 Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), Assume that there is only one duplicate number, find the duplicate one
 */
#include <iostream>
#include <vector>
using namespace std;

int duplicate(vector<int>arr) {
    
    int n = arr.size();
    for(int i = 0; i < n; ++i) {
        if(arr[abs(arr[i]) - 1] < 0)
            return abs(arr[i]);
        arr[abs(arr[i]) - 1] *= -1;
    }
    return 0;   // Xcode compulsion
}

int duplicate2(vector<int> a) {
    
    int n = a.size();
    
    if(n < 2)
        return 0;
    
    long long int sum1 = 0, sum2 = 0;
    for(int i = 0; i < n - 1; ++i) {
        sum1 += i + 1;          // sum of first n natural numbers
        sum2 += a[i];
    }
    sum2 += a[n - 1];           // sum of elements of vector
    
    return sum2 - sum1;
}

int duplicate3(vector<int> a) {
    
    int n = a.size();
    
    if(n < 2)
        return 0;
    
    int xorr = 0;
    for(int i = 0; i < n - 1; ++i) {
        xorr ^= a[i] ^ (i + 1);
    }
    xorr ^= a[n - 1];
    return xorr;
}

/* Method 4 : sort and check */

int main() {
    
    vector<int> a = {1,2,3,4,3};
    cout << duplicate2(a) << endl;
    cout << duplicate3(a) << endl;
    cout << duplicate(a) << endl << endl;
    
    a = {1,1};
    cout << duplicate2(a) << endl;
    cout << duplicate3(a) << endl;
    cout << duplicate(a) << endl << endl;
    
    a = {2,1,1};
    cout << duplicate2(a) << endl;
    cout << duplicate3(a) << endl;
    cout << duplicate(a) << endl << endl;
    
    a = {2,1,2};
    cout << duplicate2(a) << endl;
    cout << duplicate3(a) << endl;
    cout << duplicate(a) << endl << endl;
    
    a = {6,3,4,4,1,5,2};
    cout << duplicate2(a) << endl;
    cout << duplicate3(a) << endl;
    cout << duplicate(a) << endl << endl;
    
    return 0;
}
