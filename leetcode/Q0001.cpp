/*
 Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 
 You may assume that each input would have exactly one solution, and you may not use the same element twice.
 
 Example:
 
 Given nums = [2, 7, 11, 15], target = 9,
 
 Because nums[0] + nums[1] = 2 + 7 = 9,
 return [0, 1].
 */

vector<int> twoSum(vector<int>& nums, int target) {
    
    vector<pair<int,int>> arr;
    for(int i = 0; i < nums.size(); ++i)
        arr.push_back({nums[i],i});
    
    sort(arr.begin(), arr.end(), [] (const pair<int,int> a, const pair<int,int> b){
        return a.first < b.first;
    });
    
    int low = 0, high = nums.size() - 1, temp;
    
    while(low < high) {
        temp = arr[low].first + arr[high].first;
        if(temp == target) {
            
            return {arr[low].second, arr[high].second};
        }
        else if(temp < target)
            ++ low;
        else
            -- high;
    }
    return {};
}
