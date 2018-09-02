/*
 Given a non-empty binary tree, find the maximum path sum.

 For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

 Example 1:

 Input: [1,2,3]

 1
 / \
 2   3

 Output: 6
 Example 2:

 Input: [-10,9,20,null,null,15,7]

 -10
 / \
 9  20
 /  \
 15   7

 Output: 42
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
class Solution {
public:
    typedef long long int lli;

    lli helper(TreeNode* node, lli &maxx) {

        if(node == nullptr) return 0;

        lli leftSum = helper(node->left, maxx),
        rightSum = helper(node->right, maxx),
        belowThisNode = node->val;
        if(max(leftSum, rightSum) + node->val > node->val)
            belowThisNode = max(leftSum, rightSum) + node->val;

        lli rootedHere = leftSum + rightSum + node->val,
        maxFromBoth = max(rootedHere, belowThisNode);
        if(maxFromBoth > maxx)
            maxx = maxFromBoth;
        return belowThisNode;
    }

    int maxPathSum(TreeNode* A) {

        if(A == nullptr)    return 0;
        lli max = INT_MIN;
        helper(A, max);
        return max;
    }
};
