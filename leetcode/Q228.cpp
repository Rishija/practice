/*
 Given a sorted integer array without duplicates, return the summary of its ranges.

 Example 1:

 Input:  [0,1,2,4,5,7]
 Output: ["0->2","4->5","7"]
 Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.
 Example 2:

 Input:  [0,2,3,4,6,8,9]
 Output: ["0","2->4","6","8->9"]
 Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.
 */


class Solution {
public:
    vector<string> summaryRanges(vector<int>& A) {
        int n = A.size(); if(n == 0) return {};
        int i = 0, last;
        vector<string> ans;
        while(i < n) {
            last = A[i];
            int j = i + 1;
            while(j < n && A[j] == last + 1) {
                ++last;
                ++j;
            }
            if(j > i + 1)
                ans.push_back(to_string(A[i]) + "->" + to_string(A[j-1]));
            else
                ans.push_back(to_string(A[i]));
            i = j;
        }
        return ans;
    }
};
