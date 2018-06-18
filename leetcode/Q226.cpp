/*
 Invert a binary tree (Mirror image)
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void helper(TreeNode* node) {
    if(node == nullptr)
        return;
    helper(node->right);
    helper(node->left);
    TreeNode* temp = node->left;
    node->left = node->right;
    node->right = temp;
}

TreeNode* invertTree(TreeNode* root) {
    helper(root);
    return root;
}
