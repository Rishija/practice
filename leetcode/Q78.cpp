/*

 Given a set of distinct integers, nums, return all possible subsets (the power set).

 Note: The solution set must not contain duplicate subsets.

 Example:

 Input: nums = [1,2,3]
 Output:
 [
 [3],
 [1],
 [2],
 [1,2,3],
 [1,3],
 [2,3],
 [1,2],
 []
 ]
 */

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& A) {
        int n = A.size();
        if(n == 0)  return {};

        vector<vector<vector<int>>> dp(n+1);
        dp[n] = {{}};
        for(int i = n-1; i >= 0; --i) {
            for(auto &v : dp[i+1]) {
                dp[i].push_back(v);
                v.push_back(A[i]);
                dp[i].push_back(v);
            }
        }
        return dp[0];
    }
};
