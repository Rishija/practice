/*
 Given a binary tree, return the tilt of the whole tree.
 
 The tilt of a tree node is defined as the absolute difference between the sum of all left subtree node values and the sum of all right subtree node values. Null node has tilt 0.
 
 The tilt of the whole tree is defined as the sum of all nodes' tilt.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int helper(TreeNode *node, int &sum) {
    if(node == nullptr)
        return 0;
    int left = helper(node->left, sum), right = helper(node->right, sum);
    sum += abs(left - right);
    return left + right + node -> val;
}

int findTilt(TreeNode* root) {
    int sum = 0;
    helper(root, sum);
    return sum;
}
