/*
 Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

 Example 1:

 Input: [3,0,1]
 Output: 2
 Example 2:

 Input: [9,6,4,2,3,5,7,0,1]
 Output: 8
 Note:
 Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
 */

class Solution {
public:
    int f1(vector<int> &A) {
        int n = A.size(), arraySum = 0, sum = n * (n+1) / 2;
        for(int i = 0; i < n; ++i) arraySum += A[i];
        return sum - arraySum;
    }

    int f2(vector<int> &A) {
        int n = A.size(), xorr = 0;
        for(int i = 0; i < n; ++i) xorr ^= (i+1) ^ A[i];
        return xorr;
    }
    int missingNumber(vector<int>& nums) {
        // return f1(nums);
        return f2(nums);
        // return f3(nums);
    }
};
