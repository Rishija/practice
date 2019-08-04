/*
Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Note:

Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.
Example:

Input: root = [4,2,5,1,3], target = 3.714286

   4
  / \
 2   5
/ \
1   3

Output: 4
*/

void inorder(TreeNode* node, bool &done, const double target, double &ans) {
    if(node == nullptr || done) return;
    inorder(node->left, done, target, ans);
    double thisGap = abs(node->val - target);
    if(thisGap < abs(ans - target)) {
        ans = node->val;
        inorder(node->right, done, target, ans);
    }
    else done = true;
}

int closestValue(TreeNode* root, double target) {
    bool done = false;
    double ans = std::numeric_limits<double>::max();
    inorder(root, done, target, ans);
    return ans;
}
