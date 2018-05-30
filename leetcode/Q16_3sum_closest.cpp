/*
 Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
 */
/*
 Time: O(n^2)
 Space: O(1)
 */
int threeSumClosest(vector<int>& nums, int target) {
    
    int n = nums.size();
    if(n < 3)
        return 0;
    
    sort(nums.begin(), nums.end());
    
    int current, i = 0, low, high, thisSum;
    long long int ansTillNow = INT_MAX;
    while(i < n) {
        current = nums[i];
        low = i+1; high = n-1;
        while(low < high) {
            thisSum = nums[i] + nums[low] + nums[high];
            if(thisSum == target)
                return target;
            else if(thisSum < target)
                ++low;
            else
                --high;
            if(abs(target - thisSum) < abs(target - ansTillNow))
                ansTillNow = thisSum;
        }
        while(i < n && nums[i] == current)
            ++i;
    }
    return ansTillNow;
}
