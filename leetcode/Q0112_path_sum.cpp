/*
 Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
 
 Note: A leaf is a node with no children.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool helper(TreeNode* node, int currentSum, const int sum) {
    
    currentSum += node->val;
    if(currentSum > sum)
        return false;
    if(node->left == nullptr) {
        if(node->right == nullptr)
            return currentSum == sum ? true : false;
        return helper(node->right, currentSum, sum);
    }
    if(node->right == nullptr)
        return helper(node->left, currentSum, sum);
    
    return helper(node->left, currentSum, sum) || helper(node->right, currentSum, sum);
}

bool hasPathSum(TreeNode* root, int sum) {
    if(root == nullptr)
        return false;
    return helper(root, 0, sum);
}
