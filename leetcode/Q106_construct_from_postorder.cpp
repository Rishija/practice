/*
 Given postorder and inorder traversal of a tree, construct the binary tree.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void helper(TreeNode* &node, const vector<int> &inorder, const vector<int> &postorder, int low, int high, int &post, unordered_map<int, int> map) {
    if(low > high)
        return;
    node = new TreeNode(postorder[post]);
    int i = map[postorder[post]];
    --post;
    helper(node->right, inorder, postorder, i+1, high, post, map);
    helper(node->left, inorder, postorder, low, i-1, post, map);
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int post = postorder.size();
    if(post == 0)
        return nullptr;
    unordered_map<int, int> map;
    for(int i = 0; i < post; ++i)
        map[inorder[i]] = i;
    TreeNode* root;
    --post;
    helper(root, inorder, postorder, 0, post, post, map);
    return root;
}
