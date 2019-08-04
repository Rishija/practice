/*
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
 */
#include <iostream>
#include <vector>
using namespace std;

/*
 Time : O(9^k)
 Space : O(9^k)
 */
void helper(int k, int n, vector<vector<int>> &ans, vector<int> temp, int index) {
    
    if(n < 0)
        return;
    
    if(k == 0) {
        if(n == 0)
            ans.push_back(temp);
        return;
    }
    
    for(int i = index; i <= 9; ++i) {
        temp.push_back(i);
        helper(k - 1, n - i, ans, temp, i + 1);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    
    vector<vector<int>> ans;
    helper(k, n, ans, {}, 1);
    return ans;
}

void print(int k, int n) {
    
    vector<vector<int>> ans = combinationSum3(k,n);
    for(auto vec : ans) {
        cout << "[";
        for(auto ele : vec)
            cout << ele << ", ";
        cout << "\b\b] ";
    }
    cout << endl;
}

int main() {
    
    print(3, 7);
    print(3, 9);
    print(1, 1);
    print(1, 5);
    print(5, 3);
    
    return 0;
}
