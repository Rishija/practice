/*
 Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 
 The same repeated number may be chosen from C unlimited number of times.
 */
#include <iostream>
#include <vector>
using namespace std;

/*
 Time : Exponential
 Space : Exponential
 */
void helper(const vector<int> &candidates, const int target, const int n, vector<vector<int>> &ans, int sumTillNow, vector<int>temp, int index) {
    
    if(sumTillNow > target)
        return;
    
    if(sumTillNow == target) {
        ans.push_back(temp);
        return;
    }
    
    for(int i = index; i < n; ++i) {
        temp.push_back(candidates[i]);
        helper(candidates, target, n, ans, sumTillNow + candidates[i], temp, i);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    
    vector<vector<int>> ans;
    sort(candidates.begin(), candidates.end());
    helper(candidates, target, candidates.size(), ans, 0, {}, 0);
    return ans;
}

void print(vector<int> c, int t) {
    
    vector<vector<int>> ans = combinationSum(c, t);
    for(auto vec : ans) {
        cout << "[";
        for(auto ele : vec)
            cout << ele << ", ";
        cout << "\b\b] ";
    }
    cout << endl;
}

int main() {
    
    print({2,3,6,7}, 7);
    print({1,2,3}, 6);
    print({},5);
    print({2}, 2);
    print({2}, 3);
    
    return 0;
}
