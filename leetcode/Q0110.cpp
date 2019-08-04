/*
 Check if given binary tree is height balanced
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
bool helper(TreeNode* node, int &height) {
    
    if(node == nullptr) {
        height = 0;
        return true;
    }
    int lh, rh;
    bool l = helper(node->left, lh), r = helper(node->right, rh);
    height = max(lh,rh) + 1;
    if(abs(lh-rh) < 2 && l && r)
        return true;
    return false;
}

bool isBalanced(TreeNode* root) {
    int h;
    
    return helper(root, h);
}
