/*
 Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
 
 For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void helper(int low, int high, const vector<int> &nums, TreeNode* &node) {
    if(low > high)
        return;
    int mid = (low + high)/2;
    node = new TreeNode(nums[mid]);
    helper(low, mid - 1, nums, node->left);
    helper(mid+1, high, nums, node->right);
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    
    int n = nums.size();
    if(n == 0)
        return nullptr;
    TreeNode* root;
    helper(0, n-1, nums, root);
    return root;
}
