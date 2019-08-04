/*
 Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
 */
/*
 Time: O(n^3)
 Space: O(n^4) - To store the 4tuples
 */
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    
    int n = nums.size();
    if(n < 4)  return {};
    
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    int n3, n4, sum;
    
    for(int n1 = 0; n1 < n; ++n1) {
        for(int n2 = n1 + 1; n2 < n; ++n2) {
            n3 = n2 + 1; n4 = n - 1;
            while(n3 < n4) {
                sum = nums[n1] + nums[n2] + nums[n3] + nums[n4];
                if(sum < target)  ++n3;
                else if(sum > target)  --n4;
                else {
                    ans.push_back({nums[n1], nums[n2], nums[n3], nums[n4]});
                    while(n3 < n4 && nums[n3] == nums[n3+1])  ++n3;
                    while(n3 < n4 && nums[n4] == nums[n4-1])  --n4;
                    ++n3; --n4;
                }
            }
            while(n2 < n - 1 && nums[n2 + 1] == nums[n2])  ++n2;
        }
        while(n1 < n - 1 && nums[n1 + 1] == nums[n1])  ++n1;
    }
    return ans;
}
