/*

 Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

 (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

 You are given a target value to search. If found in the array return true, otherwise return false.

 Example 1:

 Input: nums = [2,5,6,0,0,1,2], target = 0
 Output: true
 Example 2:

 Input: nums = [2,5,6,0,0,1,2], target = 3
 Output: false
 Follow up:

 This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
 Would this affect the run-time complexity? How and why?
 */

class Solution {
public:
    bool helper(vector<int> &A, int target, int low, int high) {
        if(low > high)  return false;
        int mid = (low + high) / 2;
        if(A[mid] == target) return true;

        if(A[mid] == A[low] && A[mid] == A[high]) {
            if(helper(A, target, low + 1, mid - 1) == false)
                return helper(A, target, mid + 1, high - 1);
            return true;
        }

        if(A[low] <= A[mid]) {
            if(A[low] <= target && target < A[mid])
                return helper(A, target, low, mid - 1);
            return helper(A, target, mid + 1, high);
        }
        if(A[mid] <= A[high]) {
            if(A[mid] < target && target <= A[high])
                return helper(A, target, mid + 1, high);
            return helper(A, target, low, mid - 1);
        }
        return false;
    }
    bool search(vector<int>& A, int target) {
        if(A.size() == 0)   return false;
        return helper(A, target, 0, A.size() - 1);
    }
};

// 5 5 6 1 2 3


