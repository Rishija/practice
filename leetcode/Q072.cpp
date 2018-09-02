/*
 Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.
 
 You have the following 3 operations permitted on a word:
 
 Insert a character
 Delete a character
 Replace a character
 */
typedef vector<int> vi;
typedef vector<vi> vvi;

int minDistance(string word1, string word2) {
    
    int n = word1.size(), m = word2.size();
    
    vvi dp(n+1, vi(m+1));
    for(int i = 1; i <= n; ++i)     dp[i][0] = i;
    for(int j = 1; j <= m; ++j)     dp[0][j] = j;
    
    for(int i = 1; i <=n; ++i)
        for(int j = 1; j <= m; ++j) {
            if(word1[i-1] == word2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else {
                if(dp[i-1][j] <= dp[i][j-1]) {
                    if(dp[i-1][j] <= dp[i-1][j-1])
                        dp[i][j] = 1 + dp[i-1][j];
                    else
                        dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                    dp[i][j] = 1 + (dp[i][j-1] < dp[i-1][j-1] ? dp[i][j-1] : dp[i-1][j-1]);
            }
        }
    return dp[n][m];
}
