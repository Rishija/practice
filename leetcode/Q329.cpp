/*
Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

Input: nums =
[
 [9,9,4],
 [6,6,8],
 [2,1,1]
 ]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].
Example 2:

Input: nums =
[
 [3,4,5],
 [3,2,6],
 [2,2,1]
 ]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
*/

int n, m, ans;

int visit(const int i, const int j, const vector<vector<int>> &A, vector<vector<int>> &val, const long last) {
    // Invalid index
    if(i < 0 || j < 0 || i >= n || j >= m)
        return 0;
    // Current is greater than last term
    if(A[i][j] > last) {
        if(val[i][j] == 0) {
            val[i][j] = 1 + max(max(max(visit(i + 1, j, A, val, A[i][j]),
                                        visit(i, j + 1, A, val, A[i][j])),
                                    visit(i - 1, j, A, val, A[i][j])),
                                visit(i, j - 1, A, val, A[i][j]));
            ans = max(ans, val[i][j]);
        }
        return val[i][j];
    }
    return 0;
}

int longestIncreasingPath(vector<vector<int>>& A) {
    n = A.size();
    if(n == 0)
        return 0;
    m = A[0].size(), ans = 0;
    
    vector<vector<int>> val(n, vector<int>(m));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j)
            visit(i, j, A, val, LLONG_MIN);
    }
    return ans;
}
