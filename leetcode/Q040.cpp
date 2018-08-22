/*
 Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 
 Each number in C may only be used once in the combination.
 */
#include <iostream>
#include <vector>
using namespace std;

/*
 Time : Exponential
 Space : Exponential
 */
void helper(const vector<int> &candidates, const int target, const int n, vector<vector<int>> &ans, vector<int>temp, int index) {
    
    if(target < 0)
        return;
    
    if(target == 0) {
        ans.push_back(temp);
        return;
    }
    
    for(int i = index; i < n; ++i) {
        
        if(i > index && candidates[i] == candidates[i-1])
            continue;
        
        temp.push_back(candidates[i]);
        helper(candidates, target - candidates[i], n, ans, temp, i + 1);
        temp.pop_back();
        
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    
    vector<vector<int>> ans;
    sort(candidates.begin(), candidates.end());
    helper(candidates, target, candidates.size(), ans, {}, 0);
    return ans;
}

void print(vector<int> c, int t) {
    
    vector<vector<int>> ans = combinationSum2(c, t);
    for(auto vec : ans) {
        cout << "[";
        for(auto ele : vec)
            cout << ele << ", ";
        cout << "\b\b] ";
    }
    cout << endl;
}

int main() {
    
    print({10, 1, 2, 7, 6, 1, 5}, 8);
    print({1,2,3}, 6);
    print({},5);
    print({2}, 2);
    print({2}, 3);
    
    return 0;
}
