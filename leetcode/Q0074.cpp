/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
 
Example 1:
Input:
matrix = [
          [1,   3,  5,  7],
          [10, 11, 16, 20],
          [23, 30, 34, 50]
          ]
target = 3
Output: true
 
Example 2:
Input:
matrix = [
          [1,   3,  5,  7],
          [10, 11, 16, 20],
          [23, 30, 34, 50]
          ]
target = 13
Output: false
*/

bool helper1(vector<vector<int>> &A, int target) {
    int n = A.size();    if(n == 0) return false;
    int m = A[0].size(); if(m == 0) return false;
    
    // Find row
    int low = 0, high = n - 1;
    while(low < high) {
        int mid = (low + high) / 2;
        if(A[mid][m-1] == target) return true;
        A[mid][m-1] < target ? low = mid + 1: high = mid;
    }
    // Target out of range
    if(target < A[low][0] || target > A[high][m-1]) return false;
    
    // Find column
    int l = 0, h = m-1;
    while(l <= h) {
        int mid = (l + h) / 2;
        if(A[low][mid] == target) return true;
        A[low][mid] < target ? l = mid + 1 : h = mid - 1;
    }
    return false;
}

bool helper2(vector<vector<int>> &A, int target) {
    int n = A.size();    if(n == 0) return false;
    int m = A[0].size(); if(m == 0) return false;
    
    // Flatten 2D matrix to 1D array
    int low = 0, high = n * m - 1;
    while(low <= high) {
        int mid = (low + high) / 2, i = mid / m, j = mid % m;
        if(A[i][j] == target) return true;
        A[i][j] < target ? low = mid + 1 : high = mid - 1;
    }
    return false;
}

bool searchMatrix(vector<vector<int>>& A, int target) {
    // return helper1(A, target);
    return helper2(A, target);
}
