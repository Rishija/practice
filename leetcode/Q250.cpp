/*
Given a binary tree, count the number of uni-value subtrees.

A Uni-value subtree means all nodes of the subtree have the same value.

Example :

Input:  root = [5,1,5,5,5,null,5]

      5
     / \
    1   5
   / \   \
  5   5   5

Output: 4
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

int helper(int &count, TreeNode* node) {
    int l = node->val, r = node->val;
    if(node->left != nullptr)   l = helper(count, node->left);
    if(node->right != nullptr)  r = helper(count, node->right);
    if(l == r && l == node->val)  {
        count++;
        return node->val;
    }
    return INT_MIN;
}

int countUnivalSubtrees(TreeNode* root) {
    if(root == nullptr) return 0;
    int count = 0;
    helper(count, root);
    return count;
}
