/*
 Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), where largest means subtree with largest number of nodes in it.
 
 Note:
 A subtree must include all of its descendants.
 
 Example:
 
 Input: [10,5,15,1,8,null,7]
 
    10
   / \
  5  15
 / \   \
 1   8   7
 
 Output: 3
 Explanation: The Largest BST Subtree in this case is the highlighted one.
 The return value is the subtree's size, which is 3.
 
 Follow up:
 Can you figure out ways to solve it with O(n) time complexity?
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int helper(TreeNode* node, int &minn, int &maxx, int &ans, bool isLeft = false) {
    
    int leftMin = node->val, leftMax = node->val - 1, rightMin = node->val + 1, rightMax = node->val, left = 0, right = 0;
    if(node->left != nullptr)   left = helper(node->left, leftMin, leftMax, ans, true);
    if(node->right != nullptr)  right = helper(node->right, rightMin, rightMax, ans);
    
    if(node->val > leftMax && node->val <= rightMin) {
        int cntHere = left + right + 1;
        ans = max(ans, cntHere);
        minn = leftMin;
        maxx = rightMax;
        return cntHere;
    }
    /*
     Set only maxx if current node is left child of its parent
     ans only minn if current node is right child of its parent
     */
    isLeft ? maxx = INT_MAX : minn = INT_MIN;
    return 0;
}

int largestBSTSubtree(TreeNode* root) {
    if(root == nullptr) return 0;
    int ans = 0, min, max;
    helper(root, min, max, ans);
    return ans;
}
