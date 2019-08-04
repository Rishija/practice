/*
 Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

 Example:

 Input: 3
 Output: 5
 Explanation:
 Given n = 3, there are a total of 5 unique BST's:

 1         3     3      2      1
 \       /     /      / \      \
 3     2     1      1   3      2
 /     /       \                 \
 2     1         2                 3
*/

class Solution {
public:
    int helper(vector<int> &dp, int n) {

        if(dp[n] == 0) {
            int sum = 0;
            for(int i = 0; i < n; ++i)
                sum += helper(dp, i) * helper(dp, n-i-1);
            dp[n] = sum;
        }
        return dp[n];
    }

    int numTrees(int n) {

        if(n < 2)
            return n;
        vector<int> dp(n+1);
        dp[0] = 1;
        return helper(dp, n);
    }
};
