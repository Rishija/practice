/*
 Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.
 
 Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 */
/*
 Time : O(n)
 Space : O(1)
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size(), index = 0, i = 0, count = 1;
        if(n < 2)  return n;
        
        while(i < n - 1) {
            count = 1;
            while(i < n-1 && nums[i] == nums[i + 1]) {
                ++count;
                if(count < 3)
                    nums[++index] = nums[i+1];
                ++i;
            }
            if(i < n - 1) {
                nums[++index] = nums[i+1];
            }
            ++i;
        }
        return index + 1;
    }
};
