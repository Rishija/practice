/*
 Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

 For example, given the following triangle

 [
 [2],
 [3,4],
 [6,5,7],
 [4,1,8,3]
 ]
 The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

 Note:

 Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
 */

class Solution {
public:
    int minimumTotal(vector<vector<int>>& A) {
        int n = A.size();
        if(n == 0)  return 0;
        if(n == 1)  return *(min_element(A[0].begin(), A[0].end()));

        for(int i = n-2; i >= 0; --i) {
            for(int j = 0; j <= i; ++j)
                A[i][j] += min(A[i+1][j], A[i+1][j+1]);

        }
        return A[0][0];
    }
};
