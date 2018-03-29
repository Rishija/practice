/*
The set [1,2,3,…,n] contains a total of n! unique permutations.
Given n and k, return the kth permutation sequence.
 */

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

/*
 Time : O(n)
 Space : O(n)
 */

void factorial(int n, vector<int> &fact) {
    
    if(n == 1) {
        fact[1] = 1;
        return;
    }
    factorial(n - 1, fact);
    fact[n] = n * fact[n - 1];
}

string getPermutation(int n, int k) {
    
    string nums;
    nums = "*" + nums;
    for(int i = 1; i <= n; ++i)
        nums += to_string(i);
    
    if(k == 1) {
        nums.erase(nums.begin());
        return nums;
    }
    
    vector<int> fact(n+1);
    factorial(n, fact);
    
    string ans;
    --n;
    float remainder = k, quo;
    
    while(n >= 1 && remainder) {
        
        quo = ceil(remainder/fact[n]);
        ans += nums[quo];
        nums.erase(nums.begin() + quo);
        remainder = (int)remainder % fact[n];
        --n;
    }
    
    /*
     Remainder was fully divisible by fact(n)
     Add numerbers in reverse order
     */
    if(!remainder) {
        reverse(nums.begin(), nums.end());
        ans += nums;
    }
    
    // Delete *
    ans.erase(ans.end() - 1);
    return ans;
}

int main() {
    
    cout << getPermutation(5,80) << endl;       // 42153
    
    cout << getPermutation(5,78) << endl;       // 41532
    
    cout << getPermutation(5,72) << endl;       // 35421
    
    cout << getPermutation(5,1) << endl;        // 12345
    
    cout << getPermutation(5,120) << endl;      // 54321
    
    cout << getPermutation(5,3) << endl;        // 12435
    
    cout << getPermutation(2,1) << endl;        // 12
    
    cout << getPermutation(2,2) << endl;        // 21
    
    cout << getPermutation(1,1) << endl;        // 1
    
    return 0;
}
