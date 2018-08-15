/*
 There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.
 
 The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.
 
 Note:
 All costs are positive integers.
 
 Example:
 Input: [[1,5,3],[2,9,4]]
 Output: 5
 
 Explanation: Paint house 0 into color 0, paint house 1 into color 2. Minimum cost: 1 + 4 = 5;
 Or paint house 0 into color 2, paint house 1 into color 0. Minimum cost: 3 + 2 = 5.
 
 Follow up:
 Could you solve it in O(nk) runtime?
 */

int minCostII(vector<vector<int>>& A) {
    int n = A.size();   if(n == 0)  return 0;
    int k = A[0].size();
    if(k == 0)  return 0;
    if(k == 1 && n > 1)  return INT_MAX;
    
    for(int row = 1; row < n; ++row) {
        // Find min and second min index
        int minIndex, secondMinIndex;
        if(A[row-1][0] < A[row-1][1]) { minIndex = 0;   secondMinIndex = 1; }
        else                          { minIndex = 1;   secondMinIndex = 0; }
        for(int i = 2; i < k; ++i) {
            if(A[row-1][i] < A[row-1][minIndex]) {
                secondMinIndex = minIndex;
                minIndex = i;
            }
            else if(A[row-1][i] < A[row-1][secondMinIndex])
                secondMinIndex = i;
        }
        
        // when current == minIndex, set its value to secondMinIndex else to the minIndex
        for(int i = 0; i < k; ++i) {
            if(i == minIndex) A[row][i] += A[row-1][secondMinIndex];
            else              A[row][i] += A[row-1][minIndex];
        }
    }
    return *min_element(A[n-1].begin(), A[n-1].end());
}
