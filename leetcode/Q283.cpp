/*
 Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

 Example:

 Input: [0,1,0,3,12]
 Output: [1,3,12,0,0]
 Note:

 You must do this in-place without making a copy of the array.
 Minimize the total number of operations.
 */

class Solution {
public:
    void moveZeroes(vector<int>& A) {
        int n = A.size(), start = 0;
        for(int i = 0; i < n; ++i)  if(A[i] != 0) swap(A[start++],A[i]);
    }
    // void moveZeroes(vector<int>& A) {
    //     int n = A.size(), start = 0;
    //     for(int i = 0; i < n; ++i)  if(A[i] != 0) A[start++] = A[i];
    //     for(int i = start; i < n; ++i)  A[i] = 0;
    // }
};
