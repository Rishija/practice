/*
 You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:
 
 Each 0 marks an empty land which you can pass by freely.
 Each 1 marks a building which you cannot pass through.
 Each 2 marks an obstacle which you cannot pass through.
 
 Example:
 
 Input: [[1,0,2,0,1],[0,0,0,0,0],[0,0,1,0,0]]
 
 1 - 0 - 2 - 0 - 1
 |   |   |   |   |
 0 - 0 - 0 - 0 - 0
 |   |   |   |   |
 0 - 0 - 1 - 0 - 0
 
 Output: 7
 
 Explanation: Given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2),
 the point (1,2) is an ideal empty land to build a house, as the total
 travel distance of 3+3+1=7 is minimal. So return 7.
 
 Note:
 There will be at least one building. If it is not possible to build such house according to the above rules, return -1.
 */

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<vector<bool>> vvb;

struct info {
    int i, j, dist;
    info(int i, int j, int dist) : i(i), j(j), dist(dist){}
};

int shortestDistance(vector<vector<int>>& A) {
    int n = A.size();    if(n == 0)   return -1;
    int m = A[0].size(); if(m == 0)   return -1;
    
    // Pair stores {number of ones, sum of distances}
    vector<vector<pii>> D(n, vector<pair<int,int>>(m));
    int numOfOnes = 0;
    
    for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) {
        if(A[i][j] == 1) {
            ++numOfOnes;
            vvb V(n, vector<bool>(m));
            
            queue<info> q; q.push({i,j,0});
            while(!q.empty()) {
                auto p = q.front(); q.pop();
                ++D[p.i][p.j].first;           //Increase number of ones
                D[p.i][p.j].second += p.dist;  // Increase total distance
                
                if(p.i < n-1 && V[p.i + 1][p.j] == false && A[p.i + 1][p.j] == 0) {
                    q.push({p.i + 1, p.j, p.dist + 1});
                    V[p.i + 1][p.j] = true;
                }
                if(p.j < m-1 && V[p.i][p.j + 1] == false && A[p.i][p.j + 1] == 0) {
                    q.push({p.i, p.j + 1, p.dist + 1});
                    V[p.i][p.j + 1] = true;
                }
                if(p.i > 0 && V[p.i - 1][p.j] == false && A[p.i - 1][p.j] == 0) {
                    q.push({p.i - 1, p.j, p.dist + 1});
                    V[p.i - 1][p.j] = true;
                }
                if(p.j > 0 && V[p.i][p.j - 1] == false && A[p.i][p.j - 1] == 0) {
                    q.push({p.i, p.j - 1, p.dist + 1});
                    V[p.i][p.j - 1] = true;
                }
            }
        }
    }
    
    int ans = INT_MAX;
    for(int i = 0; i < n; ++i)  for(int j = 0; j < m; ++j)
        if(A[i][j] == 0 && D[i][j].first == numOfOnes)  ans = min(ans, D[i][j].second);
    return ans == INT_MAX ? -1 : ans;
}
