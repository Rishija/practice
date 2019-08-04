/*
 Given a binary tree, determine if it is a valid binary search tree (BST).
 
 Assume a BST is defined as follows:
 
 The left subtree of a node contains only nodes with keys less than the node's key.
 The right subtree of a node contains only nodes with keys greater than the node's key.
 Both the left and right subtrees must also be binary search trees.
 */

bool helper(TreeNode* node, long long int &last) {
    if(node == nullptr)
        return true;
    if(helper(node->left, last) == false)
        return false;
    if(last >= node->val)
        return false;
    last = node->val;
    return helper(node->right, last);
}
bool isValidBST(TreeNode* root) {
    if(root == nullptr)
        return true;
    long long int last = LONG_MIN;
    return helper(root, last);
}
