/*
Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.



Example 1:

Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Example 2:

Input: [-7,-3,2,3,11]
Output: [4,9,9,49,121]

Note:

1 <= A.length <= 10000
-10000 <= A[i] <= 10000
A is sorted in non-decreasing order.
*/

public int[] sortedSquares(int[] A) {
    int n = A.length, i = 0, j = n - 1, ans[] = new int[n];
    for(int index = n - 1; index >= 0; --index)
        ans[index] = (Math.abs(A[i]) >= Math.abs(A[j])) ?
        (int)Math.pow(A[i++], 2) : (int)Math.pow(A[j--], 2);
    return ans;
}
