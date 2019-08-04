/*
 Given preorder and inorder traversal of a tree, construct the binary tree.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void helper(TreeNode* &node, const vector<int> &inorder, const vector<int> &preorder, int low, int high, int &p) {
    
    if(low > high)
        return;
    
    node = new TreeNode(preorder[p]);
    int i;
    for(i = low; i <= high; ++i)
        if(inorder[i] == preorder[p])
            break;
    ++p;
    helper(node->left, inorder, preorder, low, i-1, p);
    helper(node->right, inorder, preorder, i+1, high, p);
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int pre = preorder.size();
    if(pre == 0)    return nullptr;
    TreeNode* root;
    int p = 0;
    helper(root, inorder, preorder, 0, pre - 1, p);
    return root;
}
