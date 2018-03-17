#include <iostream>
#include <vector>
using namespace std;

int duplicate(vector<int>arr) {
    
    int n = arr.size();
    for(int i = 0; i < n; ++i) {
        if(arr[abs(arr[i] - 1)] < 0)
            return abs(arr[i]);
        arr[abs(arr[i] - 1)] *= -1;
    }
    return 0;   // Xcode compulsion
}

int main() {
    
    vector<int> a = {1,2,3,4,3};
    cout << duplicate(a) << endl;
    
    a = {1,1};
    cout << duplicate(a) << endl;
    
    a = {2,1,1};
    cout << duplicate(a) << endl;
    
    a = {2,1,2};
    cout << duplicate(a) << endl;
    
    a = {6,3,4,4,1,5,2};
    cout << duplicate(a) << endl;
    
    return 0;
}
