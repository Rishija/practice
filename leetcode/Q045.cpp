/*
 Given an array of non-negative integers, you are initially positioned at the first index of the array.
 
 Each element in the array represents your maximum jump length at that position.
 
 Your goal is to reach the last index in the minimum number of jumps.
 
 Example:
 
 Input: [2,3,1,1,4]
 Output: 2
 Explanation: The minimum number of jumps to reach the last index is 2.
 Jump 1 step from index 0 to 1, then 3 steps to the last index.
 Note:
 
 You can assume that you can always reach the last index.
 */

int jump(vector<int>& A) {
    int n = A.size();
    if(n < 2)  return 0;
    int i = 0, maxReach = -1, count = 1, nextReach = A[0];
    while(i < n) {
        maxReach = max(maxReach, A[i] + i);
        if(nextReach == i) {
            ++count;
            nextReach = maxReach;
        }
        ++i;
        if(nextReach >= n-1)    return count;
    }
    return count;
}
