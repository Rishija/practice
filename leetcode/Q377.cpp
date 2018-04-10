/*
 Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.
 */
#include <iostream>
#include <vector>
using namespace std;

/*
 Without DP
 
 Time : Exponential
 Space : O(target)
 */
void helper(const vector<int> &candidates, const int target, const int n, int &cnt) {
    
    if(target < 0)
        return;
    
    if(target == 0) {
        ++ cnt;
        return;
    }
    
    for(int i = 0; i < n; ++i) {
        helper(candidates, target - candidates[i], n, cnt);
    }
}

int combinationSum_1(vector<int>& candidates, int target) {
    
    int ans = 0;
    helper(candidates, target, candidates.size(), ans);
    return ans;
}


/*
 Method 2
 Top down approach

 Time : O(n * target)
 Space : O(target)
 */
int helper(const vector<int> &nums, vector<int> &dp, int target, const int n) {
    
    if(dp[target] == -1) {
        
        if(target == 0)
            dp[target] = 1;
        
        else {
            dp[target] = 0;
            for(int i = 0; i < n; ++i) {
                if(nums[i] <= target)
                    dp[target] += helper(nums, dp, target - nums[i], n);
            }
        }
    }
    return dp[target];
}

int combinationSum_2(vector<int>& nums, int target) {
    
    sort(nums.begin(), nums.end());
    vector<int> dp(target + 1, -1);
    helper(nums, dp, target, nums.size());
    return dp[target];
}


/*
 Method 3
 Bottom up approach
 
 Time : O(n * target)
 Space : O(target)
 */
int combinationSum_3(vector<int>& nums, int target) {
    
    vector<int> dp(target + 1);
    dp[0] = 1;
    int n = nums.size();
    
    for(int i = 1; i <= target; ++i) {
        for(int j = 0; j < n; ++j) {
            if((i - nums[j] >= 0))
                dp[i] += dp[i - nums[j]];
        }
    }
    return dp[target];
}


int main() {
    
    vector<int> vec = {1,2,3};
    cout << combinationSum_3(vec, 4) << endl;
    
    vec = {9};
    cout << combinationSum_3(vec, 3) << endl;
    
    vec = {};
    cout << combinationSum_3(vec, 4) << endl;
    
    return 0;
}
