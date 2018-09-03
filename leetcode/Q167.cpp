/*
 Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

 The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

 Note:

 Your returned answers (both index1 and index2) are not zero-based.
 You may assume that each input would have exactly one solution and you may not use the same element twice.
 Example:

 Input: numbers = [2,7,11,15], target = 9
 Output: [1,2]
 Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
 */


class Solution {
public:
    vector<int> helper1(vector<int> &A, int target) {
        int n = A.size();
        if(n < 2) return {};

        unordered_map<int, int> map;
        for(int i = 0; i < n; ++i) {
            if(map.find(target - A[i]) != map.end())
                return {map[target - A[i]] + 1, i + 1};
            map[A[i]] = i;
        }
        return {};
    }

    vector<int> helper2(vector<int> &A, int target) {
        int n = A.size();
        if(n < 2) return {};

        int low = 0, high = n-1;
        while(low < high) {
            int sum = A[low] + A[high];
            if(sum == target) return {low + 1, high + 1};
            sum < target ? ++low : --high;
        }
        return {};
    }

    vector<int> twoSum(vector<int>& A, int target) {
        return helper1(A, target);
//        return helper2(A, target);
    }
};
