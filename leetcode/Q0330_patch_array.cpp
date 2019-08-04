/*
Given a sorted positive integer array nums and an integer n, add/patch elements to the array such that any number in range [1, n] inclusive can be formed by the sum of some elements in the array. Return the minimum number of patches required.
 */
#include <iostream>
#include <vector>
using namespace std;

/*
 Time : O(n)
 Space : O(1)
 */

int minPatches(vector<int>& nums, int n) {
    
    int cnt = 0;
    
    long long int limit = 1, i = 0;
    while(limit <= n) {
        
        if(i >= nums.size() || nums[i] > limit ) {
            /*
             Patched number = limit
             New range is till 2 * limit
             */
            ++cnt;
            limit = (limit << 1) ;
        }
        else {
            limit += nums[i];
            ++i;
        }
    }
    return cnt;
}


int main() {
    
    vector<int> vec;
    vec = {};
    cout << minPatches(vec, 8) << endl;
    
    vec = {1,2,31,33};
    cout << minPatches(vec, 2147483647) << endl;
    
    vec = {1,3};
    cout << minPatches(vec, 6) << endl;
    
    vec = {};
    cout << minPatches(vec, 7) << endl;
    
    vec = {1,5,10};
    cout << minPatches(vec, 20) << endl;
    
    vec = {1,2,2};
    cout << minPatches(vec, 5) << endl;
    
    return 0;
}
