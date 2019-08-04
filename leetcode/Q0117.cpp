/*
Given a binary tree

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:
- You may only use constant extra space.
- Recursive approach is fine, implicit stack space does not count as extra space for this problem.
*/

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void helper(TreeLinkNode *root) {
    
    if(root == nullptr)
        return;
    
    TreeLinkNode* current;
    bool found = true;
    
    if(root->left) {
        found = false;
        if(root->right) {
            root->left->next = root->right;
            found = true;
        }
        else {
            current = root->next;
            while(current) {
                if(current->left) {
                    root->left->next = current->left;
                    found = true;
                    break;
                }
                if(current->right) {
                    root->left->next = current->right;
                    found = true;
                    break;
                }
                current = current->next;
            }
        }
    }
    // found => Either root->left doesn't exists or root->left found non null next ptr
    if(root->right && found) {
        current = root->next;
        while(current) {
            if(current->left) {
                root->right->next = current->left;
                break;
            }
            if(current->right) {
                root->right->next = current->right;
                break;
            }
            current = current->next;
        }
    }
    helper(root->right);
    helper(root->left);
}

void connect(TreeLinkNode *root) {
    
    if(root == nullptr)
        return;
    helper(root);
}
