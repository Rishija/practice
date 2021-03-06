/*
Given a binary tree.
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:
- You may only use constant extra space.
- Recursive approach is fine, implicit stack space does not count as extra space for this problem.
- You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
*/

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void helper(TreeLinkNode *root) {
    if(root->left) {
        root->left->next = root->right;
        if(root->next)
            root->right->next = root->next->left;
        helper(root->left);
        helper(root->right);
    }
}

void connect(TreeLinkNode *root) {
    
    if(root == nullptr)
        return;
    helper(root);   // Separate function to avoid additional nullptr check
}
