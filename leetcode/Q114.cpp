TreeNode* p;

void helper(TreeNode* node) {
    
    if(node == nullptr) return;
    
    helper(node->right);
    helper(node->left);
    node->left = nullptr;
    node->right = p;
    p = node;
}

TreeNode* flatten(TreeNode* A) {
    
    if(A == nullptr)    return A;
    if(A->left == nullptr && A->right == nullptr)   return A;
    p = nullptr;
    helper(A);
    return A;
}
