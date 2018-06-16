/*
 Given an unsorted integer array, find the smallest missing positive integer.
 */
int firstMissingPositive(vector<int>& nums) {
    int n = nums.size(), i = 0, temp;
    while(i < n) {
        if(nums[i] > 0 && nums[i] <= n && nums[i] != i + 1 && nums[nums[i] - 1] != nums[i]) {
            temp = nums[nums[i] - 1];
            nums[nums[i] - 1] = nums[i];
            nums[i] = temp;
            //            swap(nums[nums[i] - 1], nums[i]);
        }
        else
            ++i;
    }
    for(int i = 0; i < n; ++i)
        if(nums[i] != i + 1)
            return i + 1;
    return n + 1;
}
