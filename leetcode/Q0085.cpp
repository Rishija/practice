/*
 Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 Example:

 Input:
 [
 ["1","0","1","0","0"],
 ["1","0","1","1","1"],
 ["1","1","1","1","1"],
 ["1","0","0","1","0"]
 ]
 Output: 6
 */

class Solution {
public:
    int largest_histogram2(vector<int> &graph) {

        int n = graph.size();
        if(n == 0)  return 0;
        if(n == 1)  return graph[0];

        stack<int> bounds;
        int maxx = 0;

        bounds.push(-1);
        for(int i = 0; i < n; i++) {
            int current = bounds.top();
            while((current != - 1) && (graph[current] >= graph[i])) {
                bounds.pop();
                maxx = max(maxx, graph[current] * (i - bounds.top() - 1));
                current = bounds.top();
            }
            bounds.push(i);
        }

        int current = bounds.top(), right = bounds.top();
        while(current != - 1) {
            bounds.pop();
            maxx = max(maxx, graph[current] * (right - bounds.top()));
            current = bounds.top();
        }
        return maxx;
    }

    int maximalRectangle(vector<vector<char>>& A) {
        int n = A.size();    if(n == 0)  return 0;
        int m = A[0].size(); if(m == 0)  return 0;

        vector<vector<int>> below(n, vector<int>(m));

        for(int j = 0; j < m; ++j)  below[n-1][j] = A[n-1][j] - 48;
        for(int j = 0; j < m; ++j)  for(int i = n-2; i >= 0; --i)
            below[i][j] = (A[i][j] == '1') ? below[i+1][j] + 1 : 0;

        int maxx = 0;
        for(int i = 0; i < n; ++i)  maxx = max(maxx, largest_histogram2(below[i]));
        return maxx;
    }
};
