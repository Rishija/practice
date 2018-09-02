/*
 Given an array, rotate the array to the right by k steps, where k is non-negative.

 Example 1:

 Input: [1,2,3,4,5,6,7] and k = 3
 Output: [5,6,7,1,2,3,4]
 Explanation:
 rotate 1 steps to the right: [7,1,2,3,4,5,6]
 rotate 2 steps to the right: [6,7,1,2,3,4,5]
 rotate 3 steps to the right: [5,6,7,1,2,3,4]
 Example 2:

 Input: [-1,-100,3,99] and k = 2
 Output: [3,99,-1,-100]
 Explanation:
 rotate 1 steps to the right: [99,-1,-100,3]
 rotate 2 steps to the right: [3,99,-1,-100]
 Note:

 Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
 Could you do it in-place with O(1) extra space?
 */

class Solution {
public:
    void method1(vector<int> &A, int k) {
        int n = A.size();
        k = k % n;
        if(k == 0)  return;
        reverse(A.begin(), A.begin() + n - k);
        reverse(A.begin() + n - k, A.end());
        reverse(A.begin(), A.end());
    }

    void method2(vector<int> &A, int k) {
        int n = A.size(), i = 0;
        k = k % n;
        vector<int> neww(n);
        for(int i = 0; i < n; ++i)
            neww[i] = A[(i - k + n) % n];
        A = neww;
    }
    void rotate(vector<int>& nums, int k) {
        // method1(nums, k);
        method2(nums, k);
    }
};
