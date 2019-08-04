/*
 Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).
 
 Note: The solution set must not contain duplicate subsets.
 
 Example:
 
 Input: [1,2,2]
 Output:
 [
 [2],
 [1],
 [1,2,2],
 [2,2],
 [1,2],
 []
 ]
 */

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& A) {
        int n = A.size(); if(n == 0) return {};
        sort(A.begin(), A.end());
        vector<vector<int>> ans = {{}};
        int i = 0, last = 0;
        
        while(true) {
            int size = ans.size();
            for(int k = last; k < size; ++k) {
                ans[k].push_back(A[i]);
                ans.push_back(ans[k]);
                ans[k].pop_back();
            }
            if(++i == n) break;
            last = A[i] != A[i-1] ? 0 : size;
        }
        return ans;
    }
};
