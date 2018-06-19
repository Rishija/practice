/*
 Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.
 */

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    int n = nums.size();
    if(n < 2 || k == 0)
        return false;
    unordered_map<int, int> map;
    for(int i = 0; i < n; ++i) {
        if(map[nums[i]] > 0 && i - map[nums[i]] + 1 <= k)
            return true;
        else
            map[nums[i]] = i + 1;
    }
    return false;
}
