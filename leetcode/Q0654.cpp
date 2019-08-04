/*
 Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:
 
 The root is the maximum number in the array.
 The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
 The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
 Construct the maximum tree by the given array and output the root node of this tree.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* helper(vector<int> &nums, int low, int high) {
    
    if(low == high)
        return new TreeNode(nums[low]);
    int max = low, i = low + 1;
    while(i <= high) {
        if(nums[i] > nums[max])
            max = i;
        ++i;
    }
    TreeNode* node = new TreeNode(nums[max]);
    if(max > low)
        node -> left = helper(nums, low, max - 1);
    if(max < high)
        node -> right = helper(nums, max + 1, high);
    return node;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    
    int n = nums.size();
    if(n == 0)  return nullptr;
    return helper(nums, 0, n - 1);
}
