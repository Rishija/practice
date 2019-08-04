/*
 A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 
 The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 
 Now consider if some obstacles are added to the grids. How many unique paths would there be?
 */
typedef vector<int> vi;
typedef vector<vi> vvi;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int n = (int)obstacleGrid.size();
    if(n == 0)
        return 0;
    int m = (int)obstacleGrid[0].size();
    if(m == 0)
        return 0;
    vvi dp(n, vi (m));
    
    for(int i = n-1; i >= 0; --i) {
        for(int j = m-1; j >= 0; --j) {
            if(obstacleGrid[i][j])
                continue;
            if(i == n-1 && j == m-1) {
                dp[i][j] = 1;
                continue;
            }
            if(i < n - 1) {
                if(j < m - 1)
                    dp[i][j] = dp[i+1][j] + dp[i][j+1];
                else
                    dp[i][j] = dp[i+1][j];
            }
            else
                dp[i][j] = dp[i][j+1];
        }
    }
    return dp[0][0];
}
