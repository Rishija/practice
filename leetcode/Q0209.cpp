/*
 Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

 Example:

 Input: s = 7, nums = [2,3,1,2,4,3]
 Output: 2
 Explanation: the subarray [4,3] has the minimal length under the problem constraint.
 Follow up:
 If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
 */


class Solution {
public:
    int helper1(int s, vector<int> &A) {

        int n = A.size(); if(n == 0) return 0;
        int minLen = INT_MAX, i = 0, j = 0, sum = 0;
        while(true) {
            if(sum >= s) {
                while(i < j && sum - A[i] >= s)
                    sum -= A[i++];
                minLen = min(minLen, j - i);
            }
            if(j == n) break;
            sum += A[j++];
        }
        return minLen == INT_MAX ? 0 : minLen;
    }

    // Idiocity
    int helper2(int s, vector<int> &A) {
        int n = A.size(); if(n == 0) return 0;
        sort(A.begin(), A.end());
        int i = n - 1, sum = 0;
        while(i >= 0) {
            sum += A[i--];
            if(sum >= s) return n - i - 1;
        }
        return 0;
    }
    int minSubArrayLen(int s, vector<int>& A) {
        return helper1(s, A);
        // return helper2(s, A);
    }
};
