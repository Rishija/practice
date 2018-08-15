/*
 You are given a m x n 2D grid initialized with these three possible values.
 
 -1 - A wall or an obstacle.
 0 - A gate.
 INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
 Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.
 
 Example:
 
 Given the 2D grid:
 
 INF  -1  0  INF
 INF INF INF  -1
 INF  -1 INF  -1
 0  -1 INF INF
 
 After running your function, the 2D grid should be:
 
 3  -1   0   1
 2   2   1  -1
 1  -1   2  -1
 0  -1   3   4
 */

class item {
public:
    int row, col, val;
    item(int i, int j, int v) : row(i), col(j), val(v) {}
};

class Solution {
public:
    
    void wallsAndGates(vector<vector<int>>& A) {
        int n = A.size();    if(n == 0) return;
        int m = A[0].size(); if(m == 0) return;
        
        queue<pair<int,int>> q;
        for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j)
            if(A[i][j] == 0) q.push({i,j});
        
        while(!q.empty()) {
            auto x = q.front(); q.pop();
            if(x.first < n-1 && A[x.first + 1][x.second] == INT_MAX) {
                A[x.first + 1][x.second] = A[x.first][x.second] + 1;
                q.push({x.first + 1, x.second});
            }
            if(x.second < m-1 && A[x.first][x.second + 1] == INT_MAX) {
                A[x.first][x.second + 1] = A[x.first][x.second] + 1;
                q.push({x.first, x.second + 1});
            }
            if(x.first > 0 && A[x.first - 1][x.second] == INT_MAX) {
                A[x.first - 1][x.second] = A[x.first][x.second] + 1;
                q.push({x.first - 1, x.second});
            }
            if(x.second > 0 && A[x.first][x.second - 1] == INT_MAX) {
                A[x.first][x.second - 1] = A[x.first][x.second] + 1;
                q.push({x.first, x.second - 1});
            }
        }
    }
    
};
