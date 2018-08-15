/*
 Given a binary tree where all the right nodes are either leaf nodes with a sibling (a left node that shares the same parent node) or empty, flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes. Return the new root.
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
TreeNode* upsideDownBinaryTree(TreeNode* root) {
    if(root == nullptr || root->left == nullptr) return root;
    
    // Process left subtree
    TreeNode* newRoot = upsideDownBinaryTree(root->left);
    
    // Rotate clockwise
    root->left->left = root->right;
    root->left->right = root;
    root->left = nullptr;
    root->right = nullptr;
    
    // Return leftmost root in the original tree
    return newRoot;
}
