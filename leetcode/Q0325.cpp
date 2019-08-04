/*
 Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.
 
 Note:
 The sum of the entire nums array is guaranteed to fit within the 32-bit signed integer range.
 
 Example 1:
 Input: nums = [1, -1, 5, -2, 3], k = 3
 Output: 4
 Explanation: The subarray [1, -1, 5, -2] sums to 3 and is the longest.
 
 Example 2:
 Input: nums = [-2, -1, 2, 1], k = 1
 Output: 2
 Explanation: The subarray [-1, 2] sums to 1 and is the longest.
 
 Follow Up:
 Can you do it in O(n) time?
 */

int maxSubArrayLen(vector<int>& nums, int k) {
    int n = nums.size(), sum = 0, len = 0;
    unordered_map<int, int> map;
    
    // Sum = 0 ends at index -1 (including index -1)
    map[0] = -1;
    
    for(int i = 0; i < n; ++i) {
        sum += nums[i];
        if(map.find(sum - k) != map.end() && len < i - map[sum - k])
            len = i - map[sum - k];
        
        // Includes index i
        if(map.find(sum) == map.end())
            map[sum] = i;
    }
    return len;
}
