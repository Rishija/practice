/*
Given a complete binary tree, count the number of nodes.

Note:

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Example:

Input:
1
/ \
2   3
/ \  /
4  5 6

Output: 6
*/

int countNodes(TreeNode* root) {
    
    if(root == nullptr)
        return 0;
    int h1 = 0, h2 = 0;
    TreeNode *l = root->left, *r = root->right;
    
    while(l != nullptr) {
        ++h1;
        l = l->left;
    }
    while(r != nullptr) {
        ++h2;
        r = r->left;
    }
    
    // Same number of nodes till left end of right subtree
    if(h1 == h2)
        return (1 << h1) + countNodes(root->right);
    
    return countNodes(root->left) + (1 << h2);
}
