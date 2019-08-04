/*
 Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.
 
 Example:
 Input: nums = [-2,0,1,3], and target = 2
 Output: 2
 
 Explanation: Because there are two triplets which sums are less than 2:
 [-2,0,1]
 [-2,0,3]
 
 Follow up: Could you solve it in O(n^2) runtime?
 */

int threeSumSmaller(vector<int>& A, int target) {
    int n = A.size();
    if(n < 3)   return 0;
    
    sort(A.begin(), A.end());
    int count = 0;
    for(int i = 0; i < n - 2; ++i) {
        int j = i+1, k = n-1;
        while(j < k) {
            if(A[i] + A[j] + A[k] >= target)    --k;
            else {
                count += k - j;
                ++j;
            }
        }
    }
    return count;
}
