/*
Given a binary tree, find the length of the longest consecutive sequence path.

The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).

Example 1:

Input:

1
 \
  3
 / \
 2   4
      \
       5

Output: 3

Explanation: Longest consecutive sequence path is 3-4-5, so return 3.
Example 2:

Input:

 2
  \
  3
  /
 2
/
1

Output: 2

Explanation: Longest consecutive sequence path is 2-3, not 3-2-1, so return 2.
*/

int helper(TreeNode* node, int &maxx) {
    if(node == nullptr) return 0;
    int left = node->left != nullptr ? helper(node->left, maxx) : 0,
    right = node->right != nullptr ? helper(node->right, maxx) : 0;
    
    int ans = 1;
    if(left > 0 && node->left->val == node->val + 1)   ans = left + 1;
    if(right > 0 && node->right->val == node->val + 1)   ans = max(ans, right + 1);
    
    maxx = max(maxx, ans);
    return ans;
}

int longestConsecutive(TreeNode* root) {
    int maxx = 0;
    helper(root, maxx);
    return maxx;
}
