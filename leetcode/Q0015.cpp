/*
 Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 
 Note:
 
 The solution set must not contain duplicate triplets.
 
 Example:
 
 Given array nums = [-1, 0, 1, 2, -1, -4],
 
 A solution set is:
 [
 [-1, 0, 1],
 [-1, -1, 2]
 ]
 */

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    if(n < 3)   return {};
    
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    int i = 0;
    
    while(i < n - 2) {
        
        int target = -nums[i], low = i + 1, high = n - 1;
        while(low < high) {
            int sum = nums[low] + nums[high];
            if(sum == target) {
                ans.push_back({nums[i], nums[low], nums[high]});
                while(low < high && nums[low] == nums[low + 1]) ++low;
                ++low;
                while(low < high && nums[high] == nums[high - 1]) --high;
                --high;
            }
            else    sum < target ? ++low : --high;
        }
        while(i < n - 3 && nums[i] == nums[i + 1]) ++i;
        ++i;
    }
    return ans;
}
