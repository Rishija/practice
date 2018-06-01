/*
 Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
 
 Your algorithm's runtime complexity must be in the order of O(log n).
 
 If the target is not found in the array, return [-1, -1]
 */
#include <iostream>
#include <vector>
using namespace std;

int bsearch(int elem, vector<int> arr, int start, int end) {
    
    int low = start, high = end, mid;
    while(low <= high) {
        
        mid = low + (high - low) / 2;
        
        if(arr[mid] == elem)
            return mid;
        if(arr[mid] < elem)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int helperLeft(vector<int> &nums, int start, int end, int target) {
    
    int occurence = bsearch(target, nums, start, end);
    if(occurence == -1)
        return end + 1;
    return helperLeft(nums, start, occurence - 1, target);
}

int helperRight(vector<int> &nums, int start, int end, int target) {
    
    int occurence = bsearch(target, nums, start, end);
    if(occurence == -1)
        return start - 1;
    return helperRight(nums, occurence + 1, end, target);
}

vector<int> searchRange(vector<int>& nums, int target) {
    
    int n = nums.size(), occurence = bsearch(target, nums, 0, n-1);
    if(occurence == -1)
        return {-1, -1};
    
    int left = helperLeft(nums, 0, occurence - 1, target), right = helperRight(nums, occurence + 1, n - 1, target);
    vector<int> ans(2);
    ans[0] = left >= 0 ? left : occurence;
    ans[1] = right >= 0 ? right : occurence;
    return ans;
}

void print(vector<int> vec, int target) {
    vector<int>ans = searchRange(vec, target);
    cout << ans[0] << ", " << ans[1] << endl;
}

int main() {
    
    vector<int> nums;
    
    nums = {2,2};
    print(nums, 2);
    
    nums = {5,7,7,8,8,10};
    print(nums, 8);
    
    nums = {5,7,7,8,8,10};
    print(nums, 2);
    return 0;
}
