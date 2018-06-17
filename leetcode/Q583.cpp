/*
 Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.
 */

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

// [0,-1,2,-3,null,null,4]  ->  [6,5,6,2,null,null,4]
// [1,0,4,-2,null,3]        ->  [8,8,4,6,null,7]
