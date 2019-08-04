/*
 Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.
 
 The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int widthOfBinaryTree(TreeNode* root) {
    
    if(root == nullptr)
        return 0;
    
    pair<TreeNode*,int> c;
    vector<pair<TreeNode*, int>> q1;
    q1.push_back({root, 0});
    int max = 1, diff, i, n;
    
    while(!q1.empty()) {
        
        vector<pair<TreeNode*, int>> q2;
        diff = abs(q1[0].second - q1[q1.size() - 1].second) + 1;
        if(diff > max)
            max = diff;
        i = 0;
        n = q1.size();
        while(i < n) {
            c = q1[i];
            if(c.first->left != nullptr)
                q2.push_back({c.first->left, 2*c.second});
            if(c.first->right != nullptr)
                q2.push_back({c.first->right, 2*c.second + 1});
            ++i;
        }
        q1 = q2;
    }
    return max;
}

