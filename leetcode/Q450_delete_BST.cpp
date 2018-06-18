/*
 Delete node from BST
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* successor(TreeNode* node) {
    if(node->left == nullptr)
        return node;
    return successor(node->left);
}

// Reference to node
void helper(TreeNode* &node, int key) {
    
    if(node == nullptr)         return;                  // Key absent
    if(node->val < key)         helper(node->right, key);
    else if(node->val > key)    helper(node->left, key);
    else {
        TreeNode* temp = nullptr;
        if(node->left == nullptr) {
            if(node->right != nullptr)                   // Only right child present
                temp = node->right;
        }
        else if(node->right == nullptr)                  // Only left child present
            temp = node->left;
        else {                                           // Both present
            node->val = successor(node->right)->val;     // Copy successor's value
            helper(node->right, node->val);              // Delete successor
            return;
        }
        delete node;                                     // Free memory node is pointing to
        node = temp;
    }
}

TreeNode* deleteNode(TreeNode* root, int key) {
    helper(root, key);
    return root;
}

