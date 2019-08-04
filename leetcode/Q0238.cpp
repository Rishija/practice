/*
 Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

 Example:

 Input:  [1,2,3,4]
 Output: [24,12,8,6]
 Note: Please solve it without division and in O(n).

 Follow up:
 Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
*/

class Solution {
public:
    vector<int> helper1(vector<int> &nums) {
        int n = nums.size();
        vector<int> left(n), right(n); left[0] = 1; right[n-1] = 1;
        for(int i = 1; i < n; ++i)  left[i] = left[i-1] * nums[i-1];
        for(int i = n-2; i >= 0; --i) right[i] = right[i+1] * nums[i+1];

        for(int i = 0; i < n; ++i) left[i] = left[i] * right[i];
        return left;
    }
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(); if(n == 0) return {};
        if(n == 1)  return {1};

        vector<int> left(n); left[0] = 1;
        for(int i = 1; i < n; ++i)  left[i] = left[i-1] * nums[i-1];

        int right = 1;
        for(int i = n - 1; i >= 0; --i) {
            left[i] = left[i] * right;
            right *= nums[i];
        }
        return left;
        //return helper1(nums);

    }
};
