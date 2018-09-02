/*
 Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 Example 1:

 Input:
 11110
 11010
 11000
 00000

 Output: 1
 Example 2:

 Input:
 11000
 11000
 00100
 00011

 Output: 3
 */

class Solution {
public:
    void helper(vector<vector<bool>> &visited, const vector<vector<char>> &A, const int row, const int col, const int n, const int m) {
        if(row < 0 || row >= n || col < 0 || col >= m || visited[row][col] == true || A[row][col] == '0')  return;
        visited[row][col] = 1;
        helper(visited, A, row + 1, col, n, m);
        helper(visited, A, row - 1, col, n, m);
        helper(visited, A, row, col + 1, n, m);
        helper(visited, A, row, col - 1, n, m);
    }

    int numIslands(vector<vector<char>>& A) {
        int n = A.size();       if(n == 0)  return 0;
        int m = A[0].size();    if(m == 0)  return 0;

        int count = 0;
        vector<vector<bool>> visited(n, vector<bool>(m));
        for(int i = 0; i < n; ++i)  for(int j = 0; j < m; ++j)
            if(A[i][j] == '1' && visited[i][j] == false) {
                helper(visited, A, i, j, n, m);
                ++count;
            }
        return count;
    }
};
