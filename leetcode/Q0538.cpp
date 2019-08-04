/*
 Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

 Example:

 Input: The root of a Binary Search Tree like this:
   5
 /   \
 2     13

 Output: The root of a Greater Tree like this:
     18
   /   \
 20     13
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

    // In a sorted list, keep adding sum of right hand side nodes
    void helper(TreeNode* node, int &sum) {
        if(node == nullptr)
            return;
        helper(node->right, sum);
        node->val += sum;
        sum = node->val;
        helper(node->left,sum);
    }

    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        helper(root, sum);
        return root;
    }

};
// [0,-1,2,-3,null,null,4]  ->  [6,5,6,2,null,null,4]
// [1,0,4,-2,null,3]        ->  [8,8,4,6,null,7]
