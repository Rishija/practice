/*
 Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....
 
 Example:
 
     Input: nums = [3,5,2,1,6,4]
     Output: One possible answer is [3,5,1,6,2,4]
 */

void wiggleSort(vector<int>& A) {
    int n = A.size();
    if(n < 2)   return;
    
    for(int i = 1; i < n; i += 2) {
        if(A[i-1] > A[i])   swap(A[i-1], A[i]);
        if(i < (n - 1) && A[i+1] > A[i])   swap(A[i+1], A[i]);
    }
}
