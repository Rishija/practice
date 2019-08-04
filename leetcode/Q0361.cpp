/*
 Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0' (the number zero), return the maximum enemies you can kill using one bomb.
 The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since the wall is too strong to be destroyed.
 Note: You can only put the bomb at an empty cell.
 
 Example:
 
 Input: [["0","E","0","0"],["E","0","W","E"],["0","E","0","0"]]
 Output: 3
 Explanation: For the given grid,
 
 0 E 0 0
 E 0 W E
 0 E 0 0
 
 Placing a bomb at (1,1) kills 3 enemies.
 */

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& A) {
        int n = A.size();    if(n == 0) return 0;
        int m = A[0].size(); if(m == 0) return 0;
        vector<vector<int>> right(n + 1, vector<int> (m + 1)), bottom = right, left = right, up = right;
        int ans = 0;
        
        for(int i = n-1; i >= 0; --i) {
            for(int j = m-1; j >= 0; --j)
                if(A[i][j] == '0') {
                    right[i][j] = right[i][j + 1];
                    bottom[i][j] = bottom[i + 1][j];
                }
                else if(A[i][j] == 'E') {
                    right[i][j] = right[i][j + 1] + 1;
                    bottom[i][j] = bottom[i + 1][j] + 1;
                }
        }
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j)
                if(A[i][j] == '0') {
                    left[i][j + 1] = left[i][j];
                    up[i + 1][j] = up[i][j];
                    ans = max(ans, right[i][j] + bottom[i][j] + left[i][j + 1] + up[i + 1][j]);
                }
                else if(A[i][j] == 'E') {
                    left[i][j + 1] = left[i][j] + 1;
                    up[i + 1][j] = up[i][j] + 1;
                }
        }
        return ans;
    }
};
